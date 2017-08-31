<?php
function sy_commerce_add_token_info() {

    // Создаём новый токен с паролем и добавляем его в группу пользователей.
    $info['tokens']['commerce-order']['report'] = array(
        'name' => 'Бланк заказа',
        'description' => 'Бланк заказа Аптеки',
    );

    return $info;
}
function sy_commerce_add_tokens($type, $tokens, array $data = array(), array $options = array()) {

    $replacements = array();
    if (isset($data['commerce-order']) ) {
        $order=$data['commerce-order'];





        $styles[] = array(
            'type' => 'file',
            'media' => 'all',
            'data' => commerce_invoice_reciept_css_path(),
            'group' => CSS_DEFAULT,
            'every_page' => FALSE,
            'weight' => 0,
            'preprocess' => FALSE,
            'browsers' => array(),
        );
        $html = drupal_get_css($styles);

        $build = entity_view('commerce_order', array($order->order_id => $order), 'invoice', NULL, TRUE);
        $invoice_info = _commerce_invoice_receipt_get_invoice_info($order, $build);

        $html .= theme('commerce_order_invoice_view', array('info' => $invoice_info, 'order' => $order));

        $replacements['[commerce-order:report]'] = _emogrifier_process($html, NULL, NULL, NULL, NULL, NULL);
    }
    return $replacements;
}
