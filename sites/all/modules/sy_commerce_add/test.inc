<?php
function sy_commerce_add_test_form()
{


    $output = sy_commerce_add_get_orders_xml();
    file_unmanaged_save_data($output , drupal_realpath('public://feeds-tmp/output.xml'), FILE_EXISTS_REPLACE);
    $form['clear'] = array(
        '#type'  => 'submit',
        '#value' => 'Очистить1','#weight' => 50,
    );
    return $form;
}