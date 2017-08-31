<html>
<head>
  <?php print $head; ?>
  <base href='<?php print $url ?>'/>
  <title><?php print $print_title; ?></title>
  <?php print $scripts; ?>
  <?php if (isset($sendtoprinter)) {
    print $sendtoprinter;
  } ?>
  <?php print $robots_meta; ?>
  <?php if (theme_get_setting('toggle_favicon')): ?>
    <link rel='shortcut icon' href='<?php print theme_get_setting('favicon') ?>'
          type='image/x-icon'/>
  <?php endif; ?>
  <?php print $css; ?>
</head>
<body>
<?php if (!empty($message)): ?>
  <div class="print-message"><?php print $message; ?></div><p/>
<?php endif; ?>
<?php if ($print_logo): ?>
  <div class="print-logo"><?php print $print_logo; ?></div>
<?php endif; ?>

<?php if (!isset($node->type)): ?>
  <h2 class="print-title"><?php print $print_title; ?></h2>
<?php endif; ?>
<div class="print-content"><?php print $content; ?></div>
<div class="print-footer"><?php print theme('print_footer'); ?></div>
<?php if ($sourceurl_enabled): ?>
  <div class="print-source_url">
    <?php print theme('print_sourceurl', [
      'url' => $source_url,
      'node' => $node,
      'cid' => $cid,
    ]); ?>
  </div>
<?php endif; ?>
<?php print $footer_scripts; ?>
</body>
</html>