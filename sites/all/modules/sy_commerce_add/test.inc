<?php
function sy_commerce_add_test_form()
{


    $form['clear'] = array(
        '#type'  => 'submit',
        '#value' => 'Очистить1','#weight' => 50,
    );
    return $form;
}