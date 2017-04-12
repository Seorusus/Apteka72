<?php

$plugin = array(
    'form' => 'sy_commerce_add_sy_plugin_date_form',
    // Optional validation callback.
    'validate' => 'sy_commerce_add_sy_plugin_date_validate',
    'callback' => 'sy_commerce_add_sy_plugin_date_callback',
    'name' => 'SY plugin date',
    'multi' => 'loop',
    'category' => 'Other',
);

function sy_commerce_add_sy_plugin_date_form($importer, $element_key, $settings) {
    $form = array();
    // $form['help']['#value'] = t('My plugin can do awesome things.');
    //
    // Other formy stuff here.
    //
    return $form;
}

function sy_commerce_add_sy_plugin_date_validate(&$settings) {
    // Validate $settings.
}

function sy_commerce_add_sy_plugin_date_callback($source, $item_key, $element_key, &$field, $settings) {

if(strlen(trim($source->current_item[$element_key]))==10)
{
    $field=date("d-m-Y",$source->current_item[$element_key]);
}
    else
    {
        $field=NULL;
    }
}