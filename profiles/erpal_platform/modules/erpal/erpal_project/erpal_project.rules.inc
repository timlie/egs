<?php

/**
 * @file
 * Rules integration for ERPAL project.
 */

/**
 * Implements hook_rules_action_info().
 */
function erpal_project_rules_action_info() {
  return array(
    'erpal_project_create_acceptance' => array(
      'label' => t('Create acceptance output for projects and tasks.'),
      'group' => t('ERPAL Project'),
      'parameter' => array(
        'node' => array(
          'type' => 'node',
          'label' => t('Node'),
        ),
      ),
    ),
    'erpal_project_create_budgets' => array(
      'label' => t('Create budgets for projects and tasks.'),
      'group' => t('ERPAL Project'),
      'parameter' => array(
        'node' => array(
          'type' => 'node',
          'label' => t('Node'),
        ),
      ),
    ),
    'erpal_project_update' => array(
      'label' => t('Check all data of Project/task on update.'),
      'group' => t('ERPAL Project'),
      'parameter' => array(
        'node' => array(
          'type' => 'node',
          'label' => t('Node'),
        ),
        'node_unchanged' => array(
          'type' => 'node',
          'label' => t('Node Unchanged'),
        ),
      ),
    ),
    'erpal_project_delivery_action' => array(
      'label' => t('Set project or task to delivered or not.'),
      'group' => t('ERPAL Project'),
      'parameter' => array(
        'node' => array(
          'type' => 'node',
          'label' => t('Node'),
        ),
        'node_unchanged' => array(
          'type' => 'node',
          'label' => t('Node'),
        ),
      ),
    ),
    'erpal_project_delete' => array(
      'label' => t('Clear data if project or task was deleted.'),
      'group' => t('ERPAL Project'),
      'parameter' => array(
        'node' => array(
          'type' => 'node',
          'label' => t('Node'),
        ),
      ),
    ),
    'erpal_project_insert_time' => array(
      'label' => t('Check if need create invoice line item on time insert.'),
      'group' => t('ERPAL Project'),
      'parameter' => array(
        'erpal_output' => array(
          'type' => 'erpal_output',
          'label' => t('ERPAL Output'),
        ),
      ),
    ),
    'erpal_project_update_time' => array(
      'label' => t('Check if need create/update invoice line item on time create/update.'),
      'group' => t('ERPAL Project'),
      'parameter' => array(
        'erpal_output' => array(
          'type' => 'erpal_output',
          'label' => t('ERPAL Output'),
        ),
      ),
    ),
    'erpal_project_delete_time' => array(
      'label' => t('Check if need delete invoice line item on time delete.'),
      'group' => t('ERPAL Project'),
      'parameter' => array(
        'erpal_output' => array(
          'type' => 'erpal_output',
          'label' => t('ERPAL Output'),
        ),
      ),
    ),
  );
}

/**
 * Create acceptance output for projects and tasks.
 *
 * Used as Rules action callback.
 *
 * @see erpal_project_rules_action_info()
 */
function erpal_project_create_acceptance($node) {
  global $language, $user;

  // Take fields field_line_item, field_payment_modality from different types.
  list($field_line_item, $field_payment_modality, $field_status, $field_resource) = erpal_project_fields($node);

  // Add logic of creating acceptance output.
  if (!empty($field_line_item) && !empty($field_payment_modality) && !empty($field_resource)) {

    $payment_modality = erpal_payment_modality_load($field_payment_modality[0]['target_id']);
    $line_item = commerce_line_item_load($field_line_item[0]['target_id']);
    $field_unit = field_get_items('commerce_line_item', $line_item, 'field_line_item_unit');
    $field_due_with = field_get_items('erpal_payment_modality', $payment_modality, 'field_due_with');

    if (!empty($field_unit) && $field_unit[0]['value'] == 'item' && !empty($field_due_with) && $field_due_with[0]['value'] == 'delivery') {

      if ($total = erpal_payment_modality_total($payment_modality, $line_item)) {

        // Creating manually output entity.
        $output = entity_get_controller('erpal_output')->create();
        $output->title = $node->title;
        $output->type = 'acceptance';
        $output->uid = $user->uid;
        $unit = units_unit_machine_name_load(strtolower($total['currency_code']));

        $lang = field_language('erpal_output', $output, 'field_output_unit');
        $output->field_output_unit[$lang][0] = array(
          'value' => commerce_currency_amount_to_decimal($total['amount'], $total['currency_code']),
          'target_id' => $unit->umid,
        );

        $lang = field_language('erpal_output', $output, 'field_output_time_refers');
        $output->field_output_time_refers[$lang][0] = array(
          'target_id' => $node->nid,
        );

        $lang = field_language('erpal_output', $output, 'field_resource');
        $output->field_resource[$lang][0] = array(
          'target_id' => $field_resource[0]['target_id'],
        );

        erpal_output_save($output);
      }
    }
  }
}


