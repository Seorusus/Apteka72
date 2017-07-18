(function ($) {
    Drupal.behaviors.yourName = {
        attach : function(context, settings) {


            $( 'div.view-id-taxonomy_term .views-row select[name="product_id"][class!="refreshed"]' ).each(function( index ) {
                console.log( index + ": " + $( this ).attr('class') );
                $( this ).parent().addClass("refreshed");
                $( this ).addClass("refreshed"); 
               // $( this ).change();
            });


        }

    };
})(jQuery);