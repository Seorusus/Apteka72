<?php

function sy_commerce_add_entity_load($entities, $type)
{
  if($type=='commerce_line_item')
  {
    foreach ($entities as $key=>$entity) {
      $entities[$key]->quantity_over = sy_commerce_add_get_quantity_over_li( $entity->line_item_id );
    }
  }
}
function sy_commerce_add_entity_presave($entity, $type)
{
  if($type=='commerce_line_item' && $entity->type=='product')
  {
    $line_item_id=$entity->line_item_id;
    if($line_item_id>0)
    {
      $product=commerce_product_load($entity->commerce_product[LANGUAGE_NONE][0]['product_id']);
      $quantity_over=$entity->quantity-$product->commerce_stock[LANGUAGE_NONE][0]['value'];
      $quantity_over=$quantity_over<0?0:$quantity_over;
      $qty_id=sy_commerce_add_get_qty_id_li($line_item_id);

      //if($product->commerce_stock_override[LANGUAGE_NONE][0]['value']==0)
      if($quantity_over>0)
      {
        if($qty_id>0)
          sy_commerce_add_quantity_over_update($qty_id,$quantity_over);
        else
          sy_commerce_add_quantity_over_add($line_item_id,$quantity_over);
      }
      else
      {
        sy_commerce_add_quantity_over_del($qty_id);
      }
    }


  }

}
function sy_commerce_add_quantity_over_del($qty_id)
{
  db_delete('sy_commerce_add_quantity')
    ->condition('qty_id', $qty_id)
    ->execute();
}
function sy_commerce_add_quantity_over_add($line_item_id,$quantity_over)
{

  db_insert('sy_commerce_add_quantity')
    ->fields(array(
      'line_item_id' => $line_item_id,
      'quantity' => $quantity_over,
    ))
    ->execute();
}
function sy_commerce_add_quantity_over_update($qty_id,$quantity_over)
{
  db_update('sy_commerce_add_quantity')
    ->fields(array('quantity' => $quantity_over))
    ->condition('qty_id', $qty_id)
    ->execute();
}
function sy_commerce_add_get_qty_id_li($line_item_id)
{
  $qty_id = db_select('sy_commerce_add_quantity', 'q')
    ->fields('q', array('qty_id'))
    ->condition('q.line_item_id', $line_item_id)
    ->execute()
    ->fetchField();
  return (is_numeric($qty_id)?$qty_id:0);
}
function sy_commerce_add_get_quantity_over_li($line_item_id)
{
$quantity = db_select('sy_commerce_add_quantity', 'q')
  ->fields('q', array('quantity'))
  ->condition('q.line_item_id', $line_item_id)
  ->execute()
  ->fetchField();
return (is_numeric($quantity)?floatval($quantity):0);
}

