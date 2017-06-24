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
    $block['content'] = sy_commerce_add_block_select_city_new();
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
  if(!isset($_SESSION['sy_commerce_add_city'])) sy_commerce_add_get_city_stocks_location();
  $out=array();
  foreach ($citys as $city)
  {
     $attr=array(); if(isset($_SESSION['sy_commerce_add_city']) && $_SESSION['sy_commerce_add_city']==$city) $attr= array('class' =>'active');
      $out[]=l($city, 'change-sity/'.$city, array('query' => array( drupal_get_destination()),'attributes' =>$attr));
  }
  return implode(' ',$out);


}function sy_commerce_add_block_select_city_new()
{
  $citys=sy_commerce_add_get_city_stocks();
  if(!isset($_SESSION['sy_commerce_add_city'])) sy_commerce_add_get_city_stocks_location();
  //  $out=array();
  $out='<form name="nav"><select name="SelectURL" onchange="document.location.href=document.nav.SelectURL.options[document.nav.SelectURL.selectedIndex].value">';
  foreach ($citys as $city)
  {
     $attr=''; if(isset($_SESSION['sy_commerce_add_city']) && $_SESSION['sy_commerce_add_city']==$city) $attr='selected="selected"';
    $out.='<option value="change-sity/'.$city.'?destination='.current_path().'" '.$attr.' >'.$city.'</option>';
  }$out.='</select></form>';
  return $out;


}