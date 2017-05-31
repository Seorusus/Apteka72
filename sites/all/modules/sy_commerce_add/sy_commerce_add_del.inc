<?php




function sy_commerce_add_my_form($form, &$form_state)
{

    $result = db_query("SELECT * FROM {semaphore}");
    foreach ($result as $node) {
       dpm($node);
    }    $result = db_query("SELECT * FROM {elysia_cron}");
    foreach ($result as $node) {
       dpm($node);
    }
    db_query("update elysia_cron set running = 0 where name = 'sy_commerce_add_cron';");
    $form['isnew'] = array(
            '#markup' => 'hidden',
        );


    return $form;
}
