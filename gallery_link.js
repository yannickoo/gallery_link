(function ($) {

  Drupal.behaviors.galleryLink = {
    attach: function (context, settings) {
      // We bind a click event to all items with a "data-gallery-id" attribute.
      $('a[data-gallery-link]').bind('click', function(e) {
        var currentGallery = settings.galleryLink[$(this).attr('data-gallery-link')];
        // Trigger fancyBox, pass images and optins.
        $.fancybox(currentGallery['images'], currentGallery['options']);
        // We prevend the default behavior of the link.
        e.preventDefault();
      });
    }
  };

})(jQuery);