/**
 * Create budgets for projects and tasks.
 *
 * Used as Rules action callback.
 *
 * @see erpal_project_rules_action_info()
 */
function erpal_project_create_budgets($node) {
  global $language, $user;

  // Take fields field_line_item, field_payment_modality from different types.
  list($field_line_item, $field_payment_modality, $field_status, $field_resource) = erpal_project_fields($node);

  // Add logic of creating budgets.
  if (!empty($field_line_item) && !empty($field_payment_modality) && !empty($field_resource)) {

    $payment_modality = erpal_payment_modality_load($field_payment_modality[0]['target_id']);
    $line_item = commerce_line_item_load($field_line_item[0]['target_id']);
    $field_unit = field_get_items('commerce_line_item', $line_item, 'field_line_item_unit');

    $time = array_keys(erpal_core_units_time());

    if (!empty($field_unit) && in_array($field_unit[0]['value'], $time)) {

      $field_payment_modality = field_get_items('commerce_line_item', $line_item, 'field_payment_modality');
      if (!empty($field_payment_modality)) {
        foreach ($field_payment_modality as $payment_modality_id) {
          $time_payment_modality = erpal_payment_modality_load($payment_modality_id['target_id']);
          $field_amount = field_get_items('erpal_payment_modality', $time_payment_modality, 'field_amount');
          $field_amount_type = field_get_items('erpal_payment_modality', $time_payment_modality, 'field_amount_type');
          $field_due_with = field_get_items('erpal_payment_modality', $time_payment_modality, 'field_due_with');
          if (!empty($field_due_with[0]['value']) && $field_due_with[0]['value'] == 'order') {
            $prepaid_total = erpal_payment_modality_total($time_payment_modality, $line_item);
          }
        }
      }
      $item_total = erpal_payment_modality_total($payment_modality, $line_item);

      // Creating budgets.
      $create_budget = function ($data, $negative, $recource, $type, $total, $available) {
        $prepaid_budget = entity_get_controller('erpal_budget')->create($data);

        $lang = field_language('erpal_budget', $prepaid_budget, 'field_budget_negative');
        $prepaid_budget->field_budget_negative[$lang][0]['value'] = $negative;

        $lang = field_language('erpal_budget', $prepaid_budget, 'field_resource');
        $prepaid_budget->field_resource[$lang][0]['target_id'] = $recource;

        $lang = field_language('erpal_budget', $prepaid_budget, 'field_budget_type');
        $prepaid_budget->field_budget_type[$lang][0]['value'] = $type;

        $lang = field_language('erpal_budget', $prepaid_budget, 'field_budget_available');
        $prepaid_budget->field_budget_total[$lang][0] = $total;
        $prepaid_budget->field_budget_available[$lang][0] = $available;
        erpal_budget_save($prepaid_budget);
      };

      // Create prepaid budget.
      if (!empty($prepaid_total)) {
        $date  = array(
          'type' => 'time',
          'title' => $node->title . ' - prepaid',
        );
        $unit = units_unit_machine_name_load(strtolower($field_unit[0]['value']));
        $budget_total = array(
          'value' => $prepaid_total['amount'] / $item_total['amount'],
          'target_id' => $unit->umid,
        );
        $create_budget($date, 0, $field_resource[0]['target_id'], 'prepaid', $budget_total, $budget_total);
      }

      // Create postpaid budget.
      $total = commerce_line_items_total(array($line_item));
      if (!empty($prepaid_total)) {
        $total['amount'] = $total['amount'] - $prepaid_total['amount'];
      }
      $date  = array(
        'type' => 'time',
        'title' => $node->title . ' - postpaid',
      );
      $unit = units_unit_machine_name_load(strtolower($field_unit[0]['value']));
      $budget_total = array(
        'value' => $total['amount'] / $item_total['amount'],
        'target_id' => $unit->umid,
      );
      $create_budget($date, 0, $field_resource[0]['target_id'], 'postpaid', $budget_total, $budget_total);
    }
  }
}


/**
 * Set project or task to delivered or not.
 *
 * Used as Rules action callback.
 *
 * @see erpal_project_rules_action_info()
 */
