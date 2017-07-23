(function ($) {
    Drupal.behaviors.yourName = {
        attach : function(context, settings) {


            $( 'div.view-id-taxonomy_term .views-row[class!="refreshed"] select[name="product_id"]' ).each(function( index ) {
                if(!$( this ).parent().parent().parent().parent().parent().parent().hasClass("refreshed")) {
                    $(this).parent().parent().parent().parent().parent().parent().addClass("refreshed");
                    $(this).change();
                }
            });


        }

    };
})(jQuery);