<?php
/**
 * @file
 * erpal_project_ui.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function erpal_project_ui_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'erpal_project';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'ERPAL Project';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Tasks';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Projects not found.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_date_with_end_ref_target_id']['id'] = 'field_date_with_end_ref_target_id';
  $handler->display->display_options['relationships']['field_date_with_end_ref_target_id']['table'] = 'field_data_field_date_with_end_ref';
  $handler->display->display_options['relationships']['field_date_with_end_ref_target_id']['field'] = 'field_date_with_end_ref_target_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Date item: Date */
  $handler->display->display_options['fields']['field_date_item_with_end']['id'] = 'field_date_item_with_end';
  $handler->display->display_options['fields']['field_date_item_with_end']['table'] = 'field_data_field_date_item_with_end';
  $handler->display->display_options['fields']['field_date_item_with_end']['field'] = 'field_date_item_with_end';
  $handler->display->display_options['fields']['field_date_item_with_end']['relationship'] = 'field_date_with_end_ref_target_id';
  $handler->display->display_options['fields']['field_date_item_with_end']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_project_status']['id'] = 'field_project_status';
  $handler->display->display_options['fields']['field_project_status']['table'] = 'field_data_field_project_status';
  $handler->display->display_options['fields']['field_project_status']['field'] = 'field_project_status';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_project' => 'erpal_project',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'starts';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Date item: Date -  start date (field_date_item_with_end) */
  $handler->display->display_options['filters']['field_date_item_with_end_value']['id'] = 'field_date_item_with_end_value';
  $handler->display->display_options['filters']['field_date_item_with_end_value']['table'] = 'field_data_field_date_item_with_end';
  $handler->display->display_options['filters']['field_date_item_with_end_value']['field'] = 'field_date_item_with_end_value';
  $handler->display->display_options['filters']['field_date_item_with_end_value']['relationship'] = 'field_date_with_end_ref_target_id';
  $handler->display->display_options['filters']['field_date_item_with_end_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_date_item_with_end_value']['expose']['operator_id'] = 'field_date_item_with_end_value_op';
  $handler->display->display_options['filters']['field_date_item_with_end_value']['expose']['label'] = 'Date From';
  $handler->display->display_options['filters']['field_date_item_with_end_value']['expose']['operator'] = 'field_date_item_with_end_value_op';
  $handler->display->display_options['filters']['field_date_item_with_end_value']['expose']['identifier'] = 'field_date_item_with_end_value';
  $handler->display->display_options['filters']['field_date_item_with_end_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_date_item_with_end_value']['form_type'] = 'date_popup';
  /* Filter criterion: Date item: Date - end date (field_date_item_with_end:value2) */
  $handler->display->display_options['filters']['field_date_item_with_end_value2']['id'] = 'field_date_item_with_end_value2';
  $handler->display->display_options['filters']['field_date_item_with_end_value2']['table'] = 'field_data_field_date_item_with_end';
  $handler->display->display_options['filters']['field_date_item_with_end_value2']['field'] = 'field_date_item_with_end_value2';
  $handler->display->display_options['filters']['field_date_item_with_end_value2']['relationship'] = 'field_date_with_end_ref_target_id';
  $handler->display->display_options['filters']['field_date_item_with_end_value2']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_date_item_with_end_value2']['expose']['operator_id'] = 'field_date_item_with_end_value2_op';
  $handler->display->display_options['filters']['field_date_item_with_end_value2']['expose']['label'] = 'Date To';
  $handler->display->display_options['filters']['field_date_item_with_end_value2']['expose']['operator'] = 'field_date_item_with_end_value2_op';
  $handler->display->display_options['filters']['field_date_item_with_end_value2']['expose']['identifier'] = 'field_date_item_with_end_value2';
  $handler->display->display_options['filters']['field_date_item_with_end_value2']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_date_item_with_end_value2']['form_type'] = 'date_popup';
  /* Filter criterion: Content: Status (field_project_status) */
  $handler->display->display_options['filters']['field_project_status_value']['id'] = 'field_project_status_value';
  $handler->display->display_options['filters']['field_project_status_value']['table'] = 'field_data_field_project_status';
  $handler->display->display_options['filters']['field_project_status_value']['field'] = 'field_project_status_value';
  $handler->display->display_options['filters']['field_project_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_status_value']['expose']['operator_id'] = 'field_project_status_value_op';
  $handler->display->display_options['filters']['field_project_status_value']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_project_status_value']['expose']['operator'] = 'field_project_status_value_op';
  $handler->display->display_options['filters']['field_project_status_value']['expose']['identifier'] = 'field_project_status_value';
  $handler->display->display_options['filters']['field_project_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  
  /* Display: Admin */
  $handler = $view->new_display('page', 'Admin', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Projects';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = '@total rows';
  $handler->display->display_options['path'] = 'admin/erpal/projects';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'ERPAL Projects';
  $handler->display->display_options['menu']['weight'] = '10';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  
  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Projects';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = '@total rows';
  $handler->display->display_options['path'] = 'projects';
  $handler->display->display_options['menu']['title'] = 'ERPAL Projects';
  $handler->display->display_options['menu']['weight'] = '10';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  
  /* Display: Tasks */
  $handler = $view->new_display('panel_pane', 'Tasks', 'panel_pane_1');
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'tasks not found.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_date_with_end_ref_target_id']['id'] = 'field_date_with_end_ref_target_id';
  $handler->display->display_options['relationships']['field_date_with_end_ref_target_id']['table'] = 'field_data_field_date_with_end_ref';
  $handler->display->display_options['relationships']['field_date_with_end_ref_target_id']['field'] = 'field_date_with_end_ref_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Date item: Date */
  $handler->display->display_options['fields']['field_date_item_with_end']['id'] = 'field_date_item_with_end';
  $handler->display->display_options['fields']['field_date_item_with_end']['table'] = 'field_data_field_date_item_with_end';
  $handler->display->display_options['fields']['field_date_item_with_end']['field'] = 'field_date_item_with_end';
  $handler->display->display_options['fields']['field_date_item_with_end']['relationship'] = 'field_date_with_end_ref_target_id';
  $handler->display->display_options['fields']['field_date_item_with_end']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_project_status']['id'] = 'field_project_status';
  $handler->display->display_options['fields']['field_project_status']['table'] = 'field_data_field_project_status';
  $handler->display->display_options['fields']['field_project_status']['field'] = 'field_project_status';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_task_type']['id'] = 'field_task_type';
  $handler->display->display_options['fields']['field_task_type']['table'] = 'field_data_field_task_type';
  $handler->display->display_options['fields']['field_task_type']['field'] = 'field_task_type';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Project (field_task_project) */
  $handler->display->display_options['arguments']['field_task_project_target_id']['id'] = 'field_task_project_target_id';
  $handler->display->display_options['arguments']['field_task_project_target_id']['table'] = 'field_data_field_task_project';
  $handler->display->display_options['arguments']['field_task_project_target_id']['field'] = 'field_task_project_target_id';
  $handler->display->display_options['arguments']['field_task_project_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_task_project_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_task_project_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_task_project_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_task' => 'erpal_task',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'starts';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Status (field_task_status) */
  $handler->display->display_options['filters']['field_task_status_value']['id'] = 'field_task_status_value';
  $handler->display->display_options['filters']['field_task_status_value']['table'] = 'field_data_field_task_status';
  $handler->display->display_options['filters']['field_task_status_value']['field'] = 'field_task_status_value';
  $handler->display->display_options['filters']['field_task_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_value']['expose']['operator_id'] = 'field_task_status_value_op';
  $handler->display->display_options['filters']['field_task_status_value']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_task_status_value']['expose']['operator'] = 'field_task_status_value_op';
  $handler->display->display_options['filters']['field_task_status_value']['expose']['identifier'] = 'field_task_status_value';
  $handler->display->display_options['filters']['field_task_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['argument_input'] = array(
    'field_task_project_target_id' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Project (field_task_project)',
    ),
  );
  
  /* Display: Projects by Order */
  $handler = $view->new_display('panel_pane', 'Projects by Order', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Projects';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Order (field_project_order) */
  $handler->display->display_options['arguments']['field_project_order_target_id']['id'] = 'field_project_order_target_id';
  $handler->display->display_options['arguments']['field_project_order_target_id']['table'] = 'field_data_field_project_order';
  $handler->display->display_options['arguments']['field_project_order_target_id']['field'] = 'field_project_order_target_id';
  $handler->display->display_options['arguments']['field_project_order_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_project_order_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_project_order_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_project_order_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['argument_input'] = array(
    'field_project_order_target_id' => array(
      'type' => 'context',
      'context' => 'entity:commerce_order.order-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Order (field_project_order)',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  
  /* Display: Postpaid Tasks */
  $handler = $view->new_display('panel_pane', 'Postpaid Tasks', 'panel_pane_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Postpaid Tasks';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'tasks not found.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_date_with_end_ref_target_id']['id'] = 'field_date_with_end_ref_target_id';
  $handler->display->display_options['relationships']['field_date_with_end_ref_target_id']['table'] = 'field_data_field_date_with_end_ref';
  $handler->display->display_options['relationships']['field_date_with_end_ref_target_id']['field'] = 'field_date_with_end_ref_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_task_line_item_target_id']['id'] = 'field_task_line_item_target_id';
  $handler->display->display_options['relationships']['field_task_line_item_target_id']['table'] = 'field_data_field_task_line_item';
  $handler->display->display_options['relationships']['field_task_line_item_target_id']['field'] = 'field_task_line_item_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_task_payment_modality_target_id']['id'] = 'field_task_payment_modality_target_id';
  $handler->display->display_options['relationships']['field_task_payment_modality_target_id']['table'] = 'field_data_field_task_payment_modality';
  $handler->display->display_options['relationships']['field_task_payment_modality_target_id']['field'] = 'field_task_payment_modality_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Priority */
  $handler->display->display_options['fields']['field_task_priority']['id'] = 'field_task_priority';
  $handler->display->display_options['fields']['field_task_priority']['table'] = 'field_data_field_task_priority';
  $handler->display->display_options['fields']['field_task_priority']['field'] = 'field_task_priority';
  $handler->display->display_options['fields']['field_task_priority']['label'] = '';
  $handler->display->display_options['fields']['field_task_priority']['element_label_colon'] = FALSE;
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_project_status']['id'] = 'field_project_status';
  $handler->display->display_options['fields']['field_project_status']['table'] = 'field_data_field_project_status';
  $handler->display->display_options['fields']['field_project_status']['field'] = 'field_project_status';
  $handler->display->display_options['fields']['field_project_status']['label'] = '';
  $handler->display->display_options['fields']['field_project_status']['element_label_colon'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_task_type']['id'] = 'field_task_type';
  $handler->display->display_options['fields']['field_task_type']['table'] = 'field_data_field_task_type';
  $handler->display->display_options['fields']['field_task_type']['field'] = 'field_task_type';
  $handler->display->display_options['fields']['field_task_type']['label'] = '';
  $handler->display->display_options['fields']['field_task_type']['element_label_colon'] = FALSE;
  /* Field: Date item: Date */
  $handler->display->display_options['fields']['field_date_item_with_end']['id'] = 'field_date_item_with_end';
  $handler->display->display_options['fields']['field_date_item_with_end']['table'] = 'field_data_field_date_item_with_end';
  $handler->display->display_options['fields']['field_date_item_with_end']['field'] = 'field_date_item_with_end';
  $handler->display->display_options['fields']['field_date_item_with_end']['relationship'] = 'field_date_with_end_ref_target_id';
  $handler->display->display_options['fields']['field_date_item_with_end']['label'] = '';
  $handler->display->display_options['fields']['field_date_item_with_end']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_item_with_end']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_date_item_with_end']['format_date_sql'] = 0;
  /* Field: ERPAL payment modality: Amount */
  $handler->display->display_options['fields']['field_amount']['id'] = 'field_amount';
  $handler->display->display_options['fields']['field_amount']['table'] = 'field_data_field_amount';
  $handler->display->display_options['fields']['field_amount']['field'] = 'field_amount';
  $handler->display->display_options['fields']['field_amount']['relationship'] = 'field_task_payment_modality_target_id';
  $handler->display->display_options['fields']['field_amount']['label'] = '';
  $handler->display->display_options['fields']['field_amount']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_amount']['type'] = 'erpal_payment_modality_amount';
  $handler->display->display_options['fields']['field_amount']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Project (field_task_project) */
  $handler->display->display_options['arguments']['field_task_project_target_id']['id'] = 'field_task_project_target_id';
  $handler->display->display_options['arguments']['field_task_project_target_id']['table'] = 'field_data_field_task_project';
  $handler->display->display_options['arguments']['field_task_project_target_id']['field'] = 'field_task_project_target_id';
  $handler->display->display_options['arguments']['field_task_project_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_task_project_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_task_project_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_task_project_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_task' => 'erpal_task',
  );
  /* Filter criterion: Commerce Line item: Unit (field_line_item_unit) */
  $handler->display->display_options['filters']['field_line_item_unit_value']['id'] = 'field_line_item_unit_value';
  $handler->display->display_options['filters']['field_line_item_unit_value']['table'] = 'field_data_field_line_item_unit';
  $handler->display->display_options['filters']['field_line_item_unit_value']['field'] = 'field_line_item_unit_value';
  $handler->display->display_options['filters']['field_line_item_unit_value']['relationship'] = 'field_task_line_item_target_id';
  $handler->display->display_options['filters']['field_line_item_unit_value']['value'] = array(
    'item' => 'item',
  );
  $handler->display->display_options['argument_input'] = array(
    'field_task_project_target_id' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Project (field_task_project)',
    ),
  );
  $translatables['erpal_project'] = array(
    t('Master'),
    t('Tasks'),
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
    t('Projects not found.'),
    t('Date item entity referenced from field_date_with_end_ref'),
    t('Title'),
    t('Date'),
    t('Status'),
    t('Date From'),
    t('Date To'),
    t('Admin'),
    t('Projects'),
    t('@total rows'),
    t('Page'),
    t('tasks not found.'),
    t('Type'),
    t('All'),
    t('View panes'),
    t('Projects by Order'),
    t('Postpaid Tasks'),
    t('Commerce Line item entity referenced from field_task_line_item'),
    t('ERPAL payment modality entity referenced from field_task_payment_modality'),
  );

  $export['erpal_project'] = $view;

  $view = new view();
  $view->name = 'erpal_time_tracking';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'erpal_output';
  $view->human_name = 'ERPAL time tracking';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Time trackings';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'output_id' => 'output_id',
    'field_output_unit' => 'field_output_unit',
    'created' => 'created',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'output_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_output_unit' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Time tracking not created yet..';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: ERPAL output: output ID */
  $handler->display->display_options['fields']['output_id']['id'] = 'output_id';
  $handler->display->display_options['fields']['output_id']['table'] = 'erpal_output';
  $handler->display->display_options['fields']['output_id']['field'] = 'output_id';
  $handler->display->display_options['fields']['output_id']['label'] = '';
  $handler->display->display_options['fields']['output_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['output_id']['element_label_colon'] = FALSE;
  /* Field: ERPAL Output: Unit */
  $handler->display->display_options['fields']['field_output_unit']['id'] = 'field_output_unit';
  $handler->display->display_options['fields']['field_output_unit']['table'] = 'field_data_field_output_unit';
  $handler->display->display_options['fields']['field_output_unit']['field'] = 'field_output_unit';
  $handler->display->display_options['fields']['field_output_unit']['label'] = 'Value';
  $handler->display->display_options['fields']['field_output_unit']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_output_unit']['settings'] = array(
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
  /* Field: ERPAL output: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'erpal_output';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Date';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'edit';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'erpal/output/[output_id]/edit?destination=node/!1';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: ERPAL output: output ID */
  $handler->display->display_options['sorts']['output_id']['id'] = 'output_id';
  $handler->display->display_options['sorts']['output_id']['table'] = 'erpal_output';
  $handler->display->display_options['sorts']['output_id']['field'] = 'output_id';
  $handler->display->display_options['sorts']['output_id']['order'] = 'DESC';
  /* Contextual filter: ERPAL Output: Refers to (field_output_time_refers) */
  $handler->display->display_options['arguments']['field_output_time_refers_target_id']['id'] = 'field_output_time_refers_target_id';
  $handler->display->display_options['arguments']['field_output_time_refers_target_id']['table'] = 'field_data_field_output_time_refers';
  $handler->display->display_options['arguments']['field_output_time_refers_target_id']['field'] = 'field_output_time_refers_target_id';
  $handler->display->display_options['arguments']['field_output_time_refers_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_output_time_refers_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_output_time_refers_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_output_time_refers_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: ERPAL output: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'erpal_output';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'time' => 'time',
  );
  
  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['argument_input'] = array(
    'field_output_time_refers_target_id' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'ERPAL Output: Refers to (field_output_time_refers)',
    ),
  );
  $translatables['erpal_time_tracking'] = array(
    t('Master'),
    t('Time trackings'),
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
    t('Time tracking not created yet..'),
    t('.'),
    t(','),
    t('Value'),
    t('Date'),
    t('edit'),
    t('All'),
    t('Content pane'),
    t('View panes'),
  );

  $export['erpal_time_tracking'] = $view;

  $view = new view();
  $view->name = 'erpal_project_task_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'ERPAL Project, Task Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_project' => 'erpal_project',
    'erpal_task' => 'erpal_task',
  );
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );

  /* Display: Reference dialog Search */
  $handler = $view->new_display('references_dialog', 'Reference dialog Search', 'references_dialog_1');
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['attach'] = array(
    0 => 'erpal_output:field_output_time_refers:time',
  );
  $translatables['erpal_project_task_search'] = array(
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
    t('Nid'),
    t('Title'),
    t('Type'),
    t('Post date'),
    t('Reference dialog Search'),
  );

  $export['erpal_project_task_search'] = $view;

  $view = new view();
  $view->name = 'erpal_project_output';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'erpal_output';
  $view->human_name = 'ERPAL Project Output';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Time Trackings';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Outputs not found.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Bulk operations: ERPAL output */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'erpal_output';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
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
  /* Field: ERPAL output: output ID */
  $handler->display->display_options['fields']['output_id']['id'] = 'output_id';
  $handler->display->display_options['fields']['output_id']['table'] = 'erpal_output';
  $handler->display->display_options['fields']['output_id']['field'] = 'output_id';
  /* Field: ERPAL output: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'erpal_output';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'erpal/output/[output_id]';
  /* Field: ERPAL output: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'erpal_output';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: ERPAL Output: Unit */
  $handler->display->display_options['fields']['field_output_unit']['id'] = 'field_output_unit';
  $handler->display->display_options['fields']['field_output_unit']['table'] = 'field_data_field_output_unit';
  $handler->display->display_options['fields']['field_output_unit']['field'] = 'field_output_unit';
  $handler->display->display_options['fields']['field_output_unit']['label'] = 'Value';
  $handler->display->display_options['fields']['field_output_unit']['settings'] = array(
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
  /* Field: ERPAL output: Date updated */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'erpal_output';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  /* Sort criterion: ERPAL output: output ID */
  $handler->display->display_options['sorts']['output_id']['id'] = 'output_id';
  $handler->display->display_options['sorts']['output_id']['table'] = 'erpal_output';
  $handler->display->display_options['sorts']['output_id']['field'] = 'output_id';
  $handler->display->display_options['sorts']['output_id']['order'] = 'DESC';

  /* Display: Project Time */
  $handler = $view->new_display('panel_pane', 'Project Time', 'panel_pane_3');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_output_time_refers_target_id']['id'] = 'field_output_time_refers_target_id';
  $handler->display->display_options['relationships']['field_output_time_refers_target_id']['table'] = 'field_data_field_output_time_refers';
  $handler->display->display_options['relationships']['field_output_time_refers_target_id']['field'] = 'field_output_time_refers_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: ERPAL output: output ID */
  $handler->display->display_options['fields']['output_id']['id'] = 'output_id';
  $handler->display->display_options['fields']['output_id']['table'] = 'erpal_output';
  $handler->display->display_options['fields']['output_id']['field'] = 'output_id';
  $handler->display->display_options['fields']['output_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['output_id']['element_label_colon'] = FALSE;
  /* Field: ERPAL output: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'erpal_output';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'erpal/output/[output_id]';
  /* Field: ERPAL Output: Unit */
  $handler->display->display_options['fields']['field_output_unit']['id'] = 'field_output_unit';
  $handler->display->display_options['fields']['field_output_unit']['table'] = 'field_data_field_output_unit';
  $handler->display->display_options['fields']['field_output_unit']['field'] = 'field_output_unit';
  $handler->display->display_options['fields']['field_output_unit']['label'] = 'Value';
  $handler->display->display_options['fields']['field_output_unit']['settings'] = array(
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
  /* Field: ERPAL output: Date updated */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'erpal_output';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_output_time_refers_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Task/Project';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'OR',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Project (field_task_project) */
  $handler->display->display_options['filters']['field_task_project_target_id']['id'] = 'field_task_project_target_id';
  $handler->display->display_options['filters']['field_task_project_target_id']['table'] = 'field_data_field_task_project';
  $handler->display->display_options['filters']['field_task_project_target_id']['field'] = 'field_task_project_target_id';
  $handler->display->display_options['filters']['field_task_project_target_id']['relationship'] = 'field_output_time_refers_target_id';
  $handler->display->display_options['filters']['field_task_project_target_id']['value']['value'] = '!1';
  $handler->display->display_options['filters']['field_task_project_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_task_project_target_id']['expose']['operator_id'] = 'field_task_project_target_id_op';
  $handler->display->display_options['filters']['field_task_project_target_id']['expose']['label'] = 'Project (field_task_project)';
  $handler->display->display_options['filters']['field_task_project_target_id']['expose']['operator'] = 'field_task_project_target_id_op';
  $handler->display->display_options['filters']['field_task_project_target_id']['expose']['identifier'] = 'task_project';
  $handler->display->display_options['filters']['field_task_project_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: ERPAL Output: Refers to (field_output_time_refers) */
  $handler->display->display_options['filters']['field_output_time_refers_target_id']['id'] = 'field_output_time_refers_target_id';
  $handler->display->display_options['filters']['field_output_time_refers_target_id']['table'] = 'field_data_field_output_time_refers';
  $handler->display->display_options['filters']['field_output_time_refers_target_id']['field'] = 'field_output_time_refers_target_id';
  $handler->display->display_options['filters']['field_output_time_refers_target_id']['value']['value'] = '!1';
  $handler->display->display_options['filters']['field_output_time_refers_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_output_time_refers_target_id']['expose']['operator_id'] = 'field_output_time_refers_target_id_op';
  $handler->display->display_options['filters']['field_output_time_refers_target_id']['expose']['label'] = 'Refers to (field_output_time_refers)';
  $handler->display->display_options['filters']['field_output_time_refers_target_id']['expose']['operator'] = 'field_output_time_refers_target_id_op';
  $handler->display->display_options['filters']['field_output_time_refers_target_id']['expose']['identifier'] = 'time_refers';
  $handler->display->display_options['filters']['field_output_time_refers_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: ERPAL output: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'erpal_output';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'time' => 'time',
  );
  $handler->display->display_options['filters']['type']['group'] = 2;
  $translatables['erpal_project_output'] = array(
    t('Master'),
    t('Time Trackings'),
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
    t('Outputs not found.'),
    t('ERPAL output'),
    t('- Choose an operation -'),
    t('output ID'),
    t('.'),
    t(','),
    t('Title'),
    t('Type'),
    t('Value'),
    t('Date updated'),
    t('Project Time'),
    t('Content entity referenced from field_output_time_refers'),
    t('Task/Project'),
    t('Project (field_task_project)'),
    t('Refers to (field_output_time_refers)'),
    t('View panes'),
  );

  $export['erpal_project_output'] = $view;

  return $export;
}
