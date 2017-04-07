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