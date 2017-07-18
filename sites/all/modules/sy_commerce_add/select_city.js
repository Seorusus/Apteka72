(function ($) {

    Drupal.behaviors.sy_commerce_add_block_select_city = {
        attach: function (context, settings) {

            $('.block-sy-commerce-add select').change(function() {
                // set the window's location property to the value of the option the user has selected
                window.location = $(this).val();
            });
     
}
};

}(jQuery));