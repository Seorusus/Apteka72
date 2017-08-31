<?php
function sy_commerce_add_test_form()
{

    $order=commerce_order_load(7);
    dpm($order);

    foreach ($order->commerce_line_items['und'] as $commerce_line_item)
    {
//        dpm($commerce_line_item);
        $cli=commerce_line_item_load($commerce_line_item['line_item_id']);
        dpm($cli);
    }



    $form['clear'] = array(
        '#type'  => 'submit',
        '#value' => 'Очистить1','#weight' => 50,
    );
    return $form;
}