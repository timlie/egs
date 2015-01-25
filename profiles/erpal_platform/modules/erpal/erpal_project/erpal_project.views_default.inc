<?php
/**
 * @file
 * erpal_project.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function erpal_project_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'erpal_project_payment_modality_dfv';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'erpal_payment_modality';
  $view->human_name = 'Erpal Project Payment modality dfv';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_payment_modality_commerce_line_item']['id'] = 'reverse_field_payment_modality_commerce_line_item';
  $handler->display->display_options['relationships']['reverse_field_payment_modality_commerce_line_item']['table'] = 'erpal_payment_modality';
  $handler->display->display_options['relationships']['reverse_field_payment_modality_commerce_line_item']['field'] = 'reverse_field_payment_modality_commerce_line_item';
  /* Field: ERPAL payment modality: Payment modality ID */
  $handler->display->display_options['fields']['payment_modality_id']['id'] = 'payment_modality_id';
  $handler->display->display_options['fields']['payment_modality_id']['table'] = 'erpal_payment_modality';
  $handler->display->display_options['fields']['payment_modality_id']['field'] = 'payment_modality_id';
  $handler->display->display_options['fields']['payment_modality_id']['label'] = '';
  $handler->display->display_options['fields']['payment_modality_id']['element_label_colon'] = FALSE;
  /* Field: ERPAL payment modality: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'erpal_payment_modality';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Contextual filter: Commerce Line Item: Line item ID */
  $handler->display->display_options['arguments']['line_item_id']['id'] = 'line_item_id';
  $handler->display->display_options['arguments']['line_item_id']['table'] = 'commerce_line_item';
  $handler->display->display_options['arguments']['line_item_id']['field'] = 'line_item_id';
  $handler->display->display_options['arguments']['line_item_id']['relationship'] = 'reverse_field_payment_modality_commerce_line_item';
  $handler->display->display_options['arguments']['line_item_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['line_item_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['line_item_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['line_item_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['line_item_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: ERPAL payment modality: Due with (field_due_with) */
  $handler->display->display_options['filters']['field_due_with_value']['id'] = 'field_due_with_value';
  $handler->display->display_options['filters']['field_due_with_value']['table'] = 'field_data_field_due_with';
  $handler->display->display_options['filters']['field_due_with_value']['field'] = 'field_due_with_value';
  $handler->display->display_options['filters']['field_due_with_value']['value'] = array(
    'delivery' => 'delivery',
  );
  
  /* Display: Dependend Field Values */
  $handler = $view->new_display('dfv', 'Dependend Field Values', 'dfv_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'dfv_style';
  $handler->display->display_options['style_options']['title_field'] = 'title';
  $handler->display->display_options['style_options']['key_field'] = 'payment_modality_id';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'dfv_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $translatables['erpal_project_payment_modality_dfv'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Commerce Line item referencing ERPAL payment modality from field_payment_modality'),
    t('.'),
    t(','),
    t('All'),
    t('Dependend Field Values'),
  );

  $export['erpal_project_line_item_dfv'] = $view;

  $view = new view();
  $view->name = 'erpal_project_payment_modality_dfv';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'erpal_payment_modality';
  $view->human_name = 'Erpal Project Payment modality dfv';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_payment_modality_commerce_line_item']['id'] = 'reverse_field_payment_modality_commerce_line_item';
  $handler->display->display_options['relationships']['reverse_field_payment_modality_commerce_line_item']['table'] = 'erpal_payment_modality';
  $handler->display->display_options['relationships']['reverse_field_payment_modality_commerce_line_item']['field'] = 'reverse_field_payment_modality_commerce_line_item';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_task_payment_modality_node']['id'] = 'reverse_field_task_payment_modality_node';
  $handler->display->display_options['relationships']['reverse_field_task_payment_modality_node']['table'] = 'erpal_payment_modality';
  $handler->display->display_options['relationships']['reverse_field_task_payment_modality_node']['field'] = 'reverse_field_task_payment_modality_node';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_project_payment_modality_node']['id'] = 'reverse_field_project_payment_modality_node';
  $handler->display->display_options['relationships']['reverse_field_project_payment_modality_node']['table'] = 'erpal_payment_modality';
  $handler->display->display_options['relationships']['reverse_field_project_payment_modality_node']['field'] = 'reverse_field_project_payment_modality_node';
  /* Field: ERPAL payment modality: Payment modality ID */
  $handler->display->display_options['fields']['payment_modality_id']['id'] = 'payment_modality_id';
  $handler->display->display_options['fields']['payment_modality_id']['table'] = 'erpal_payment_modality';
  $handler->display->display_options['fields']['payment_modality_id']['field'] = 'payment_modality_id';
  $handler->display->display_options['fields']['payment_modality_id']['label'] = '';
  $handler->display->display_options['fields']['payment_modality_id']['element_label_colon'] = FALSE;
  /* Field: ERPAL payment modality: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'erpal_payment_modality';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Contextual filter: Commerce Line Item: Line item ID */
  $handler->display->display_options['arguments']['line_item_id']['id'] = 'line_item_id';
  $handler->display->display_options['arguments']['line_item_id']['table'] = 'commerce_line_item';
  $handler->display->display_options['arguments']['line_item_id']['field'] = 'line_item_id';
  $handler->display->display_options['arguments']['line_item_id']['relationship'] = 'reverse_field_payment_modality_commerce_line_item';
  $handler->display->display_options['arguments']['line_item_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['line_item_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['line_item_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['line_item_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['line_item_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: ERPAL payment modality: Due with (field_due_with) */
  $handler->display->display_options['filters']['field_due_with_value']['id'] = 'field_due_with_value';
  $handler->display->display_options['filters']['field_due_with_value']['table'] = 'field_data_field_due_with';
  $handler->display->display_options['filters']['field_due_with_value']['field'] = 'field_due_with_value';
  $handler->display->display_options['filters']['field_due_with_value']['value'] = array(
    'delivery' => 'delivery',
  );
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['relationship'] = 'reverse_field_task_payment_modality_node';
  $handler->display->display_options['filters']['nid']['operator'] = 'empty';
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['filters']['nid_1']['table'] = 'node';
  $handler->display->display_options['filters']['nid_1']['field'] = 'nid';
  $handler->display->display_options['filters']['nid_1']['relationship'] = 'reverse_field_project_payment_modality_node';
  $handler->display->display_options['filters']['nid_1']['operator'] = 'empty';
  
  /* Display: Dependend Field Values */
  $handler = $view->new_display('dfv', 'Dependend Field Values', 'dfv_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'dfv_style';
  $handler->display->display_options['style_options']['title_field'] = 'title';
  $handler->display->display_options['style_options']['key_field'] = 'payment_modality_id';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'dfv_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $translatables['erpal_project_payment_modality_dfv'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Commerce Line item referencing ERPAL payment modality from field_payment_modality'),
    t('Content referencing ERPAL payment modality from field_task_payment_modality'),
    t('Content referencing ERPAL payment modality from field_project_payment_modality'),
    t('.'),
    t(','),
    t('All'),
    t('Dependend Field Values'),
  );

  $export['erpal_project_payment_modality_dfv'] = $view;

  /* erpal project budget */
  $view = new view();
  $view->name = 'erpal_project_budget';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'erpal_budget';
  $view->human_name = 'ERPAL Project Budget';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Controlling';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['wrapper_class'] = 'budget-item';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_resource_target_id']['id'] = 'field_resource_target_id';
  $handler->display->display_options['relationships']['field_resource_target_id']['table'] = 'field_data_field_resource';
  $handler->display->display_options['relationships']['field_resource_target_id']['field'] = 'field_resource_target_id';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_resource_node']['id'] = 'reverse_field_resource_node';
  $handler->display->display_options['relationships']['reverse_field_resource_node']['table'] = 'erpal_resource';
  $handler->display->display_options['relationships']['reverse_field_resource_node']['field'] = 'reverse_field_resource_node';
  $handler->display->display_options['relationships']['reverse_field_resource_node']['relationship'] = 'field_resource_target_id';
  /* Field: ERPAL budget: budget ID */
  $handler->display->display_options['fields']['budget_id']['id'] = 'budget_id';
  $handler->display->display_options['fields']['budget_id']['table'] = 'erpal_budget';
  $handler->display->display_options['fields']['budget_id']['field'] = 'budget_id';
  $handler->display->display_options['fields']['budget_id']['label'] = '';
  $handler->display->display_options['fields']['budget_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['budget_id']['element_label_colon'] = FALSE;
  /* Field: ERPAL budget: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'erpal_budget';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: ERPAL Budget: Available */
  $handler->display->display_options['fields']['field_budget_available']['id'] = 'field_budget_available';
  $handler->display->display_options['fields']['field_budget_available']['table'] = 'field_data_field_budget_available';
  $handler->display->display_options['fields']['field_budget_available']['field'] = 'field_budget_available';
  $handler->display->display_options['fields']['field_budget_available']['label'] = '';
  $handler->display->display_options['fields']['field_budget_available']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_budget_available']['type'] = 'erpal_budget_formatter_default';
  $handler->display->display_options['fields']['field_budget_available']['settings'] = array(
    'unit' => array(
      'formatter' => 'entityreference_label',
      'link' => 0,
    ),
    'value' => array(
      'formatter' => 'number_decimal',
      'thousand_separator' => ' ',
      'decimal_separator' => '.',
      'scale' => '2',
      'prefix_suffix' => 1,
    ),
    'mvf' => array(
      'unit_suggester_settings' => array(
        'MVFUnitSuggesterLocale' => array(
          'en' => '-1',
          'weight' => '-10',
          'enable' => 0,
        ),
        'MVFUnitSuggesterHardCoded' => array(
          'unit' => '1',
          'weight' => '-10',
          'enable' => 0,
        ),
        'MVFUnitSuggesterOriginal' => array(
          'weight' => '-10',
          'enable' => 0,
        ),
      ),
    ),
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_resource_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: ERPAL budget: Date updated */
  $handler->display->display_options['filters']['changed']['id'] = 'changed';
  $handler->display->display_options['filters']['changed']['table'] = 'erpal_budget';
  $handler->display->display_options['filters']['changed']['field'] = 'changed';
  $handler->display->display_options['filters']['changed']['expose']['operator_id'] = 'changed_op';
  $handler->display->display_options['filters']['changed']['expose']['label'] = 'Date updated';
  $handler->display->display_options['filters']['changed']['expose']['operator'] = 'changed_op';
  $handler->display->display_options['filters']['changed']['expose']['identifier'] = 'changed';
  /* Filter criterion: ERPAL budget: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'erpal_budget';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  
  /* Display: Widget */
  $handler = $view->new_display('page', 'Widget', 'page');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'Controlling:';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: ERPAL budget: budget ID */
  $handler->display->display_options['fields']['budget_id']['id'] = 'budget_id';
  $handler->display->display_options['fields']['budget_id']['table'] = 'erpal_budget';
  $handler->display->display_options['fields']['budget_id']['field'] = 'budget_id';
  $handler->display->display_options['fields']['budget_id']['label'] = '';
  $handler->display->display_options['fields']['budget_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['budget_id']['element_label_colon'] = FALSE;
  /* Field: ERPAL budget: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'erpal_budget';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'erpal/budget/[budget_id]';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: ERPAL Budget: Available */
  $handler->display->display_options['fields']['field_budget_available']['id'] = 'field_budget_available';
  $handler->display->display_options['fields']['field_budget_available']['table'] = 'field_data_field_budget_available';
  $handler->display->display_options['fields']['field_budget_available']['field'] = 'field_budget_available';
  $handler->display->display_options['fields']['field_budget_available']['label'] = '';
  $handler->display->display_options['fields']['field_budget_available']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_budget_available']['type'] = 'erpal_budget_formatter_default';
  $handler->display->display_options['fields']['field_budget_available']['settings'] = array(
    'unit' => array(
      'formatter' => 'entityreference_label',
      'link' => 0,
    ),
    'value' => array(
      'formatter' => 'number_decimal',
      'thousand_separator' => ' ',
      'decimal_separator' => '.',
      'scale' => '2',
      'prefix_suffix' => 1,
    ),
    'mvf' => array(
      'unit_suggester_settings' => array(
        'MVFUnitSuggesterLocale' => array(
          'en' => '-1',
          'weight' => '-10',
          'enable' => 0,
        ),
        'MVFUnitSuggesterHardCoded' => array(
          'unit' => '1',
          'weight' => '-10',
          'enable' => 0,
        ),
        'MVFUnitSuggesterOriginal' => array(
          'weight' => '-10',
          'enable' => 0,
        ),
      ),
    ),
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $handler->display->display_options['path'] = 'erpal-project-budget';
  
  /* Display: Table */
  $handler = $view->new_display('panel_pane', 'Table', 'panel_pane_1');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['row_class'] = 'budget-row';
  $handler->display->display_options['style_options']['columns'] = array(
    'budget_id' => 'budget_id',
    'field_budget_available_2' => 'field_budget_available_2',
    'title' => 'title',
    'field_budget_available' => 'field_budget_available',
    'field_budget_total' => 'field_budget_total',
    'field_budget_type' => 'field_budget_type',
    'changed' => 'changed',
    'nothing' => 'nothing',
    'views_bulk_operations' => 'views_bulk_operations',
  );
  $handler->display->display_options['style_options']['default'] = 'field_budget_available';
  $handler->display->display_options['style_options']['info'] = array(
    'budget_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_budget_available_2' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_budget_available' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_budget_total' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_budget_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'views_bulk_operations' => array(
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No budgets found';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: ERPAL budget: budget ID */
  $handler->display->display_options['fields']['budget_id']['id'] = 'budget_id';
  $handler->display->display_options['fields']['budget_id']['table'] = 'erpal_budget';
  $handler->display->display_options['fields']['budget_id']['field'] = 'budget_id';
  $handler->display->display_options['fields']['budget_id']['label'] = '';
  $handler->display->display_options['fields']['budget_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['budget_id']['element_label_colon'] = FALSE;
  /* Field: ERPAL Budget: Available */
  $handler->display->display_options['fields']['field_budget_available_2']['id'] = 'field_budget_available_2';
  $handler->display->display_options['fields']['field_budget_available_2']['table'] = 'field_data_field_budget_available';
  $handler->display->display_options['fields']['field_budget_available_2']['field'] = 'field_budget_available';
  $handler->display->display_options['fields']['field_budget_available_2']['label'] = 'Widget';
  $handler->display->display_options['fields']['field_budget_available_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_budget_available_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_budget_available_2']['type'] = 'erpal_budget_formatter_default';
  $handler->display->display_options['fields']['field_budget_available_2']['settings'] = array(
    'unit' => array(
      'formatter' => 'entityreference_label',
      'link' => 0,
    ),
    'value' => array(
      'formatter' => 'number_decimal',
      'thousand_separator' => ' ',
      'decimal_separator' => '.',
      'scale' => '2',
      'prefix_suffix' => 1,
    ),
    'mvf' => array(
      'unit_suggester_settings' => array(
        'MVFUnitSuggesterLocale' => array(
          'en' => '-1',
          'weight' => '-10',
          'enable' => 0,
        ),
        'MVFUnitSuggesterHardCoded' => array(
          'unit' => '1',
          'weight' => '-10',
          'enable' => 0,
        ),
        'MVFUnitSuggesterOriginal' => array(
          'weight' => '-10',
          'enable' => 0,
        ),
      ),
    ),
  );
  /* Field: ERPAL budget: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'erpal_budget';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Budget';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'erpal/budget/[budget_id]';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: ERPAL Budget: Available */
  $handler->display->display_options['fields']['field_budget_available']['id'] = 'field_budget_available';
  $handler->display->display_options['fields']['field_budget_available']['table'] = 'field_data_field_budget_available';
  $handler->display->display_options['fields']['field_budget_available']['field'] = 'field_budget_available';
  $handler->display->display_options['fields']['field_budget_available']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_budget_available']['settings'] = array(
    'unit' => array(
      'formatter' => 'entityreference_label',
      'link' => 0,
    ),
    'value' => array(
      'formatter' => 'number_decimal',
      'thousand_separator' => ' ',
      'decimal_separator' => '.',
      'scale' => '2',
      'prefix_suffix' => 1,
    ),
    'mvf' => array(
      'unit_suggester_settings' => array(
        'MVFUnitSuggesterLocale' => array(
          'en' => '-1',
          'weight' => '-10',
          'enable' => 0,
        ),
        'MVFUnitSuggesterHardCoded' => array(
          'unit' => '1',
          'weight' => '-10',
          'enable' => 0,
        ),
        'MVFUnitSuggesterOriginal' => array(
          'weight' => '-10',
          'enable' => 0,
        ),
      ),
    ),
  );
  /* Field: ERPAL Budget: Total */
  $handler->display->display_options['fields']['field_budget_total']['id'] = 'field_budget_total';
  $handler->display->display_options['fields']['field_budget_total']['table'] = 'field_data_field_budget_total';
  $handler->display->display_options['fields']['field_budget_total']['field'] = 'field_budget_total';
  $handler->display->display_options['fields']['field_budget_total']['settings'] = array(
    'unit' => array(
      'formatter' => 'entityreference_label',
      'link' => 0,
    ),
    'value' => array(
      'formatter' => 'number_decimal',
      'thousand_separator' => ' ',
      'decimal_separator' => '.',
      'scale' => '2',
      'prefix_suffix' => 1,
    ),
    'mvf' => array(
      'unit_suggester_settings' => array(
        'MVFUnitSuggesterLocale' => array(
          'en' => '-1',
          'weight' => '-10',
          'enable' => 0,
        ),
        'MVFUnitSuggesterHardCoded' => array(
          'unit' => '1',
          'weight' => '-10',
          'enable' => 0,
        ),
        'MVFUnitSuggesterOriginal' => array(
          'weight' => '-10',
          'enable' => 0,
        ),
      ),
    ),
  );
  /* Field: ERPAL Budget: Type */
  $handler->display->display_options['fields']['field_budget_type']['id'] = 'field_budget_type';
  $handler->display->display_options['fields']['field_budget_type']['table'] = 'field_data_field_budget_type';
  $handler->display->display_options['fields']['field_budget_type']['field'] = 'field_budget_type';
  /* Field: ERPAL Budget Revisions: Date updated */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'erpal_budget_revision';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Last updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'raw time ago';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'year';
  $handler->display->display_options['fields']['changed']['format_date_sql'] = 0;
  /* Field: ERPAL budget: Actions */
  $handler->display->display_options['fields']['erpal_entity_actions_1']['id'] = 'erpal_entity_actions_1';
  $handler->display->display_options['fields']['erpal_entity_actions_1']['table'] = 'erpal_budget';
  $handler->display->display_options['fields']['erpal_entity_actions_1']['field'] = 'erpal_entity_actions';
  $handler->display->display_options['fields']['erpal_entity_actions_1']['label'] = '';
  $handler->display->display_options['fields']['erpal_entity_actions_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['erpal_entity_actions_1']['alter']['text'] = '[erpal_entity_actions_1]
    [field_budget_available_2]';
  $handler->display->display_options['fields']['erpal_entity_actions_1']['element_label_colon'] = FALSE;
  /* Field: Bulk operations: ERPAL budget */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'erpal_budget';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_revision' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: ERPAL budget: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'erpal_budget';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Budget';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: ERPAL Budget: Type (field_budget_type) */
  $handler->display->display_options['filters']['field_budget_type_value']['id'] = 'field_budget_type_value';
  $handler->display->display_options['filters']['field_budget_type_value']['table'] = 'field_data_field_budget_type';
  $handler->display->display_options['filters']['field_budget_type_value']['field'] = 'field_budget_type_value';
  $handler->display->display_options['filters']['field_budget_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_budget_type_value']['expose']['operator_id'] = 'field_budget_type_value_op';
  $handler->display->display_options['filters']['field_budget_type_value']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_budget_type_value']['expose']['operator'] = 'field_budget_type_value_op';
  $handler->display->display_options['filters']['field_budget_type_value']['expose']['identifier'] = 'field_budget_type_value';
  $handler->display->display_options['filters']['field_budget_type_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['link_to_view'] = '0';
  $translatables['erpal_project_budget'] = array(
    t('Master'),
    t('Controlling'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('ERPAL Resource entity referenced from field_resource'),
    t('Content referencing ERPAL Resource from field_resource'),
    t('.'),
    t(','),
    t('Custom text'),
    t('All'),
    t('Date updated'),
    t('Widget'),
    t('Controlling:'),
    t('Table'),
    t('No budgets found'),
    t('Budget'),
    t('Available'),
    t('Total'),
    t('Type'),
    t('Last updated'),
    t('[erpal_entity_actions_1]
    [field_budget_available_2]'),
    t('- Choose an operation -'),
    t('View panes'),
  );

  $export['erpal_project_budget'] = $view;


  /* erpal project reference */
  $view = new view();
  $view->name = 'erpal_project_reference';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'ERPAL Project Reference';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'ERPAL Project Reference';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_resource_target_id']['id'] = 'field_resource_target_id';
  $handler->display->display_options['relationships']['field_resource_target_id']['table'] = 'field_data_field_resource';
  $handler->display->display_options['relationships']['field_resource_target_id']['field'] = 'field_resource_target_id';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_resource_erpal_budget']['id'] = 'reverse_field_resource_erpal_budget';
  $handler->display->display_options['relationships']['reverse_field_resource_erpal_budget']['table'] = 'erpal_resource';
  $handler->display->display_options['relationships']['reverse_field_resource_erpal_budget']['field'] = 'reverse_field_resource_erpal_budget';
  $handler->display->display_options['relationships']['reverse_field_resource_erpal_budget']['relationship'] = 'field_resource_target_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: ERPAL budget: budget ID */
  $handler->display->display_options['arguments']['budget_id']['id'] = 'budget_id';
  $handler->display->display_options['arguments']['budget_id']['table'] = 'erpal_budget';
  $handler->display->display_options['arguments']['budget_id']['field'] = 'budget_id';
  $handler->display->display_options['arguments']['budget_id']['relationship'] = 'reverse_field_resource_erpal_budget';
  $handler->display->display_options['arguments']['budget_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['budget_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['budget_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['budget_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Project by Budget */
  $handler = $view->new_display('panel_pane', 'Project by Budget', 'panel_pane_1');
  $translatables['erpal_project_reference'] = array(
    t('Master'),
    t('ERPAL Project Reference'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('ERPAL Resource entity referenced from field_resource'),
    t('ERPAL Budget referencing ERPAL Resource from field_resource'),
    t('All'),
    t('Project by Budget'),
    t('View panes'),
  );
  $export['erpal_project_reference'] = $view;

  return $export;
}
