-- Installation --

- Download fancybox 1.3.4 from fancybox.net
- Unzip the archive and put the fancybox folder inside into sites/all/libraries
- (so jquery.fancybox-1.3.4.pack.js is located at
  sites/all/libraries/fancybox/jquery.fancybox-1.3.4.pack.js)

-- Usage --

  theme(
    'gallery_link', 
    $items, 
    $link_text, 
    $preset, 
    $link_options = array(), 
    $fancybox_options = array()
  );
  
  
  Returns a link which triggers a slideshow

  $items              $items is an array which contains the images.

  $link_text          This is the text of the trigger link

  $preset             The images will be display with this imagecache preset

  $link_options       (optional) Here you can pass an array which is
                      structured like the options from the l() function

  $fancybox_options   (optional) Here you can pass an array which
                      defines the fancybox options (http://fancybox.net/api)

-- Example --

  <?php
    $images = array();

    $images[] = array(
      'file' => 'http://drupal.org/files/druplicon.small_.png',
      'title' => 'just druplicon'
    );

    $images[] = array(
      'file' => 5,
      'title' => 'nice five'
    );

    $images[] = array(
      'file' => '/themes/garland/logo.png'
    );

    $link_options = array(
      'attributes' => array(
        'class' => 'foo',
      ),
    );

    $fancybox_options = array(
      'overlayColor' => '#fff',
    );

    return theme(
      'gallery_link',
      $images, 
      t('Click to open gallery'), 
      'big',
      $link_options,
      $fancybox_options
    );
  }
  ?>

So we get a link with the label "Click to open gallery" and on click
it triggers a gallery displaying our images with the imagecache preset "big".

