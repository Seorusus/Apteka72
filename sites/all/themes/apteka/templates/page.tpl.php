<div class="header">
    <div class="wrap">

        <?php print render($page['header']); ?>

    </div>
</div>

<div class="delivery">
    <div class="wrap">
        <div class="logo-search">
            <?php if ($logo): ?>
                <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="header__logo"><img
                            src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>"/></a>
            <?php endif; ?>
            <?php print render($page['search']); ?>
        </div>
        <?php print render($page['department']); ?>
    </div>
</div>
<div class="main-menu">
    <div class="wrap">
        <div class="menu-block-empty">empty</div>
        <?php print render($page['main_menu']); ?>
    </div>
</div>

<div class="wrap">
    <div class="sidebar">
        <?php print render($page['sidebar']); ?>
    </div>
    <?php print render($page['banner']); ?>
    <div class="main-container">
        <?php print render($page['highlighted']); ?>

        <?php print render($title_prefix); ?>
        <?php if ($title): ?>
            <h2><?php print $title; ?></h2>
        <?php endif; ?>
        <?php print render($title_suffix); ?>
        <?php print $messages; ?>
        <?php print render($tabs); ?>
        <?php print render($page['help']); ?>
        <?php if ($action_links): ?>
            <ul class="action-links"><?php print render($action_links); ?></ul>
        <?php endif; ?>
        <?php print render($page['content']); ?>
        <?php print $feed_icons; ?>
    </div>
</div>

<div class="content-bottom">
    <div class="wrap">
        <?php print render($page['content_bottom']); ?>
    </div>
</div>

<div class="footer">
    <div class="wrap">
        <?php print render($page['footer']); ?>
    </div>
</div>
