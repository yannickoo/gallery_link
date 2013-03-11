<?php

/**
 * @file
 * Drush integration for the Gallery Link module.
 */

/**
 * The URL to fancyBox plugin.
 */
define('FANCYBOX_DOWNLOAD_URL', 'https://nodeload.github.com/fancyapps/fancyBox/zip/v2.1.4');

/**
 * Implements hook_drush_command().
 */
function gallery_link_drush_command() {
  $items = array();

  $items['fancybox-download'] = array(
    'description' => dt('Downloads the fancyBox plugin from GitHub.'),
    'arguments' => array(
      'path' => dt('Optional. A path to the libraries directory. If ommitted the default location will be used (sites/all/libraries).'),
    ),
  );

  return $items;
}

/**
 * Implements drush_MODULE_post_COMMAND().
 */
function drush_gallery_link_post_pm_enable() {
  $modules = func_get_args();

  // If our module was enabled we run the download command.
  if (in_array('gallery_link', $modules)) {
    drush_fancybox_download();
  }
}

/**
 * Command callback for 'fancybox-download'.
 */
function drush_gallery_link_fancybox_download() {
  if (!drush_shell_exec('type unzip')) {
    return drush_set_error(dt('Missing dependency: unzip. Install it before using this command.'));
  }

  $args = func_get_args();
  if (isset($args[0])) {
    $path = $args[0];
  }
  else {
    $path = 'sites/all/libraries';
  }

  $filename = basename(FANCYBOX_DOWNLOAD_URL);
  $dirname = 'fancybox';
  $fullpath = $path . '/' . $dirname;

  // Create the path if it does not exist.
  if (is_dir($fullpath)) {
    // Override any existing fancyBox plugin directory.
    drush_delete_dir($fullpath);
    drush_log(dt('An existing version of fancyBox was overwritten at @path', array('@path' => $fullpath)), 'warning');
  }

  // Remember curent working directory.
  $olddir = getcwd();

  // Set the directory to the download location.
  chdir($path);

  // Download the Javascript file.
  if (!drush_shell_exec('wget ' . FANCYBOX_DOWNLOAD_URL)) {
    drush_shell_exec('curl -O ' . FANCYBOX_DOWNLOAD_URL);
  }

  if (is_file($filename)) {
    // Extract zip archive.
    drush_shell_exec('unzip -qq -o ' . $filename);
    // Rename directory.
    drush_shell_exec('mv fancyBox-* ' . 'fancybox');
    // Remove zip archive.
    drush_op('unlink', $filename);
  }

  // Set working directory back to the previous working directory.
  chdir($olddir);

  // We just check for jquery.fancybox.pack.js file.
  if (file_exists($fullpath . '/source/jquery.fancybox.pack.js')) {
    drush_log(dt('The fancyBox plugin has been downloaded to @path', array('@path' => $fullpath)), 'success');
  }
  else {
    drush_log(dt('Drush was unable to download the fancyBox plugin to @path', array('@path' => $fullpath)), 'error');
  }
}
