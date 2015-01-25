<?php

/**
 * @file
 * Views integration for Erpal Reports.
 */

/**
 * Implements hook_views_data_alter()
 */
function erpal_reports_views_data_alter(&$data) {

  // Expose the date format.
  $data['views']['date_format'] = array(
    'title' => t('Exposed date format'),
    'help' => t('Provide exposed filter to change date format'),
    'filter' => array(
      'handler' => 'erpal_reports_handler_filter_date_format',
    ),
  );

  // Payment type: ingoing/outgoing.
  $data['commerce_order']['payment_type'] = array(
    'title' => t('Payment type'),
    'help' => t('Provide filter to chose payment type: ingoing/outgoing'),
    'real field' => 'field_customer_target_id',
    'filter' => array(
      'handler' => 'erpal_reports_handler_filter_payment_type',
    ),
  );
}
