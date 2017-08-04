<?php


function sy_commerce_add_block_info()
{
    $blocks['select-city'] = array(
        'info' => 'Выбор города',
        'cache' => DRUPAL_NO_CACHE,
    );
    $blocks['select-city-new'] = array(
        'info' => 'Выбор города new',
        'cache' => DRUPAL_NO_CACHE,
    );
    return $blocks;
}

function sy_commerce_add_block_view($delta = '')
{
    $block = array();

    if ($delta == 'select-city') {
        $block['content'] = sy_commerce_add_block_select_city();
    }

    if ($delta == 'select-city-new') {
        $block['content'] = drupal_get_form('sy_commerce_add_block_select_city_new_form');
//    $block['content'] = sy_commerce_add_block_select_city_new();
    }

    return $block;

}


function sy_commerce_add_change_sity($city)
{
    $_SESSION['sy_commerce_add_city'] = $city;
    drupal_goto(drupal_get_destination());
}

function sy_commerce_add_block_select_city()
{
    $citys = sy_commerce_add_get_city_stocks();
    if (!isset($_SESSION['sy_commerce_add_city'])) sy_commerce_add_get_city_stocks_location();
    $out = array();
    foreach ($citys as $city) {
        $attr = array();
        if (isset($_SESSION['sy_commerce_add_city']) && $_SESSION['sy_commerce_add_city'] == $city) $attr = array('class' => 'active');
        $out[] = l($city, 'change-sity/' . $city, array('query' => array(drupal_get_destination()), 'attributes' => $attr));
    }
    return implode(' ', $out);


}


function sy_commerce_add_block_select_city_new_form()
{
    $form = array();
    $citys = sy_commerce_add_get_city_stocks();
    if (!isset($_SESSION['sy_commerce_add_city'])) sy_commerce_add_get_city_stocks_location();
    $def = NULL;
    $options = array();
    foreach ($citys as $city) {
        $key = 'change-sity/' . $city . '?destination=' . current_path();
        if (isset($_SESSION['sy_commerce_add_city']) && $_SESSION['sy_commerce_add_city'] == $city) $def = $key;
        $options[$key] = $city;
    }
    $form['selected'] = array(
        '#type' => 'select',
        '#title' => t('Selected'),
        '#options' => $options,
        '#default_value' => $def,
    );
    $form['#attached']['js'] = array(
        drupal_get_path('module', 'sy_commerce_add') . '/select_city.js', 
    );
    if(arg(0)=='cart' || arg(0)=='checkout') $form['selected']['#disabled']=TRUE;
    return $form;
}