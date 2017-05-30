<?php




function sy_commerce_add_my_form($form, &$form_state)
{

    sy_commerce_add_feeds_run();
        $form['isnew'] = array(
            '#markup' => 'hidden',
        );


    return $form;
}
