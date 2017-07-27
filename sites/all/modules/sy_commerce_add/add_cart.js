(function ($) {

    Drupal.behaviors.sy_commerce_add_add_cart = {
        attach: function (context, settings) {

            function hide_add2cart() {
                $('.commerce-add-to-cart input.form-submit').addClass('element-invisible');
                $('.commerce-add-to-cart a.catalog-link').removeClass('element-invisible');
                $('.ajax-shopping-cart-wrapper a').attr('href','/cart?return='+window.location.pathname);
                $('.ajax-shopping-cart-wrapper .cart-contents.empty').removeClass('empty');
            }

           $('.add-cart-message-wrapper .continuen').live('click', function(){
               console.log('1');
               hide_add2cart();
            });
           $('.add-cart-message-wrapper .add-to-cart-close').live('click', function(){
               console.log('2');
               hide_add2cart();
            });
            $('#edit-product-id').change();










        }
};

}(jQuery));