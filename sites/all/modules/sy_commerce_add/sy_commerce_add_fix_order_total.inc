<?php
/**
 * Implements hook_theme_registry_alter().
 */
function sy_commerce_add_theme_registry_alter(&$theme_registry)
{
    $theme_registry['commerce_price_formatted_components']['function'] = 'theme_sy_commerce_add_price_formatted_components';
}

/**
 * Themes a price components table.
 *
 * @param $variables
 *   Array contains the 'components' array and original 'price' array.
 *
 * @return string
 *   The formatted price components.
 */
function theme_sy_commerce_add_price_formatted_components(&$variables)
{
// Add the CSS styling to the table.
    drupal_add_css(drupal_get_path('module', 'commerce_price') . '/theme/commerce_price.theme.css');

// Build table rows out of the components.
    $rows = array();
    $variables['components']['commerce_price_formatted_amount']['title'] = t('Order total');
    foreach ($variables['components'] as $name => $component) {
        $rows[] = array(
            'data' => array(
                array(
                    'data' => $component['title'],
                    'class' => array('component-title'),
                ),
                array(
                    'data' => $component['formatted_price'],
                    'class' => array('component-total'),
                ),
            ),
            'class' => array(drupal_html_class('component-type-' . $name)),
        );
    }

    return theme('table', array('rows' => $rows, 'attributes' => array('class' => array('commerce-price-formatted-components'))));
}