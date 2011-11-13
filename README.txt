-- Installation --

Download fancybox 1.3.4 from fancybox.net
Unzip the archive and put the fancybox folder inside into sites/all/libraries
(so jquery.fancybox-1.3.4.pack.js is located at sites/all/libraries/fancybox/jquery.fancybox-1.3.4.pack.js)

-- Usage --

There are some functions which you can use:

slideshow_link_get_file_path($fid, $preset)
  Returns the path to a file. If $preset is set you'll get an imagecache path to $fid

  $fid - The file id (can also be a filepath)
  $preset - The name of the imagecache preset

theme('slideshow_link', $elements, $preset, $text, $options = array());
  Returns a link which triggers a slideshow

  $element - $element is an array which contains the images.
  $preset - The images will be display with this imagecache preset
  $text - This is the text of the trigger link
  $options - (optional) Here can you pass an array which is structured like the options from the l() function