<?php
function sy_commerce_add_test_form()
{


    $product_id=18787; $shop_name='Тюмень, Мельникайте, 135'; $shop_quantity=5;
    $city='';
    $settings = db_select('commerce_stock_calculation', 'n')
        ->fields('n', array('settings'))
        ->condition('n.name', "stock_calculation:$product_id")
        ->execute()
        ->fetchField();
$settings_ar=unserialize($settings);
    foreach ($settings_ar as $key=>$value)
    {
        if($value==1) {
            $city = db_query("SELECT city.field_city_value FROM {commerce_stock_sources} AS stk
                            LEFT JOIN {field_data_field_city} AS city ON city.entity_id = stk.source_id
                            LEFT JOIN {field_data_field_disabled} AS dsbl ON dsbl.entity_id = stk.source_id  WHERE city.bundle = 'commerce_stock_sources' AND
                            dsbl.bundle = 'commerce_stock_sources' AND dsbl.field_disabled_value <> 1 AND stk.source_id = :sid", array(':sid' => $key))->fetchField();
        }
    }
    $product=commerce_product_load($product_id);
    $product->field_city_stock['und'][0]['value']=$city;
    $product->field_city_stock['und'][0]['safe_value']=$city;
    commerce_product_save($product);
    dpm($product);
    /*
    $product_id=18787; $shop_name='Тюмень, Мельникайте, 135'; $shop_quantity=5;
    $product=commerce_product_load($product_id);
    $plugin_type = commerce_stock_calculation_get_active_plugin($product);
    $plugin = commerce_stock_calculation_get_plugin_instance($plugin_type, array( 'product' => $product,));
    $f = array();$plugin_settings_form = $plugin->settingsForm($f,$f);
dpm($plugin_type);
dpm($plugin);
dpm($plugin_settings_form);
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
            'source_id'=>$key,
            'product_id'=>$product_id,
            'quantity'=>$item_quantity,
            'uid'=>1
        );
        if(isset($quantity->stq_id)){$values['stq_id']=$quantity->stq_id;}
        $controller = entity_get_controller('commerce_stock_quantity');
        $entity = $controller->create($values);
        $controller->save($entity);
    }
    dpm($plugin_id);
    dpm($calculation_plugin_settings);
    dpm($product);
    commerce_stock_calculation_save_config($plugin_id, 'sum_calculation', $calculation_plugin_settings);
    $plugin = commerce_stock_calculation_get_plugin_instance('sum_calculation', array('product' => $product));
    $quantity = $plugin->calculate();
    $wrapper = entity_metadata_wrapper('commerce_product', $product);
    $wrapper->commerce_stock->set($shop_quantity);
    $wrapper->save();

*/

    $form['clear'] = array(
        '#type'  => 'submit',
        '#value' => 'Очистить1','#weight' => 50,
    );
    return $form;
}