<div class="<?php print $classes; ?>"<?php print $attributes; ?> id="<?php print $block_html_id; ?>">

    <?php print render($title_prefix); ?>
    <?php if ($title): ?>
        <h2<?php print $title_attributes; ?>>

            <?php print $title; ?>

            <button class="hamburger hamburger--spin" type="button">
                <span class="hamburger-box">
                    <span class="hamburger-inner"></span>
                </span>
            </button>

        </h2>
    <?php endif; ?>
    <?php print render($title_suffix); ?>
    <div class="menu-wrap">
        <?php print $content; ?>
    </div>
</div>
