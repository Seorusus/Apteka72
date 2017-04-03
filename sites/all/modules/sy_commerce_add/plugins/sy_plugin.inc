<?php

$plugin = array(
    'form' => 'sy_commerce_add_sy_plugin_form',
    // Optional validation callback.
    'validate' => 'sy_commerce_add_sy_plugin_validate',
    'callback' => 'sy_commerce_add_sy_plugin_callback',
    'name' => 'SY plugin',
    'multi' => 'loop',
    'category' => 'Other',
);

function sy_commerce_add_sy_plugin_form($importer, $element_key, $settings) {
    $form = array();
   // $form['help']['#value'] = t('My plugin can do awesome things.');
    //
    // Other formy stuff here.
    //
    return $form;
}

function sy_commerce_add_sy_plugin_validate(&$settings) {
    // Validate $settings.
}

function sy_commerce_add_sy_plugin_callback($source, $item_key, $element_key, &$field, $settings) {


    $product=commerce_product_load_by_sku($source->current_item['xpathparser:0']);
    if($product){ // Склад не обновим до создания  продукта
    $shop_quantity=$source->current_item['xpathparser:'.(( (int) str_replace('xpathparser:','',$element_key) )+1)];
    commerce_stock_calculation_save_config('stock_calculation:'.$product->product_id, 'sum_calculation', array());
 sy_commerce_add_change_stocks_settings($product->product_id, $field, $shop_quantity);}
}
function sy_commerce_add_change_stocks_settings($product_id, $shop_name, $shop_quantity)
{

    $product=commerce_product_load($product_id);
    $plugin_type = commerce_stock_calculation_get_active_plugin($product);
    $plugin = commerce_stock_calculation_get_plugin_instance($plugin_type, array( 'product' => $product,));
    $f = array();$plugin_settings_form = $plugin->settingsForm($f,$f);

    $shops=$plugin_settings_form['#options'];
    $plugin_id='stock_calculation:'.$product_id;
    $calculation_plugin_settings=array();
    foreach ($shops as $key=>$value)
    {
        if($value==$shop_name)
        {
            $item_quantity=$shop_quantity;
            $calculation_plugin_settings[$key]=$key;
        }
        else
        {
            $item_quantity=0;
            $calculation_plugin_settings[$key]=0;
        }
        $calculation_plugin_settings[$key]=$value==$shop_name?$key:0;
        $quantity = commerce_stock_sources_load_quantity_by_product_and_source($product_id, $key);
        $values=array(
            'stq_id'=>$quantity->stq_id,
            'source_id'=>$key,
            'product_id'=>$product_id,
            'quantity'=>$item_quantity,
            'uid'=>1
        );
        $controller = entity_get_controller('commerce_stock_quantity');
        $entity = $controller->create($values);
        $controller->save($entity);
    }
    commerce_stock_calculation_save_config($plugin_id, 'sum_calculation', $calculation_plugin_settings);
    $plugin = commerce_stock_calculation_get_plugin_instance('sum_calculation', array('product' => $product));
    $quantity = $plugin->calculate();
    $wrapper = entity_metadata_wrapper('commerce_product', $product);
    $wrapper->commerce_stock->set($quantity);
    $wrapper->save();
}

