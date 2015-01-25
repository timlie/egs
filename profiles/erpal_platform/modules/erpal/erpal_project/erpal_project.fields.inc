<?php

/**
 * @file
 * Adds fields to the task and project entity types used by ERPAL PM.
 */


/**
 * Define the default fields for the ERPAL task and project entity types.
 */
function _erpal_project_default_fields() {
  $fields = array();

  // Exported field_base: 'body'
  $fields['erpal_task'][] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'node',
    ),
    'field_name' => 'body',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_with_summary',
  );

  // Exported field_base: 'field_date_with_end_ref'
  $fields['erpal_task'][] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_date_with_end_ref',
    'foreign keys' => array(
      'date_item' => array(
        'columns' => array(
          'target_id' => 'diid',
        ),
        'table' => 'date_item',
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
          0 => 'with_end',
        ),
      ),
      'target_type' => 'date_item',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_project_budget_view'
  $fields['erpal_task'][] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_project_budget_view',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'viewfield',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'viewfield',
  );

  // Exported field_base: 'field_task_parent'
  $fields['erpal_task'][] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_task_parent',
    'foreign keys' => array(
      'node' => array(
        'columns' => array(
          'target_id' => 'nid',
        ),
        'table' => 'node',
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
          'erpal_task' => 'erpal_task',
        ),
      ),
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_task_priority'
  $fields['erpal_task'][] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_task_priority',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'high' => 'high',
        'middle' => 'middle',
        'low' => 'low',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_task_project'
  $fields['erpal_task'][] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_task_project',
    'foreign keys' => array(
      'node' => array(
        'columns' => array(
          'target_id' => 'nid',
        ),
        'table' => 'node',
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
          'erpal_project' => 'erpal_project',
        ),
      ),
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_task_status'
  $fields['erpal_task'][] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_task_status',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'ready to start' => 'ready to start',
        'in progress' => 'in progress',
        'ready to test' => 'ready to test',
        'test failed' => 'test failed',
        'test passed' => 'test passed',
        'delivered' => 'delivered',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_task_type'
  $fields['erpal_task'][] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_task_type',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'bug' => 'bug',
        'task' => 'task',
        'feature request' => 'feature request',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_task_line_item'
  $fields['erpal_task'][] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_task_line_item',
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
          'product' => 'product',
        ),
      ),
      'target_type' => 'commerce_line_item',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_task_line_item'
  $fields['erpal_task'][] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_task_payment_modality',
    'foreign keys' => array(
      'erpal_payment_modality' => array(
        'columns' => array(
          'target_id' => 'payment_modality_id',
        ),
        'table' => 'erpal_payment_modality',
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
          'payment_modality' => 'payment_modality',
        ),
      ),
      'target_type' => 'erpal_payment_modality',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_project_status'
  $fields['erpal_project'][] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_project_status',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'stopped' => 'stopped',
        'in progress' => 'in progress',
        'delivered' => 'delivered',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_project_order'
  $fields['erpal_project'][] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_project_order',
    'foreign keys' => array(
      'commerce_order' => array(
        'columns' => array(
          'target_id' => 'order_id',
        ),
        'table' => 'commerce_order',
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
          'commerce_order' => 'commerce_order',
        ),
      ),
      'target_type' => 'commerce_order',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_project_line_item'
  $fields['erpal_project'][] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_project_line_item',
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
          'product' => 'product',
        ),
      ),
      'target_type' => 'commerce_line_item',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_project_payment_modality'
  $fields['erpal_project'][] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_project_payment_modality',
    'foreign keys' => array(
      'erpal_payment_modality' => array(
        'columns' => array(
          'target_id' => 'payment_modality_id',
        ),
        'table' => 'erpal_payment_modality',
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
          'payment_modality' => 'payment_modality',
        ),
      ),
      'target_type' => 'erpal_payment_modality',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_project_postpaid_tasks'
  $fields['erpal_project'][] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_project_postpaid_tasks',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'viewfield',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'viewfield',
  );

  return $fields;
}

/**
 * Defines default field instances for the ERPAL task and project entity types.
 */
