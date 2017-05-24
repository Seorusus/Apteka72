<?php


function sy_commerce_add_block_info()
{
  $blocks['select-city'] = array(
      'info' => 'Выбор города',
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

  return $block;

}


function sy_commerce_add_change_sity($city)
{
  $_SESSION['sy_commerce_add_city']=$city;
  drupal_goto(drupal_get_destination());
}
function sy_commerce_add_block_select_city()
{
  $citys=sy_commerce_add_get_city_stocks();
  dpm($citys);
  dpm($_SESSION);
  $out=array();
  foreach ($citys as $city)
  {
     $attr=array(); if(isset($_SESSION['sy_commerce_add_city']) && $_SESSION['sy_commerce_add_city']==$city) $attr= array('class' =>'active');
      $out[]=l($city, 'change-sity/'.$city, array('query' => array( drupal_get_destination()),'attributes' =>$attr));
  }
  return implode(' ',$out);


}