<?php

/**
 * @file
 * Contains edit form for date_item_type.
 */

/**
 * Generates the Date item editing form.
 */
function date_item_type_form($form, &$form_state, $date_item_type, $op = 'edit') {

  if ($op == 'clone') {
    $date_item_type->label .= ' (cloned)';
  }

  $form['label'] = array(
    '#title' => t('Type title'),
    '#type' => 'textfield',
    '#default_value' => $date_item_type->label,
    '#description' => t('The human-readable name of this Date item type.'),
    '#required' => TRUE,
    '#size' => 30,
  );

  $form['machine_name'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($date_item_type->machine_name) ? check_plain($date_item_type->machine_name) : '',
    '#maxlength' => 128,
    '#disabled' => $date_item_type->isLocked() && $op != 'clone',
    '#machine_name' => array(
      'exists' => 'date_item_types',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this Date item type. It must only contain lowercase letters, numbers, and underscores.'),
  );

  $form['description'] = array(
    '#title' => t('Description'),
    '#type' => 'textarea',
    '#default_value' => isset($date_item_type->description) ? check_plain($date_item_type->description) : '',
    '#description' => t('Description about the Date item type.'),
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#weight' => 40,
  );

  if (!$date_item_type->isLocked() && $op != 'add' && $op != 'clone') {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete'),
      '#weight' => 45,
      '#limit_validation_errors' => array(),
      '#submit' => array('date_item_type_form_submit_delete')
    );
  }
  date_item_form_include($form_state, 'admin');

  return $form;
}

/**
 * Validate callback for creating/editing Date item type form.
 */
function date_item_type_form_validate($form, $form_state) {

  if (drupal_strlen($form_state['values']['description']) > 255) {

    form_set_error('description', t('Description field must be a less than 256 chars.'));
  }
}

/**
 * Submit handler for creating/editing Date item type.
 */
function date_item_type_form_submit(&$form, &$form_state) {

  // Save date item type.
  $date_item_type = entity_ui_form_submit_build_entity($form, $form_state);
  date_item_type_save($date_item_type);

  $form_state['redirect'] = DATE_ITEM_ADMIN_PATH;
}

/**
 * Delete form submit handler.
 */
function date_item_type_form_submit_delete($form, &$form_state) {

  // Delete date item type.
  $date_item_type = $form_state['date_item_type'];
  date_item_type_delete($date_item_type);

  drupal_set_message(t('Date item type %title has been deleted.', array('%title' => entity_label('date_item_type', $date_item_type))));

  $form_state['redirect'] = DATE_ITEM_ADMIN_PATH;
}
