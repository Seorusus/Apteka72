<?php
function sy_commerce_add_token_info() {

    // Создаём новый токен с паролем и добавляем его в группу пользователей.
    $info['tokens']['commerce-order']['rep'] = array(
        'name' => t('User password'),
        'description' => t('Provides user password. May be used only during registration.'),
    );

    return $info;
}
function sy_commerce_add_tokens($type, $tokens, array $data = array(), array $options = array()) {
    $replacements = array();
    if (isset($data['commerce-order']) ) {
        $replacements['[commerce-order:rep]'] = 'hhhhhhhhh';
    }
    return $replacements;
}