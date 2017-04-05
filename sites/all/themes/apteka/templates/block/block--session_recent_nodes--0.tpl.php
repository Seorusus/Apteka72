<div class="<?php print $classes; ?>"<?php print $attributes; ?> id="<?php print $block_html_id; ?>">

    <?php print render($title_prefix); ?>
    <?php if ($title): ?>
        <h2<?php print $title_attributes; ?>><span><?php print $title; ?></span></h2>
    <?php endif; ?>
    <?php print render($title_suffix); ?>
    <div class="product-wrap">
        <div class="view-content">
            <?php print $content; ?>
        </div>
    </div>
</div>
