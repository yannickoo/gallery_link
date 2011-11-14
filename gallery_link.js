Drupal.behaviors.gallery_link = function(context) {
  
    // We bind a click event to all items with a "data-gallery-id" attribute
    $('a[data-gallery-id]').bind('click', function() {
      // We access the slideshows with the slideshow id and put it into the fancybox
      $.fancybox(Drupal.settings.gallery_link[$(this).attr('data-gallery-id')]);
      // We prevend the default behavior of the link
      return false;
    });
    
}