function erpal_project_delivery_action($node, $node_unchanged) {
  global $language, $user;

  // Take fields field_line_item, field_payment_modality from different types.
  list($field_line_item, $field_payment_modality, $field_status, $field_resource) = erpal_project_fields($node);
  if (!empty($field_line_item[0]['target_id']) && !empty($field_payment_modality[0]['target_id'])) {
    switch ($node->type) {
      case 'erpal_task':
        $old_field_status = field_get_items('node', $node_unchanged, 'field_task_status');
        break;

      case 'erpal_project':
        $old_field_status = field_get_items('node', $node_unchanged, 'field_project_status');
        break;

    }

    // Set project or task to not delivered.
    if ((empty($field_status[0]['value']) || $field_status[0]['value'] != 'delivered')) {
      erpal_project_delete($node);
    }

    // Set project or task to delivered.
    if ((empty($old_field_status[0]['value']) || $old_field_status[0]['value'] != 'delivered') && (!empty($field_status[0]['value']) && $field_status[0]['value'] == 'delivered')) {
      $payment_modality = erpal_payment_modality_load($field_payment_modality[0]['target_id']);
      $line_item = commerce_line_item_load($field_line_item[0]['target_id']);
      $field_unit = field_get_items('commerce_line_item', $line_item, 'field_line_item_unit');
      $field_due_with = field_get_items('erpal_payment_modality', $payment_modality, 'field_due_with');

      if (!empty($field_unit) && $field_unit[0]['value'] == 'item' && !empty($field_due_with) && $field_due_with[0]['value'] == 'delivery') {

        // Set acceptance output to delivered.
        erpal_project_delivery($payment_modality, $line_item, $field_resource[0]['target_id']);

        // Load line item order properties.
        $order = erpal_project_get_order_properties($line_item->order_id);

        // Create invoice line item.
        erpal_payment_modality_create_line_item($payment_modality, $line_item, $order);
      }
    }
  }
}

/**
 * Check all data of Project/task on update.
 *
 * Used as Rules action callback.
 *
 * @see erpal_project_rules_action_info()
 */
function erpal_project_update($node, $node_unchanged) {

  // Take fields field_line_item, field_payment_modality from different types.
  list($field_line_item, $field_payment_modality, $field_status, $field_resource) = erpal_project_fields($node);

  if (empty($field_line_item[0]['target_id']) || empty($field_payment_modality[0]['target_id'])) {
    erpal_project_delete($node);
    return;
  }

  // Take fields field_line_item, field_payment_modality from different types.
  list($old_field_line_item, $old_field_payment_modality, $old_field_status, $old_field_resource) = erpal_project_fields($node_unchanged);

  if ((empty($old_field_line_item[0]['target_id']) || empty($old_field_payment_modality[0]['target_id']))
      || ($old_field_line_item[0]['target_id'] != $field_line_item[0]['target_id']
      || $old_field_payment_modality[0]['target_id'] != $field_payment_modality[0]['target_id'])) {
    erpal_project_delete($node);
    erpal_project_create_acceptance($node);
    erpal_project_create_budgets($node);
  }
}

/**
 * Delete invoice line item and set acceptance output to not delivered.
 *
 * Used as Rules action callback.
 *
 * @see erpal_project_rules_action_info()
 */
function erpal_project_delete($node) {
  global $language, $user;

  // Take fields field_line_item, field_payment_modality from different types.
  list($field_line_item, $field_payment_modality, $field_status, $field_resource) = erpal_project_fields($node);
  if (!empty($field_line_item[0]['target_id']) && !empty($field_payment_modality[0]['target_id'])) {
    $payment_modality = erpal_payment_modality_load($field_payment_modality[0]['target_id']);
    $line_item = commerce_line_item_load($field_line_item[0]['target_id']);
    // Set acceptance output to not delivered.
    erpal_project_delivery($payment_modality, $line_item, $field_resource[0]['target_id'], FALSE);

    // Load line item order properties.
    $order = erpal_project_get_order_properties($line_item->order_id);

    // Generate label for invoice line item.
    $invoice_label = erpal_payment_modality_generate_label($payment_modality, $line_item, $order);

    // Load invoice line items.
    $conditions = array(
      'line_item_label' => $invoice_label,
      'type' => 'invoice',
    );
    $invoice = commerce_line_item_load_multiple(array(), $conditions, TRUE);
    if (!empty($invoice)) {
      $invoice = reset($invoice);

      // If invoice line item already added to invoice nothing to do
      // here.
      if ($invoice->order_id != $order['order_id']) {
        return;
      }
      commerce_line_item_delete($invoice->line_item_id);
    }
  }

}


