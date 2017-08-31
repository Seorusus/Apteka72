<?php


function apteka_form_alter(&$form, &$form_state, $form_id)
{

    if (in_array($form_id, array('user_login', 'user_login_block'))) {
        $form['name']['#attributes']['placeholder'] = t('Введите логин...');
        $form['pass']['#attributes']['placeholder'] = t('Введите пароль...');
    }

    if (TRUE === in_array($form_id, array('user_register_form'))) {
        $form['account']['name']['#attributes']['placeholder'] = t('Введите логин...');
        $form['account']['mail']['#attributes']['placeholder'] = t('Введите e-mail...');
    }

    if (TRUE === in_array($form_id, array('user_pass'))) {
        $form['name']['#attributes']['placeholder'] = t('Введите логин...');
    }

    if (TRUE === in_array($form_id, array('commerce_checkout_form_checkout'))) {
        $form['customer_profile_billing[commerce_customer_address][und][0][first_name]']['#attributes']['placeholder'] = t('Введите логин...');
    }

    if (commerce_form_callback($form_id, $form_state) == "commerce_cart_add_to_cart_form") {
        $form['submit']['#value'] = t('В корзину');
    }
}

function apteka_page_alter(&$page)
{
    drupal_add_css('http://fonts.fontstorage.com/import/opensans.css');
}
function apteka_taxonomy_menu_block__1($variables) {
    $tree = $variables['items'];
    $config = $variables['config'];

    $num_items = count($tree);
    $i = 0;

    $output = '<ul>';
    foreach ($tree as $tid => $term) {
        $i++;
        // Add classes.
        $attributes = array();
        if ($i == 1) {
            $attributes['class'][] = 'first';
        }
        if ($i == $num_items) {
            $attributes['class'][] = 'last';
        }
        if ($term['active_trail'] == '1') {
            $attributes['class'][] = 'active-trail';
        }
        if ($term['active_trail'] == '2') {
            $attributes['class'][] = 'active';
        }

        // Alter link text if we have to display the nodes attached.
        if (isset($term['nodes'])) {
            $term['name'] = $term['name'] . ' (' . $term['nodes'] . ')';
        }

        // Set alias option to true so we don't have to query for the alias every
        // time, as this is cached anyway.
        $lterm=taxonomy_term_load($tid);
        $icons='<img src="/'.drupal_get_path('theme','apteka').'/images/herbal.png">';
        if(isset($lterm->field_ikons['und'][0]['uri'])) $icons='<img src="' .image_style_url('menu_icons_17',$lterm->field_ikons['und'][0]['uri']). '">';
        $output .= '<li' . drupal_attributes($attributes) . '>' . l($icons.$term['name'], $term['path'], $options = array('alias' => TRUE,'html' => TRUE));
        if (!empty($term['children'])) {
            $output .= theme('taxonomy_menu_block__' . $config['delta'], (array('items' => $term['children'], 'config' => $config)));
        }
        $output .= '</li>';
    }
    $output .= '</ul>';

    return $output;
}
