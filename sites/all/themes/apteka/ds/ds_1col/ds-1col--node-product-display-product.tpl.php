<div <?php print $layout_attributes; ?> class="<?php print $classes; ?>">

    <?php if (isset($title_suffix['contextual_links'])): ?>
        <?php print render($title_suffix['contextual_links']); ?>
    <?php endif; ?>


    <<?php print $ds_content_wrapper; ?> class="product-row">

    <?php print $ds_content; ?>
</<?php print $ds_content_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
    <?php print $drupal_render_children ?>
<?php endif; ?>
</div>
