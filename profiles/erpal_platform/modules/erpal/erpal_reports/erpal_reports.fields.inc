<?php

/**
 * @file
 * Contains default fields/instances for report functionality.
 */

/**
 * Define the default fields for the report functionality.
 *
 * @return array
 *   Return default fields and instances to be attached to invoice.
 *
 * @see field_create_field()
 * @see field_create_instance()
 */
function erpal_reports_default_fields() {
  $fields = array();
  $instances = array();

  // Exported field_base: 'field_output_money_refers'
  $fields[] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_output_money_refers',
    'foreign keys' => array(
      'commerce_line_item' => array(
        'columns' => array(
          'target_id' => 'line_item_id',
        ),
        'table' => 'commerce_line_item',
      ),
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'invoice' => 'invoice',
        ),
      ),
      'target_type' => 'commerce_line_item',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_instance: 'erpal_output-expense-field_output_money_refers'
  $instances[] = array(
    'bundle' => 'expense',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 19,
      ),
    ),
    'entity_type' => 'erpal_output',
    'field_name' => 'field_output_money_refers',
    'label' => 'Refers to',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'dfv' => array(
        'parent' => '',
        'status' => 0,
        'view' => '',
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'references_dialog_add' => 0,
        'references_dialog_edit' => 0,
        'references_dialog_search' => 0,
        'references_dialog_search_view' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'erpal_output-revenue-field_output_money_refers'
  $instances[] = array(
    'bundle' => 'revenue',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 19,
      ),
    ),
    'entity_type' => 'erpal_output',
    'field_name' => 'field_output_money_refers',
    'label' => 'Refers to',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'dfv' => array(
        'parent' => '',
        'status' => 0,
        'view' => '',
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'references_dialog_add' => 0,
        'references_dialog_edit' => 0,
        'references_dialog_search' => 0,
        'references_dialog_search_view' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 7,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Refers to');

  return array(
    'fields' => $fields,
    'instances' => $instances,
  );
}