function _erpal_project_default_field_instances() {
  $instances = array();

  // Exported field_instance: 'node-erpal_task-field_project_budget_view'
  $instances['erpal_task'][] = array(
    'bundle' => 'erpal_task',
    'default_value' => array(
      0 => array(
        'vname' => 'erpal_project_budget|page',
        'vargs' => '',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'viewfield',
        'settings' => array(),
        'type' => 'viewfield_default',
        'weight' => 17,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'viewfield',
        'settings' => array(),
        'type' => 'viewfield_default',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_project_budget_view',
    'label' => 'Budget Widget',
    'required' => 0,
    'settings' => array(
      'allowed_views' => array(
        'charts_demo' => 0,
        'commerce_customer_profiles' => 0,
        'commerce_line_item_table' => 0,
        'commerce_order_revisions' => 0,
        'commerce_orders' => 0,
        'commerce_product_revisions' => 0,
        'commerce_products' => 0,
        'commerce_reports_taxes' => 0,
        'commerce_user_orders' => 0,
        'erpal_activity_search' => 0,
        'erpal_budget' => 0,
        'erpal_contact_search' => 0,
        'erpal_crm_activities' => 0,
        'erpal_crm_contact_relationships' => 0,
        'erpal_crm_contacts' => 0,
        'erpal_customer_profile' => 0,
        'erpal_invoice' => 0,
        'erpal_invoice_line_items' => 0,
        'erpal_invoice_reports' => 0,
        'erpal_line_items' => 0,
        'erpal_order' => 0,
        'erpal_order_search' => 0,
        'erpal_output' => 0,
        'erpal_payment_modality' => 0,
        'erpal_products' => 0,
        'erpal_project' => 0,
        'erpal_project_budget' => 'erpal_project_budget',
        'erpal_project_line_item_dfv' => 0,
        'erpal_project_output' => 0,
        'erpal_project_payment_modality_dfv' => 0,
        'erpal_project_reference' => 0,
        'erpal_project_task_search' => 0,
        'erpal_quote' => 0,
        'erpal_quote_reports' => 0,
        'erpal_quote_search' => 0,
        'erpal_reports_basic' => 0,
        'erpal_resource' => 0,
        'erpal_time_tracking' => 0,
      ),
      'dfv' => array(
        'parent' => '',
        'status' => 0,
        'view' => '',
      ),
      'force_default' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'viewfield',
      'settings' => array(),
      'type' => 'viewfield_select',
      'weight' => 34,
    ),
  );

  // Exported field_instance: 'node-erpal_task-body'
  $instances['erpal_task'][] = array(
    'bundle' => 'erpal_task',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 9,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Description',
    'required' => 0,
    'settings' => array(
      'display_summary' => 0,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-erpal_task-field_date_with_end_ref'
  $instances['erpal_task'][] = array(
    'bundle' => 'erpal_task',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'links' => TRUE,
          'view_mode' => 'default',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 4,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'links' => TRUE,
          'view_mode' => 'default',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_date_with_end_ref',
    'label' => 'Date',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'inline_entity_form',
      'settings' => array(
        'fields' => array(),
        'type_settings' => array(
          'allow_existing' => FALSE,
          'delete_references' => 0,
          'label_plural' => 'entities',
          'label_singular' => 'entity',
          'match_operator' => 'CONTAINS',
          'override_labels' => 0,
        ),
      ),
      'type' => 'inline_entity_form_single',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-erpal_task-field_task_parent'
  $instances['erpal_task'][] = array(
    'bundle' => 'erpal_task',
    'default_value' => NULL,
    'default_value_function' => 'entityreference_prepopulate_field_default_value',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'links' => TRUE,
          'view_mode' => 'default',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 2,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_task_parent',
    'label' => 'Parent task',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'action' => 'none',
          'action_on_edit' => 0,
          'fallback' => 'none',
          'providers' => array(
            'og_context' => FALSE,
            'url' => 1,
          ),
          'skip_perm' => 0,
          'status' => 1,
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
        'match_operator' => 'STARTS_WITH',
        'path' => '',
        'references_dialog_add' => 0,
        'references_dialog_delete' => 0,
        'references_dialog_edit' => 0,
        'references_dialog_search' => 0,
        'references_dialog_search_view' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-erpal_task-field_task_priority'
  $instances['erpal_task'][] = array(
    'bundle' => 'erpal_task',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 5,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_task_priority',
    'label' => 'Priority',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-erpal_task-field_task_project'
  $instances['erpal_task'][] = array(
    'bundle' => 'erpal_task',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'links' => 1,
          'view_mode' => 'reference',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'links' => 1,
          'view_mode' => 'reference',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_task_project',
    'label' => 'Project',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'STARTS_WITH',
        'path' => '',
        'references_dialog_add' => 0,
        'references_dialog_delete' => 0,
        'references_dialog_edit' => 0,
        'references_dialog_search' => 0,
        'references_dialog_search_view' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-erpal_task-field_task_status'
  $instances['erpal_task'][] = array(
    'bundle' => 'erpal_task',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 3,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_task_status',
    'label' => 'Status',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-erpal_task-field_task_type'
  $instances['erpal_task'][] =  array(
    'bundle' => 'erpal_task',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 1,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_task_type',
    'label' => 'Type',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-erpal_task-field_task_line_item'
  $instances['erpal_task'][] = array(
    'bundle' => 'erpal_task',
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
        'weight' => 10,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_task_line_item',
    'label' => 'Line item',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'dfv' => array(
        'parent' => 'field_task_project',
        'status' => 1,
        'view' => 'erpal_project_line_item_dfv:dfv_2',
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 31,
    ),
  );

  // Exported field_instance: 'node-erpal_task-field_task_payment_modality'
  $instances['erpal_task'][] = array(
    'bundle' => 'erpal_task',
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
        'weight' => 11,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 11,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_task_payment_modality',
    'label' => 'Payment modality',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'dfv' => array(
        'parent' => 'field_task_line_item',
        'status' => 1,
        'view' => 'erpal_project_payment_modality_dfv:dfv_1',
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 32,
    ),
  );

  // Exported field_instance: 'node-erpal_project-body'
  $instances['erpal_project'][] = array(
    'bundle' => 'erpal_project',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'reference' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Description',
    'required' => 0,
    'settings' => array(
      'display_summary' => 0,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-erpal_project-field_date_with_end_ref'
  $instances['erpal_project'][] = array(
    'bundle' => 'erpal_project',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'links' => TRUE,
          'view_mode' => 'default',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 1,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'links' => TRUE,
          'view_mode' => 'default',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 1,
      ),
      'reference' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_date_with_end_ref',
    'label' => 'Date',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'inline_entity_form',
      'settings' => array(
        'fields' => array(),
        'type_settings' => array(
          'allow_existing' => FALSE,
          'delete_references' => 0,
          'label_plural' => 'entities',
          'label_singular' => 'entity',
          'match_operator' => 'CONTAINS',
          'override_labels' => 0,
        ),
      ),
      'type' => 'inline_entity_form_single',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-erpal_project-field_project_status'
  $instances['erpal_project'][] = array(
    'bundle' => 'erpal_project',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 0,
      ),
      'reference' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_project_status',
    'label' => 'Status',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-erpal_project-field_project_order'
  $instances['erpal_project'][] = array(
    'bundle' => 'erpal_project',
    'default_value' => NULL,
    'default_value_function' => 'entityreference_prepopulate_field_default_value',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => TRUE,
        ),
        'type' => 'entityreference_label',
        'weight' => 7,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => TRUE,
        ),
        'type' => 'entityreference_label',
        'weight' => 6,
      ),
      'reference' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_project_order',
    'label' => 'Order',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'action' => 'none',
          'action_on_edit' => 0,
          'fallback' => 'none',
          'providers' => array(
            'og_context' => FALSE,
            'url' => 1,
          ),
          'skip_perm' => 0,
          'status' => 1,
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
        'references_dialog_delete' => 0,
        'references_dialog_edit' => 0,
        'references_dialog_search' => 0,
        'references_dialog_search_view' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 32,
    ),
  );

  // Exported field_instance: 'node-erpal_project-field_project_line_item'
  $instances['erpal_project'][] = array(
    'bundle' => 'erpal_project',
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
        'weight' => 8,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 7,
      ),
      'reference' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_project_line_item',
    'label' => 'Line item',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'dfv' => array(
        'parent' => 'field_project_order',
        'status' => 1,
        'view' => 'erpal_project_line_item_dfv:dfv_1',
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'references_dialog_add' => 0,
        'references_dialog_edit' => 0,
        'references_dialog_search' => 0,
        'references_dialog_search_view' => '',
        'size' => 60,
      ),
      'type' => 'options_select',
      'weight' => 33,
    ),
  );

  // Exported field_instance: 'node-erpal_project-field_project_payment_modality'
  $instances['erpal_project'][] = array(
    'bundle' => 'erpal_project',
    'default_value' => NULL,
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
        'weight' => 9,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 8,
      ),
      'reference' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_project_payment_modality',
    'label' => 'Payment modality',
    'required' => FALSE,
    'settings' => array(
      'dfv' => array(
        'parent' => 'field_project_line_item',
        'status' => 1,
        'view' => 'erpal_project_payment_modality_dfv:dfv_1',
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'options',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'references_dialog_add' => 0,
        'references_dialog_edit' => 0,
        'references_dialog_search' => 0,
        'references_dialog_search_view' => '',
        'size' => 60,
      ),
      'type' => 'options_select',
      'weight' => 34,
    ),
  );

  // Exported field_instance: 'node-erpal_project-field_project_budget_view'
  $instances['erpal_project'][] = array(
    'bundle' => 'erpal_project',
    'default_value' => array(
      0 => array(
        'vname' => 'erpal_project_budget|page',
        'vargs' => '',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'viewfield',
        'settings' => array(),
        'type' => 'viewfield_default',
        'weight' => 17,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'viewfield',
        'settings' => array(),
        'type' => 'viewfield_default',
        'weight' => 5,
      ),
      'reference' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_project_budget_view',
    'label' => 'Budget Widget',
    'required' => 0,
    'settings' => array(
      'allowed_views' => array(
        'charts_demo' => 0,
        'commerce_customer_profiles' => 0,
        'commerce_line_item_table' => 0,
        'commerce_order_revisions' => 0,
        'commerce_orders' => 0,
        'commerce_product_revisions' => 0,
        'commerce_products' => 0,
        'commerce_reports_taxes' => 0,
        'commerce_user_orders' => 0,
        'erpal_activity_search' => 0,
        'erpal_budget' => 0,
        'erpal_contact_search' => 0,
        'erpal_crm_activities' => 0,
        'erpal_crm_contact_relationships' => 0,
        'erpal_crm_contacts' => 0,
        'erpal_customer_profile' => 0,
        'erpal_invoice' => 0,
        'erpal_invoice_line_items' => 0,
        'erpal_invoice_reports' => 0,
        'erpal_line_items' => 0,
        'erpal_order' => 0,
        'erpal_order_search' => 0,
        'erpal_output' => 0,
        'erpal_payment_modality' => 0,
        'erpal_products' => 0,
        'erpal_project' => 0,
        'erpal_project_budget' => 'erpal_project_budget',
        'erpal_project_line_item_dfv' => 0,
        'erpal_project_output' => 0,
        'erpal_project_payment_modality_dfv' => 0,
        'erpal_project_reference' => 0,
        'erpal_project_task_search' => 0,
        'erpal_quote' => 0,
        'erpal_quote_reports' => 0,
        'erpal_quote_search' => 0,
        'erpal_reports_basic' => 0,
        'erpal_resource' => 0,
        'erpal_time_tracking' => 0,
      ),
      'dfv' => array(
        'parent' => '',
        'status' => 0,
        'view' => '',
      ),
      'force_default' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'viewfield',
      'settings' => array(),
      'type' => 'viewfield_select',
      'weight' => 36,
    ),
  );

  // Exported field_instance: 'node-erpal_project-field_project_postpaid_tasks'
  $instances['erpal_project'][] = array(
    'bundle' => 'erpal_project',
    'default_value' => array(
      0 => array(
        'vname' => 'erpal_project|panel_pane_3',
        'vargs' => '[node:nid]',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'viewfield',
        'settings' => array(),
        'type' => 'viewfield_default',
        'weight' => 18,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'viewfield',
        'settings' => array(),
        'type' => 'viewfield_default',
        'weight' => 10,
      ),
      'reference' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_project_postpaid_tasks',
    'label' => 'Postpaid Tasks',
    'required' => 0,
    'settings' => array(
      'allowed_views' => array(
        'charts_demo' => 0,
        'commerce_customer_profiles' => 0,
        'commerce_line_item_table' => 0,
        'commerce_order_revisions' => 0,
        'commerce_orders' => 0,
        'commerce_product_revisions' => 0,
        'commerce_products' => 0,
        'commerce_reports_taxes' => 0,
        'commerce_user_orders' => 0,
        'erpal_activity_search' => 0,
        'erpal_budget' => 0,
        'erpal_contact_search' => 0,
        'erpal_crm_activities' => 0,
        'erpal_crm_contact_relationships' => 0,
        'erpal_crm_contacts' => 0,
        'erpal_customer_profile' => 0,
        'erpal_invoice' => 0,
        'erpal_invoice_line_items' => 0,
        'erpal_invoice_reports' => 0,
        'erpal_line_items' => 0,
        'erpal_order' => 0,
        'erpal_order_search' => 0,
        'erpal_output' => 0,
        'erpal_payment_modality' => 0,
        'erpal_products' => 0,
        'erpal_project' => 'erpal_project',
        'erpal_project_budget' => 0,
        'erpal_project_line_item_dfv' => 0,
        'erpal_project_output' => 0,
        'erpal_project_payment_modality_dfv' => 0,
        'erpal_project_reference' => 0,
        'erpal_project_task_search' => 0,
        'erpal_quote' => 0,
        'erpal_quote_reports' => 0,
        'erpal_quote_search' => 0,
        'erpal_reports_basic' => 0,
        'erpal_resource' => 0,
        'erpal_time_tracking' => 0,
      ),
      'dfv' => array(
        'parent' => '',
        'status' => 0,
        'view' => '',
      ),
      'force_default' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'viewfield',
      'settings' => array(),
      'type' => 'viewfield_select',
      'weight' => 37,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Body');
  t('Date');
  t('Description');
  t('Parent task');
  t('Priority');
  t('Project');
  t('Status');
  t('Type');

  return $instances;
}


/**
 * Define fields for the report functionality for output entity.
 *
 * @return array
 *   Return default fields and instances.
 *
 * @see field_create_field()
 * @see field_create_instance()
 */
function erpal_project_output_fields() {
  $fields = array();
  $instances = array();

  // Exported field_base: 'field_output_time_refers'
  $fields[] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_output_time_refers',
    'foreign keys' => array(
      'node' => array(
        'columns' => array(
          'target_id' => 'nid',
        ),
        'table' => 'node',
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
          'erpal_project' => 'erpal_project',
          'erpal_task' => 'erpal_task',
        ),
      ),
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_output_line_item'
  $fields[] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_output_line_item',
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

  // Exported field_base: 'field_output_billable'
  $fields[] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_output_billable',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_instance: 'erpal_output-time-field_output_time_refers'
  $instances[] = array(
    'bundle' => 'time',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 19,
      ),
    ),
    'entity_type' => 'erpal_output',
    'field_name' => 'field_output_time_refers',
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
        'references_dialog_add' => 1,
        'references_dialog_edit' => 1,
        'references_dialog_search' => 1,
        'references_dialog_search_view' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'erpal_output-time-field_output_time_refers'
  $instances[] = array(
    'bundle' => 'acceptance',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 19,
      ),
    ),
    'entity_type' => 'erpal_output',
    'field_name' => 'field_output_time_refers',
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

  // Exported field_instance: 'erpal_output-time-field_output_line_item'
  $instances[] = array(
    'bundle' => 'time',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 20,
      ),
    ),
    'entity_type' => 'erpal_output',
    'field_name' => 'field_output_line_item',
    'label' => 'Invoice line Item',
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
      'module' => 'field_extrawidgets',
      'settings' => array(),
      'type' => 'field_extrawidgets_hidden',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'erpal_output-time-field_output_billable'
  $instances[] = array(
    'bundle' => 'time',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 21,
      ),
    ),
    'entity_type' => 'erpal_output',
    'field_name' => 'field_output_billable',
    'label' => 'Billable',
    'required' => 0,
    'settings' => array(
      'dfv' => array(
        'parent' => '',
        'status' => 0,
        'view' => '',
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 8,
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

/**
 * Define fields for budget entity.
 *
 * @return array
 *   Return default fields and instances.
 *
 * @see field_create_field()
 * @see field_create_instance()
 */
function erpal_project_budget_fields() {
  $fields = array();
  $instances = array();

  // Exported field_base: 'field_budget_type'
  $fields[] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_budget_type',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'prepaid' => 'Prepaid',
        'postpaid' => 'Postpaid',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_budget_reference_view'
  $fields[] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_budget_reference_view',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'viewfield',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'viewfield',
  );

  // Exported field_instance: 'erpal_budget-time-field_budget_type'
  $instances[] = array(
    'bundle' => 'time',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 17,
      ),
    ),
    'entity_type' => 'erpal_budget',
    'field_name' => 'field_budget_type',
    'label' => 'Type',
    'required' => 0,
    'settings' => array(
      'dfv' => array(
        'parent' => '',
        'status' => 0,
        'view' => '',
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'erpal_budget-money-field_budget_reference_view'
  $instances[] = array(
    'bundle' => 'money',
    'default_value' => array(
      0 => array(
        'vname' => 'erpal_project_reference|panel_pane_1',
        'vargs' => '[current-page:url:args:value:2]',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'viewfield',
        'settings' => array(),
        'type' => 'viewfield_default',
        'weight' => 17,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'viewfield',
        'settings' => array(),
        'type' => 'viewfield_default',
        'weight' => 1,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'erpal_budget',
    'field_name' => 'field_budget_reference_view',
    'label' => 'Reference',
    'required' => 0,
    'settings' => array(
      'allowed_views' => array(
        'bub' => 0,
        'charts_demo' => 0,
        'commerce_customer_profiles' => 0,
        'commerce_line_item_table' => 0,
        'commerce_order_revisions' => 0,
        'commerce_orders' => 0,
        'commerce_product_revisions' => 0,
        'commerce_products' => 0,
        'commerce_reports_taxes' => 0,
        'commerce_user_orders' => 0,
        'erpal_activity_search' => 0,
        'erpal_budget' => 0,
        'erpal_contact_search' => 0,
        'erpal_crm_activities' => 0,
        'erpal_crm_contact_relationships' => 0,
        'erpal_crm_contacts' => 0,
        'erpal_customer_profile' => 0,
        'erpal_invoice' => 0,
        'erpal_invoice_line_items' => 0,
        'erpal_invoice_reports' => 0,
        'erpal_line_items' => 0,
        'erpal_order' => 0,
        'erpal_order_search' => 0,
        'erpal_output' => 0,
        'erpal_payment_modality' => 0,
        'erpal_products' => 0,
        'erpal_project' => 0,
        'erpal_project_budget' => 0,
        'erpal_project_line_item_dfv' => 0,
        'erpal_project_output' => 0,
        'erpal_project_payment_modality_dfv' => 0,
        'erpal_project_reference' => 'erpal_project_reference',
        'erpal_project_task_search' => 0,
        'erpal_quote' => 0,
        'erpal_quote_reports' => 0,
        'erpal_quote_search' => 0,
        'erpal_reports_basic' => 0,
        'erpal_resource' => 0,
        'erpal_time_tracking' => 0,
      ),
      'dfv' => array(
        'parent' => '',
        'status' => 0,
        'view' => '',
      ),
      'force_default' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'viewfield',
      'settings' => array(),
      'type' => 'viewfield_select',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'erpal_budget-time-field_budget_reference_view'
  $instances[] = array(
    'bundle' => 'time',
    'default_value' => array(
      0 => array(
        'vname' => 'erpal_project_reference|panel_pane_1',
        'vargs' => '[current-page:url:args:value:2]',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'viewfield',
        'settings' => array(),
        'type' => 'viewfield_default',
        'weight' => 6,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'viewfield',
        'settings' => array(),
        'type' => 'viewfield_default',
        'weight' => 1,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'erpal_budget',
    'field_name' => 'field_budget_reference_view',
    'label' => 'Reference',
    'required' => 0,
    'settings' => array(
      'allowed_views' => array(
        'charts_demo' => 0,
        'commerce_customer_profiles' => 0,
        'commerce_line_item_table' => 0,
        'commerce_order_revisions' => 0,
        'commerce_orders' => 0,
        'commerce_product_revisions' => 0,
        'commerce_products' => 0,
        'commerce_reports_taxes' => 0,
        'commerce_user_orders' => 0,
        'erpal_activity_search' => 0,
        'erpal_budget' => 0,
        'erpal_contact_search' => 0,
        'erpal_crm_activities' => 0,
        'erpal_crm_contact_relationships' => 0,
        'erpal_crm_contacts' => 0,
        'erpal_customer_profile' => 0,
        'erpal_invoice' => 0,
        'erpal_invoice_line_items' => 0,
        'erpal_invoice_reports' => 0,
        'erpal_line_items' => 0,
        'erpal_order' => 0,
        'erpal_order_search' => 0,
        'erpal_output' => 0,
        'erpal_payment_modality' => 0,
        'erpal_products' => 0,
        'erpal_project' => 0,
        'erpal_project_budget' => 0,
        'erpal_project_line_item_dfv' => 0,
        'erpal_project_output' => 0,
        'erpal_project_payment_modality_dfv' => 0,
        'erpal_project_reference' => 'erpal_project_reference',
        'erpal_project_task_search' => 0,
        'erpal_quote' => 0,
        'erpal_quote_reports' => 0,
        'erpal_quote_search' => 0,
        'erpal_reports_basic' => 0,
        'erpal_resource' => 0,
        'erpal_time_tracking' => 0,
      ),
      'dfv' => array(
        'parent' => '',
        'status' => 0,
        'view' => '',
      ),
      'force_default' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'viewfield',
      'settings' => array(),
      'type' => 'viewfield_select',
      'weight' => 6,
    ),
  );

  return array(
    'fields' => $fields,
    'instances' => $instances,
  );
}