function sy_commerce_add_get_list_product_in_stocks($nid)
{
$arr_out = array();
    $stoks = db_query("SELECT
                        product.sku,
                        product.title,
                        product.product_id
                        FROM
                        {field_data_field_product} AS tovar
                        INNER JOIN {commerce_product} AS product ON product.product_id = tovar.field_product_product_id
                        WHERE
                        tovar.entity_id = :nid", array(':nid' => $nid))->fetchAllAssoc('product_id');

    foreach ($stoks as $stok) {
      $stock_sets = db_query("SELECT * FROM {commerce_stock_calculation} WHERE name = :name", array(':name' => 'stock_calculation:' . $stok->product_id))->fetchObject();
      if (isset($stock_sets->plugin)) {
      $settings = array();
      if ($stock_sets->plugin == 'sum_calculation') {
        $settings = sy_commerce_add_get_stoks_for_product($stok->product_id, $stock_sets->settings);
      }
      $arr_out[$stok->product_id] = array(
        'product_id' => $stok->product_id,
        'sku' => $stok->sku,
        'title' => $stok->title,
        'plugin' => $stock_sets->plugin,
        'settings' => $settings,

      );
    }
    }
    return $arr_out;
}
function sy_commerce_add_get_stoks_for_product($pid, $settings)
{
  $arr_out = array();
  $stok_id = array_values(unserialize($settings));
  $stoks = db_query("SELECT
                    sq.source_id as sid,
                    sq.quantity,
                    s.`name`,
                    c.field_city_value
                    FROM
                    {commerce_stock_quantity} AS sq
                    LEFT JOIN {commerce_stock_sources} AS s ON s.source_id = sq.source_id
                    LEFT JOIN {field_data_field_city} AS c ON c.entity_id = s.source_id
                    WHERE
                    sq.product_id = :pid AND
                    sq.source_id IN (:source_ids) AND
                    c.bundle='commerce_stock_sources'", array(":pid" => $pid, ":source_ids" => $stok_id))->fetchAllAssoc('sid');
  foreach ($stoks as $stok) {
    $arr_out[] = (array)$stok;
  }
  return $arr_out;
}
function sy_commerce_add_get_city_stocks_in($list_product_in_stok)
{
  $citys = array();
  foreach ($list_product_in_stok as $item)
  {
    foreach ($item['settings'] as $value)
    {
      if($value['quantity']>0) $citys[$value['field_city_value']]=$value['field_city_value'];
    }
  }

  return $citys;
}
function sy_commerce_add_get_city_stocks()
{
  $citys = db_select('field_data_field_city', 'c')
      ->fields('c', array('field_city_value', 'field_city_value'))
      ->condition('bundle', "commerce_stock_sources")
      ->orderBy('c.field_city_value', 'ASC')
      ->execute()
      ->fetchAllKeyed();
  return $citys;
} 
function sy_commerce_add_get_options_product($list_product_in_stok, $def_city)
{
  $arr_out = array();
  foreach ($list_product_in_stok as $key => $value) {
    if (count($value['settings']) > 0 && $value['settings'][0]['field_city_value'] == $def_city) {
      $arr_out[$value['product_id']] = $value['settings'][0]['name'] . '(' . $value['settings'][0]['quantity'] . ') ' . $value['sku'];
    }
  }
  return $arr_out;
}


function sy_commerce_add_get_stocks_table($nid)
{
  $stoks = db_query("SELECT product.product_id, product.sku, s_s.`name`, qty.commerce_stock_value,
                    f_city.field_city_value, s_s.source_id, price.commerce_price_amount,price.commerce_price_currency_code, edr.field_expected_date_receipt_value 
                    FROM {commerce_product} AS product
                    INNER JOIN {field_data_field_product} AS f_pr ON f_pr.field_product_product_id = product.product_id
                    INNER JOIN {field_data_commerce_stock} AS qty ON qty.revision_id = product.revision_id 
                    INNER JOIN {commerce_stock_quantity} AS s_qty ON s_qty.product_id = product.product_id 
                    INNER JOIN {commerce_stock_sources} AS s_s ON s_s.source_id = s_qty.source_id
                    INNER JOIN {field_data_field_city} AS f_city ON f_city.entity_id = s_s.source_id 
                    INNER JOIN {field_data_commerce_price} AS price ON price.revision_id = product.revision_id 
                    LEFT JOIN {field_data_field_expected_date_receipt} AS edr ON edr.revision_id = product.revision_id
                    WHERE f_pr.entity_id = :nid AND product.type = 'product' AND f_city.bundle = 'commerce_stock_sources' 
                    ORDER BY  f_city.field_city_value ASC, s_s.`name` ASC", array(':nid' => $nid))->fetchAll();
  $rows = array();
  foreach ($stoks as $stok) {
    $stock_sets = db_query("SELECT * FROM {commerce_stock_calculation} WHERE name = :name", array(':name' => 'stock_calculation:' . $stok->product_id))->fetchObject();
    if (isset($stock_sets->plugin)) {
      if ($stock_sets->plugin == 'sum_calculation') {
        $settings = unserialize($stock_sets->settings);
        if ($settings[$stok->source_id] == $stok->source_id) {
          $edr='';
          if($stok->commerce_stock_value >=0 && $stok->field_expected_date_receipt_value>0 )
          {
            $edr='Ожидаемое поступление '.$stok->field_expected_date_receipt_value;
          }
          $rows[] = array(
              check_plain($stok->field_city_value), check_plain($stok->name), check_plain($stok->sku),
              floatval($stok->commerce_stock_value > 0 ? $stok->commerce_stock_value : 0),
              commerce_currency_format($stok->commerce_price_amount, $stok->commerce_price_currency_code), $edr

          );
        }
      }
    }
  }
  $header = array('Город', 'Аптека', 'Артикуль', 'Кол-во', 'Цена', '');
  if(count($rows)>0)   return array('#markup' => theme('table', array('header' => $header, 'rows' => $rows))); else return '';
}
function sy_commerce_add_get_city_stocks_location()
{
  $location = sy_commerce_add_get_location();
  return db_query("SELECT DISTINCTROW
    city.field_city_value
    FROM
    {commerce_stock_sources} AS stock
    LEFT JOIN {field_data_field_city} AS city ON city.entity_id = stock.source_id
    LEFT JOIN {field_data_field_gip_city} AS gcity ON gcity.entity_id = stock.source_id
    LEFT JOIN {field_data_field_gip_country_code} AS gcc ON gcc.entity_id = stock.source_id
    LEFT JOIN {field_data_field_gip_region} AS gregion ON gregion.entity_id = stock.source_id
    WHERE
    city.bundle = 'commerce_stock_sources' AND
    gcity.bundle = 'commerce_stock_sources' AND
    gcc.bundle = 'commerce_stock_sources' AND
    gregion.bundle = 'commerce_stock_sources' AND
    gcc.field_gip_country_code_value = :code AND
    gregion.field_gip_region_value = :region AND
    gcity.field_gip_city_value = :city LIMIT 0,1", array(':code' => $location['country_code'], ':region' => $location['region'], ':city' => $location['city'],))->fetchField();

}

function sy_commerce_add_get_location()
{
  $smart_ip_session = smart_ip_session_get('smart_ip');
  if (variable_get('sy_b_block_temp', 0) > 0 || !isset($smart_ip_session['location']['country_code'])) {
    $location = array(
      'country_code' => 'UA',
      'region' => variable_get('sy_b_block_temp', 0) == 1 ? "Dnipropetrovs'ka Oblast'" : 'Kyiv',
      'city' => variable_get('sy_b_block_temp', 0) == 1 ? 'Dnepropetrovsk' : 'Kiev'
    );
  } else {
    $location = array(
      'country_code' => $smart_ip_session['location']['country_code'],
      'region' => $smart_ip_session['location']['region'],
      'city' => $smart_ip_session['location']['city']
    );
  }
  return $location;
}