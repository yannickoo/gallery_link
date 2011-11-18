-- Installation --

Download fancybox 1.3.4 from fancybox.net
Unzip the archive and put the fancybox folder inside into sites/all/libraries
(so jquery.fancybox-1.3.4.pack.js is located at sites/all/libraries/fancybox/jquery.fancybox-1.3.4.pack.js)

-- Usage --

There are some functions which you can use:

gallery_link_get_file_path($file, $preset)
  Returns the path to a file. If $preset is set you'll get an imagecache path to $file

  $file - The file id (can also be a file path)
  $preset - The name of the imagecache preset

theme('gallery_link', $elements, $preset, $text, $options = array());
  Returns a link which triggers a slideshow

  $element - $element is an array which contains the images.
  $text - This is the text of the trigger link
  $preset - The images will be display with this imagecache preset
  $options - (optional) Here can you pass an array which is structured like the options from the l() function

--Example --

<?php
  $images = array();

  $images[] = array('file' => 'http://drupal.org/files/druplicon.small_.png');
  $images[] = array('file' => 5);
  $images[] = array('file' => '/themes/garland/logo.png');
  $images[] = array('file' => 19);

  return theme('gallery_link', $images, t('Click to open gallery'), 'big');
}
?>

So we get a link with the label "Click to open gallery" and on click it triggers a gallery displaying our four images with the imagecache preset "big".
