Drupal.behaviors.slideshow_link = function(context) {
  
    // We bind a click event to all items with the class "loom-slideshow-trigger"
    $('.slideshow-link-trigger').bind('click', function() {
      // We know the slideshow id from link from the "data-loom-slideshow-id" attribute
      // We access the slideshows with the slideshow id and put it into the fancybox
      $.fancybox(Drupal.settings.slideshow_link[$(this).attr('data-slideshow-link-id')]);
      // We prevend the default behavior of the link
      return false;
    });
    
}