/**
 * Check if need create invoice line item on time insert.
 *
 * @see erpal_project_rules_action_info()
 */
function erpal_project_insert_time($output) {
  $refers = field_get_items('erpal_output', $output, 'field_output_time_refers');
  $field_resource = field_get_items('erpal_output', $output, 'field_resource');

  if (erpal_project_time_output_is_billable($output) && !empty($refers[0]['target_id']) && !empty($field_resource[0]['target_id'])) {
    $resource = erpal_resource_load($field_resource[0]['target_id']);
    $node = node_load($resource->source_id);

    // Take fields field_line_item, field_payment_modality from different types.
    list($field_line_item, $field_payment_modality, $field_status, $field_resource) = erpal_project_fields($node, TRUE);
    if (!empty($field_line_item) && !empty($field_payment_modality) && !empty($field_resource)) {
      $payment_modality = erpal_payment_modality_load($field_payment_modality[0]['target_id']);
      $line_item = commerce_line_item_load($field_line_item[0]['target_id']);
      $field_unit = field_get_items('commerce_line_item', $line_item, 'field_line_item_unit');
      $field_output_unit = field_get_items('erpal_output', $output, 'field_output_unit');
      $time = array_keys(erpal_core_units_time());

      if (!empty($field_unit) && in_array($field_unit[0]['value'], $time)) {

        $budgets = field_get_items('erpal_output', $output, 'field_output_budget');

        if (!empty($budgets)) {
          $value = 0;
          foreach ($budgets as $budget_data) {
            if (!empty($budget_data['target_id'])) {
              $budget = erpal_budget_load($budget_data['target_id']);
              $budget_type = field_get_items('erpal_budget', $budget, 'field_budget_type');

              // Colect value from postpaid budgets.
              if (empty($budget_type) || (!empty($budget_type) && $budget_type[0]['value'] == 'postpaid')) {
                $value += $budget_data['value'];
              }
            }
          }

          // If we have any value in postpaid budget need create invoice line
          // item.
          if ($value) {

             // Load line item order properties.
            $order = erpal_project_get_order_properties($line_item->order_id);
  
            $output_unit = units_unit_load($field_output_unit[0]['target_id']);
            $unit = units_convert($value,
                  $output_unit->machine_name, $field_unit[0]['value']);
  
            // Create invoice line item.
            $label = erpal_payment_modality_generate_label($payment_modality, $line_item, $order);
            $label = t('!labelx!unit !time',
              array(
                '!label' => $label,
                '!unit' => $unit,
                '!time' => format_plural($unit, $field_unit[0]['value'], $field_unit[0]['value'] . 's')
              )
            );
            $invoice = erpal_payment_modality_create_line_item($payment_modality, $line_item, $order, FALSE, $label, $unit, FALSE);
  
            // This field is hidden and field_language can return false.
            $lang = field_language('erpal_output', $output, 'field_output_line_item');
            if (!$lang) {
              $lang = LANGUAGE_NONE;
            }
  
            $output->field_output_line_item[$lang][0]['target_id'] = $invoice->line_item_id;
  
            $lang = field_language('erpal_output', $output, 'field_output_delivered');
            $output->field_output_delivered[$lang][0]['value'] = 1;
          }
        }
      }
    }
  }
}

/**
 * Check if need create/update invoice line item on time create/update.
 *
 * @see erpal_project_rules_action_info()
 */
function erpal_project_update_time($output) {

  // Delete old invoice line item.
  erpal_project_delete_time($output);

  // Add new invoice line item.
  erpal_project_insert_time($output);
}

/**
 * Check if need delete invoice line item on time delete.
 *
 * @see erpal_project_rules_action_info()
 */
function erpal_project_delete_time($output) {
  $field_output_line_item = field_get_items('erpal_output', $output, 'field_output_line_item');
  if (!empty($field_output_line_item) && !empty($field_output_line_item[0]['target_id'])) {
    $line_item = commerce_line_item_load($field_output_line_item[0]['target_id']);
    $field_line_item_order = field_get_items('commerce_line_item', $line_item, 'field_line_item_order');

    // If invoice line item already added to invoice nothing to do
    // here.
    if ($line_item->order_id != $field_line_item_order[0]['target_id']) {
      return;
    }

    // Delete invoice line item.
    commerce_line_item_delete($line_item->line_item_id);

    // Delete reference to not existing entity.
    $output->field_output_line_item = array();
  }
}
