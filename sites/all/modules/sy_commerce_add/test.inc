<?php
function sy_commerce_add_test_form()
{
    $node = node_load(31248);

    dpm($node, '$node');

    if ($node->type == 'product_display1') {

        $dest = 'public://products/';
        $image_in = FALSE;

        if (count($node->field_product['und']) == 0) {
          //  drupal_set_message('пустой');
        } else {
            $product = commerce_product_load($node->field_product['und'][0]['product_id']);
            dpm($product, '$product');
            if (substr_count($product->sku, ';') > 0 && strpos($product->sku, ';') > 0) {
                // если есть нормальный ску
                $sku = substr($product->sku, 0, strpos($product->sku, ';'));
                $file_in = $dest . $sku;
                dpm($file_in, '$file_in');
                /*          $file_image=image_get_info($file_in);
                          if($file_image)
                          { // есди есть картинка по СКУ
                              dpm($file_image,'$file_image');
                          }
                          */
                if ($file_image = image_get_info($file_in . '.JPG')) {
                    $file_in .= '.JPG';
                } elseif ($file_image = image_get_info($file_in . '.JPEG')) {
                    $file_in .= '.JPEG';
                } elseif ($file_image = image_get_info($file_in . '.PNG')) {
                    $file_in .= '.PNG';
                } elseif ($file_image = image_get_info($file_in . '.GIF')) {
                    $file_in .= '.GIF';
                } else { /* ФАЙЛА НЕТ */
                }
                if ($file_image) {
                    dpm($file_image);
                    $file_add = FALSE;
                    if (count($node->field_image['und']) > 0) {
                        // если есть вообще картинка
                        dpm($node->field_image['und'][0]);
                        if ($file_image['width'] == $node->field_image['und'][0]['width'] && $file_image['height'] == $node->field_image['und'][0]['height'] &&
                            $file_image['mime_type'] == $node->field_image['und'][0]['filemime'] && $file_image['file_size'] == $node->field_image['und'][0]['filesize']
                        ) {
                            $image_in = $node->field_image['und'][0];
                            drupal_set_message('одинаковые');
                        } else {
                            db_delete('file_managed')
                                ->condition('uri', $file_in)
                                ->execute();
                            unset($node->field_image['und']);
                            $file_add = TRUE;
                        }
                    } else {
                        $file_add = TRUE;
                    }
                    if ($file_add == TRUE) {

                        $file = file_save((object)array(
                            'filename' => basename($file_in),
                            'uri' => $file_in,
                            'status' => FILE_STATUS_PERMANENT,
                            'filemime' => file_get_mimetype($file_in),
                        ));
                        dpm($file);
                        $image_in = file_load($file->fid);
                        $node->field_image['und'][0] = $image_in;
                    }

                } else {
                    if (count($node->field_image['und']) > 0) $image_in = $node->field_image['und'][0];
                }
                /*                if(count($node->field_image['und'])>0)
                                { // если есть вообще картинка
                                    $image_in=$node->field_image['und'][0];

                                }

                */


                if ($image_in != FALSE) {
                    foreach ($node->field_product['und'] as $prd) {
                        drupal_set_message('Запись картинки продуктам');
                    }
                }
            }
            else
            {
                if (count($node->field_image['und']) > 0) $image_in = $node->field_image['und'][0];
            }
            if($image_in)
            {
                dpm($image_in);
            }
        }
    }
    node_save($node);
    $form['clear'] = array(
        '#type' => 'submit',
        '#value' => 'Очистить1', '#weight' => 50,
    );
    return $form;
}