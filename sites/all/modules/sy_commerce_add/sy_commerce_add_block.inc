<?php


function sy_commerce_add_block_info()
{
  $blocks['test-loc'] = array(
    'info' => 'Test loc',
    'cache' => DRUPAL_NO_CACHE,
  );
  return $blocks;
}

function sy_commerce_add_block_view($delta = '')
{
  $block = array();


  if ($delta == 'test-loc') {
    $block['subject'] = 'Test loc';
    $block['content'] = drupal_get_form('sy_commerce_add_block_form');
  }

  return $block;

}


function sy_commerce_add_block_form($form, &$form_state)
{
  $form['city'] = array(
    '#type' => 'radios',
    '#title' => 'Город',
    '#default_value' => variable_get('sy_commerce_add_block_temp',0),
    '#options' => array(0=>'IP',1=>'Днепр',2=>'Киев',),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'change',
  );
  $form['desc']=array('#markup'=>'Для тестирования ...');

  $form['#attributes'] = array('style' => 'border:1px doteed red;');

  return $form;
}

function sy_commerce_add_block_form_submit($form, &$form_state)
{
  $values = $form_state['values'];
  variable_set('sy_commerce_add_block_temp',$values['city']);
}