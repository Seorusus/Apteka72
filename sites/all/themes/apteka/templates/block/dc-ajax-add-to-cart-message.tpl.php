<?php

/**
 * @file
 * Add to cart message template file.
 *
 * If you want to change the structure of Add to Cart Message popup, then copy
 * this file to your theme's templates directory and do your changes. DO NOT
 * change this file.
 *
 * Available variables:
 * - $line_item: The line item object recently ordered.
 * - $product: The product object recently added to cart.
 * Other variables:
 * - $product_per_unit_price: Per unit price of the product. It has currency
 *   code or symbol attached to it. Currency code or symbol depends on the
 *   AJAX Add to Cart settings.
 * - $product_price_total: Total price of the product. It has currency
 *   code or symbol attached to it. Currency code or symbol depends on the
 *   AJAX Add to Cart settings.
 * - $configuration['success_message']: Success message to be shown on popup.
 * - $configuration['popup_checkout']: Checkout link text.
 * - $checkout_link: Link to checkout page.
 * - $configuration['popup_continue_shopping']: Continue shopping button text.
 * - $configuration['popup_product_name_display']: Check whether to show the
 *   name of product.
 * - $configuration['popup_product_name_label']: Check whether to display name
 *   label.
 * - $product_name: Product name.
 * - $configuration['popup_product_price_display']: Check whether to show the
 *   per unit price of product.
 * - $configuration['popup_product_price_label']: Check whether to display price
 *   label.
 * - $configuration['popup_product_quantity_display']: Check whether to show
 *   quantity of product.
 * - $configuration['popup_product_quantity_label']: Check whether to display
 *   quantity label.
 * - $configuration['popup_product_total_display']: Check whether to show
 *   product total.
 * - $configuration['popup_product_total_label']: Check whether to display total
 *   label.
 */
?>
<div class="add-to-cart-overlay" id="add-to-cart-overlay"></div>
<div class="add-cart-message-wrapper">
  <a class="add-to-cart-close" data-dismiss="add-cart-message">
    <span class="element-invisible"><?php print t('Close'); ?></span>
  </a>
<div class="messages-cat"><?php print $configuration['success_message']; ?></div>

    <div class="option-buttonn checkoutn"><?php print l('В корзину',  'cart' , array('query' => array('return'=>$path_return),'attributes'=>array('class'=>'catalog-link element-invisible'))); ?></div>
    <div class="option-buttonn continuen" data-dismiss="add-cart-message" type="submit"><?php print $configuration['popup_continue_shopping']; ?></div>

</div>
