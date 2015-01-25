<?php

/**
 * @file
 * Rules integration for ERPAL Report.
 */

/**
 * Implements hook_rules_action_info().
 */
function erpal_reports_rules_action_info() {
  return array(
    'erpal_reports_create_money_output' => array(
      'label' => t('Auto creating money output entities for reports.'),
      'group' => t('ERPAL Reports'),
      'parameter' => array(
        'commerce_line_item' => array(
          'type' => 'commerce_line_item',
          'label' => t('Line item')),
      ),
    ),
    'erpal_reports_delete_line_item' => array(
      'label' => t('Delete money output on line item deletion.'),
      'group' => t('ERPAL Reports'),
      'parameter' => array(
        'commerce_line_item' => array(
          'type' => 'commerce_line_item',
          'label' => t('Line item'),
        ),
      ),
    ),
    'erpal_reports_update_line_item' => array(
      'label' => t('Update output on line item update.'),
      'group' => t('ERPAL Reports'),
      'parameter' => array(
        'commerce_line_item' => array(
          'type' => 'commerce_line_item',
          'label' => t('Line item'),
        ),
      ),
    ),
  );
}

/**
 * Auto creating money output entities for reports.
 *
 * Used as Rules action callback.
 *
 * @see erpal_reports_rules_action_info()
 */
function erpal_reports_create_money_output($line_item) {
  global $language, $user;

  // Default bundle of output will be revenue.
  $type = 'revenue';

  // Load order.
  $order_id = field_get_items('commerce_line_item', $line_item, 'field_line_item_order');
  if ($order_id) {

    // If customer is own company output should be expense type.
    $order = commerce_order_load($order_id[0]['target_id']);
    $customer_id = field_get_items('commerce_order', $order, 'field_customer');
    $settings = variable_get('erpal_vendor_settings', array());
    if (!empty($settings['vendor_id']) && $settings['vendor_id'] == $customer_id[0]['target_id']) {
      $type = 'expense';
    }
  }

  // Creating manually output entity.
  $output = entity_get_controller('erpal_output')->create();
  $output->title = $line_item->line_item_label;
  $output->type = $type;
  $output->uid = $user->uid;
  $total = commerce_line_items_total(array($line_item));
  $unit = units_unit_machine_name_load(strtolower($total['currency_code']));
  $output->field_output_unit[LANGUAGE_NONE][0] = array(
    'value' => commerce_currency_amount_to_decimal($total['amount'], $total['currency_code']),
    'target_id' => $unit->umid,
  );
  $output->field_output_quantity[LANGUAGE_NONE][0] = array(
    'value' => 1.00,
  );
  $output->field_output_money_refers[LANGUAGE_NONE][0] = array(
    'target_id' => $line_item->line_item_id,
  );

  erpal_output_save($output);
}

/**
 * Delete money output on line item deletetion, and recalculate budget.
 *
 * Used as Rules action callback.
 *
 * @see erpal_reports_rules_action_info()
 */
function erpal_reports_delete_line_item($line_item) {
  $output = erpal_reports_search_output($line_item);
  if (!empty($output)) {
    erpal_output_delete($output);
  }

}

/**
 * Update output on line item update.
 *
 * Used as Rules action callback.
 *
 * @see erpal_reports_rules_action_info()
 */
function erpal_reports_update_line_item($line_item) {
  $output = erpal_reports_search_output($line_item);
  $total = commerce_line_items_total(array($line_item));
  $unit = units_unit_machine_name_load(strtolower($total['currency_code']));

  // Resave data from line item to output.
  $output->field_output_unit[LANGUAGE_NONE][0] = array(
    'value' => commerce_currency_amount_to_decimal($total['amount'], $total['currency_code']),
    'target_id' => $unit->umid,
  );
  erpal_output_save($output);
}
