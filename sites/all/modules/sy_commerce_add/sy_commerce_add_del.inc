<?php




function sy_commerce_add_my_form($form, &$form_state)
{
db_query('update elysia_cron set running = 0');
    variable_set('sy_commerce_add_cron',0);
    $form['isnew'] = array(
            '#markup' => 'hidden',
        );


    return $form;
}
