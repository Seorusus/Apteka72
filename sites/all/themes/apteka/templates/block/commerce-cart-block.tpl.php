<?php

/**
 * @file
 * Default implementation of the shopping cart block template.
 *
 * Available variables:
 * - $contents_view: A rendered View containing the contents of the cart.
 *
 * Helper variables:
 * - $order: The full order object for the shopping cart.
 *
 * @see template_preprocess()
 * @see template_process()
 */
$dest=drupal_get_destination();
if(/*isset($dest['destination']) && */ isset($_SESSION['messages']['status'][0])) {
//  foreach ($_SESSION['messages']['status'] as $key=>$val) $_SESSION['messages']['status'][$key]=str_replace('href="/cart"', 'href="/cart?destination='.$dest['destination'].'"',$val);
  foreach ($_SESSION['messages']['status'] as $key=>$val)
  {
    if(substr_count($val,'href="/cart"')>0 )
    {unset($_SESSION['messages']['status'][$key]); if(count($_SESSION['messages']['status'])<1) unset($_SESSION['messages']['status']); }
  }
}
?>
<div class="cart-contents">
  <div id="cart-lnk" style="display: none;">  <?php print l('',  'cart' , array('query' => array('return'=>$dest['destination']))); ?></div>
  <?php print $contents_view; ?>
</div>


