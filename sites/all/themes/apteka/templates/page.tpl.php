<div class="header-mobile">

    <div class="header-mobile-top">

        <div class="wrap">
            <div class="header-mobile-left">
                <?php print render($page['header_mobile_left']); ?>
            </div>

            <div class="header-mobile-center">
                <?php if ($logo): ?>
                    <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"
                       class="header__logo"><img
                                src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>"/></a>
                <?php endif; ?>
            </div>

            <div class="header-mobile-right">
                <?php print render($page['header_mobile_right']); ?>
            </div>
        </div>

    </div>

    <div class="header-mobile-bottom">
        <div class="wrap">
            <?php print render($page['header_mobile_bottom']); ?>
        </div>
    </div>

</div>

<div class="header-destop">
    <div class="header">
        <div class="wrap">
            <?php print render($page['header']); ?>
        </div>
    </div>

    <div class="delivery">
        <div class="wrap">
            <div class="logo-search">
                <?php if ($logo): ?>
                    <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"
                       class="header__logo"><img
                                src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>"/></a>
                <?php endif; ?>
                <?php print render($page['search']); ?>
            </div>
            <?php print render($page['department']); ?>
        </div>
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

        <?php print $breadcrumb; ?>

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

    </div>

</div>

<div class="content-bottom">
    <div class="wrap">
        <?php print render($page['content_bottom']); ?>
    </div>
</div>

<div class="footer">
    <div class="wrap">
        <div class="row">
            <?php print render($page['footer']); ?>
        </div>
    </div>
</div>
