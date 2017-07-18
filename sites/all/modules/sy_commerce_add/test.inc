<?php
function sy_commerce_add_test_form()
{

    /*
        $produ_i/*d='00000004024;000000002';
        $result = db_query("SELECT * FROM {commerce_stock_calculation} WHERE name LIKE  'stock_calculation:00000004024%'");
        foreach ($result as $node) {
            dpm( $node);
        }
 */
       $product_id=14360;
        $settings = db_select('commerce_stock_calculation', 'n')
            ->fields('n', array('settings'))
            ->condition('n.name', "stock_calculation:$product_id")
            ->execute()
            ->fetchField();
        $settings_ar=unserialize($settings);
        $city='';
        foreach ($settings_ar as $key=>$value)
        {
            if($value!=0) {
                $city = db_query("SELECT city.field_city_value FROM {commerce_stock_sources} AS stk
                                LEFT JOIN {field_data_field_city} AS city ON city.entity_id = stk.source_id
                                LEFT JOIN {field_data_field_disabled} AS dsbl ON dsbl.entity_id = stk.source_id  WHERE city.bundle = 'commerce_stock_sources' AND
                                dsbl.bundle = 'commerce_stock_sources' AND stk.source_id = :sid", array(':sid' => $key))->fetchField();
            }
        }
    dpm($settings);
    dpm($settings_ar);
    dpm($city);
    $form['clear'] = array(
        '#type'  => 'submit',
        '#value' => 'Очистить1','#weight' => 50,
    );
    return $form;
}