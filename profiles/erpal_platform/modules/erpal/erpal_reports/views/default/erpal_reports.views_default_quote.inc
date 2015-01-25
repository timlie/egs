<?php

/**
 * @file
 * Views for the ERPAL Order report.
 */

/**
 * Implements hook_views_default_views().
 */
function _erpal_reports_views_default_quote() {
  $view = new view();
  $view->name = 'erpal_quote_reports';
  $view->description = '';
  $view->tag = 'ERPAL, report';
  $view->base_table = 'commerce_order';
  $view->human_name = 'ERPAL Quote reports';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Ingoing';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view erpal reports';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'chart';
  $handler->display->display_options['style_options']['type'] = 'column';
  $handler->display->display_options['style_options']['library'] = '';
  $handler->display->display_options['style_options']['label_field'] = 'field_date_item_single';
  $handler->display->display_options['style_options']['data_fields'] = array(
    'commerce_order_total' => 'commerce_order_total',
    'field_date_item_single' => 0,
  );
  $handler->display->display_options['style_options']['field_colors'] = array(
    'commerce_order_total' => '#8bbc21',
    'field_date_item_single' => '#0d233a',
  );
  $handler->display->display_options['style_options']['title'] = 'Ingoing report';
  $handler->display->display_options['style_options']['width'] = '1000';
  $handler->display->display_options['style_options']['height'] = '200';
  $handler->display->display_options['style_options']['xaxis_labels_rotation'] = '30';
  $handler->display->display_options['style_options']['yaxis_labels_rotation'] = '0';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No data by given parameters';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Date item */
  $handler->display->display_options['relationships']['field_valid_until_target_id']['id'] = 'field_valid_until_target_id';
  $handler->display->display_options['relationships']['field_valid_until_target_id']['table'] = 'field_data_field_valid_until';
  $handler->display->display_options['relationships']['field_valid_until_target_id']['field'] = 'field_valid_until_target_id';
  $handler->display->display_options['relationships']['field_valid_until_target_id']['ui_name'] = 'Date item';
  $handler->display->display_options['relationships']['field_valid_until_target_id']['label'] = 'Date item';
  /* Field: SUM(Commerce Order: Order total) */
  $handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['group_type'] = 'sum';
  $handler->display->display_options['fields']['commerce_order_total']['label'] = 'EUR';
  $handler->display->display_options['fields']['commerce_order_total']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_order_total']['type'] = 'erpal_reports_decimal';
  $handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
    'calculation' => FALSE,
  );
  $handler->display->display_options['fields']['commerce_order_total']['group_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_order_total']['group_columns'] = array(
    'currency_code' => 'currency_code',
  );
  /* Field: Date item: Date */
  $handler->display->display_options['fields']['field_date_item_single']['id'] = 'field_date_item_single';
  $handler->display->display_options['fields']['field_date_item_single']['table'] = 'field_data_field_date_item_single';
  $handler->display->display_options['fields']['field_date_item_single']['field'] = 'field_date_item_single';
  $handler->display->display_options['fields']['field_date_item_single']['relationship'] = 'field_valid_until_target_id';
  $handler->display->display_options['fields']['field_date_item_single']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_item_single']['settings'] = array(
    'format_type' => 'month',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_date_item_single']['format_date_sql'] = 1;
  /* Sort criterion: MIN(Date item: Date (field_date_item_single)) */
  $handler->display->display_options['sorts']['field_date_item_single_value']['id'] = 'field_date_item_single_value';
  $handler->display->display_options['sorts']['field_date_item_single_value']['table'] = 'field_data_field_date_item_single';
  $handler->display->display_options['sorts']['field_date_item_single_value']['field'] = 'field_date_item_single_value';
  $handler->display->display_options['sorts']['field_date_item_single_value']['relationship'] = 'field_valid_until_target_id';
  $handler->display->display_options['sorts']['field_date_item_single_value']['group_type'] = 'min';
  /* Filter criterion: Date item: Date (field_date_item_single) */
  $handler->display->display_options['filters']['field_date_item_single_value']['id'] = 'field_date_item_single_value';
  $handler->display->display_options['filters']['field_date_item_single_value']['table'] = 'field_data_field_date_item_single';
  $handler->display->display_options['filters']['field_date_item_single_value']['field'] = 'field_date_item_single_value';
  $handler->display->display_options['filters']['field_date_item_single_value']['relationship'] = 'field_valid_until_target_id';
  $handler->display->display_options['filters']['field_date_item_single_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_date_item_single_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_date_item_single_value']['expose']['operator_id'] = 'field_date_item_single_value_op';
  $handler->display->display_options['filters']['field_date_item_single_value']['expose']['operator'] = 'field_date_item_single_value_op';
  $handler->display->display_options['filters']['field_date_item_single_value']['expose']['identifier'] = 'ingoing_date';
  $handler->display->display_options['filters']['field_date_item_single_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_date_item_single_value']['form_type'] = 'date_popup';
  /* Filter criterion: Commerce Order: Order status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    'feedback' => 'feedback',
    'declined' => 'declined',
    'accepted' => 'accepted',
  );
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'ingoing_status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['status']['expose']['reduce'] = TRUE;
  /* Filter criterion: Commerce Order: Payment type */
  $handler->display->display_options['filters']['payment_type']['id'] = 'payment_type';
  $handler->display->display_options['filters']['payment_type']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['payment_type']['field'] = 'payment_type';
  $handler->display->display_options['filters']['payment_type']['value'] = 'ingoing';
  /* Filter criterion: Global: Exposed date format */
  $handler->display->display_options['filters']['date_format']['id'] = 'date_format';
  $handler->display->display_options['filters']['date_format']['table'] = 'views';
  $handler->display->display_options['filters']['date_format']['field'] = 'date_format';
  $handler->display->display_options['filters']['date_format']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_format']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['date_format']['expose']['label'] = 'Scale';
  $handler->display->display_options['filters']['date_format']['expose']['operator'] = 'date_format_op';
  $handler->display->display_options['filters']['date_format']['expose']['identifier'] = 'ingoing_date_format';
  $handler->display->display_options['filters']['date_format']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['date_format']['expose']['remember_roles'] = array(
    2 => 0,
    0 => 0,
    1 => 0,
  );
  $handler->display->display_options['filters']['date_format']['date_field'] = 'field_date_item_single';
  $handler->display->display_options['filters']['date_format']['date_formats'] = array(
    'month' => 'month',
    'year' => 'year',
  );
  /* Filter criterion: Commerce Order: Order type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'quote' => 'quote',
  );
  
  /* Display: Ingoing */
  $handler = $view->new_display('panel_pane', 'Ingoing', 'ingoing_pane');
  $handler->display->display_options['pane_category']['name'] = 'ERPAL reports';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['inherit_panels_path'] = '1';
  
  /* Display: Ingoing attachment */
  $handler = $view->new_display('attachment', 'Ingoing attachment', 'ingoing_attachment');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Summary';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_date_item_single' => 'field_date_item_single',
    'commerce_order_total' => 'commerce_order_total',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_date_item_single' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_order_total' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h2>Summary</h2>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Date item: Date */
  $handler->display->display_options['fields']['field_date_item_single']['id'] = 'field_date_item_single';
  $handler->display->display_options['fields']['field_date_item_single']['table'] = 'field_data_field_date_item_single';
  $handler->display->display_options['fields']['field_date_item_single']['field'] = 'field_date_item_single';
  $handler->display->display_options['fields']['field_date_item_single']['relationship'] = 'field_valid_until_target_id';
  $handler->display->display_options['fields']['field_date_item_single']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_item_single']['settings'] = array(
    'format_type' => 'month',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_date_item_single']['format_date_sql'] = 1;
  /* Field: SUM(Commerce Order: Order total) */
  $handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['group_type'] = 'sum';
  $handler->display->display_options['fields']['commerce_order_total']['label'] = 'EUR';
  $handler->display->display_options['fields']['commerce_order_total']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_order_total']['type'] = 'commerce_price_no_decimals';
  $handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
    'calculation' => TRUE,
  );
  $handler->display->display_options['fields']['commerce_order_total']['group_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_order_total']['group_columns'] = array(
    'currency_code' => 'currency_code',
  );
  $handler->display->display_options['displays'] = array(
    'ingoing_pane' => 'ingoing_pane',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $handler->display->display_options['inherit_exposed_filters'] = TRUE;
  
  /* Display: Outgoing */
  $handler = $view->new_display('panel_pane', 'Outgoing', 'outgoing_pane');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Outgoing';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'chart';
  $handler->display->display_options['style_options']['type'] = 'column';
  $handler->display->display_options['style_options']['library'] = '';
  $handler->display->display_options['style_options']['label_field'] = 'field_date_item_single';
  $handler->display->display_options['style_options']['data_fields'] = array(
    'commerce_order_total' => 'commerce_order_total',
    'field_date_item_single' => 0,
  );
  $handler->display->display_options['style_options']['field_colors'] = array(
    'commerce_order_total' => '#d52b2b',
    'field_date_item_single' => '#0d233a',
  );
  $handler->display->display_options['style_options']['title'] = 'Outgoing report';
  $handler->display->display_options['style_options']['width'] = '1000';
  $handler->display->display_options['style_options']['height'] = '200';
  $handler->display->display_options['style_options']['xaxis_labels_rotation'] = '30';
  $handler->display->display_options['style_options']['yaxis_labels_rotation'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Date item: Date (field_date_item_single) */
  $handler->display->display_options['filters']['field_date_item_single_value']['id'] = 'field_date_item_single_value';
  $handler->display->display_options['filters']['field_date_item_single_value']['table'] = 'field_data_field_date_item_single';
  $handler->display->display_options['filters']['field_date_item_single_value']['field'] = 'field_date_item_single_value';
  $handler->display->display_options['filters']['field_date_item_single_value']['relationship'] = 'field_valid_until_target_id';
  $handler->display->display_options['filters']['field_date_item_single_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_date_item_single_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_date_item_single_value']['expose']['operator_id'] = 'field_date_item_single_value_op';
  $handler->display->display_options['filters']['field_date_item_single_value']['expose']['operator'] = 'field_date_item_single_value_op';
  $handler->display->display_options['filters']['field_date_item_single_value']['expose']['identifier'] = 'outgoing_date';
  $handler->display->display_options['filters']['field_date_item_single_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_date_item_single_value']['form_type'] = 'date_popup';
  /* Filter criterion: Commerce Order: Order status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    'feedback' => 'feedback',
    'declined' => 'declined',
    'accepted' => 'accepted',
  );
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'outgoing_status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['status']['expose']['reduce'] = TRUE;
  /* Filter criterion: Commerce Order: Payment type */
  $handler->display->display_options['filters']['payment_type']['id'] = 'payment_type';
  $handler->display->display_options['filters']['payment_type']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['payment_type']['field'] = 'payment_type';
  $handler->display->display_options['filters']['payment_type']['value'] = 'outgoing';
  /* Filter criterion: Global: Exposed date format */
  $handler->display->display_options['filters']['date_format']['id'] = 'date_format';
  $handler->display->display_options['filters']['date_format']['table'] = 'views';
  $handler->display->display_options['filters']['date_format']['field'] = 'date_format';
  $handler->display->display_options['filters']['date_format']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_format']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['date_format']['expose']['label'] = 'Scale';
  $handler->display->display_options['filters']['date_format']['expose']['operator'] = 'date_format_op';
  $handler->display->display_options['filters']['date_format']['expose']['identifier'] = 'outgoing_date_format';
  $handler->display->display_options['filters']['date_format']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['date_format']['expose']['remember_roles'] = array(
    2 => 0,
    0 => 0,
    1 => 0,
  );
  $handler->display->display_options['filters']['date_format']['date_field'] = 'field_date_item_single';
  $handler->display->display_options['filters']['date_format']['date_formats'] = array(
    'month' => 'month',
    'year' => 'year',
  );
  /* Filter criterion: Commerce Order: Order type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'quote' => 'quote',
  );
  $handler->display->display_options['pane_category']['name'] = 'ERPAL reports';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'type' => array(
      'type' => 'user',
      'context' => 'entity:crm_core_activity.activity-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Order type',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  
  /* Display: Outgoing attachment */
  $handler = $view->new_display('attachment', 'Outgoing attachment', 'outgoing_attachment');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Summary';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_date_item_single' => 'field_date_item_single',
    'commerce_order_total' => 'commerce_order_total',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_date_item_single' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_order_total' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h2>Summary</h2>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Date item: Date */
  $handler->display->display_options['fields']['field_date_item_single']['id'] = 'field_date_item_single';
  $handler->display->display_options['fields']['field_date_item_single']['table'] = 'field_data_field_date_item_single';
  $handler->display->display_options['fields']['field_date_item_single']['field'] = 'field_date_item_single';
  $handler->display->display_options['fields']['field_date_item_single']['relationship'] = 'field_valid_until_target_id';
  $handler->display->display_options['fields']['field_date_item_single']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_item_single']['settings'] = array(
    'format_type' => 'month',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_date_item_single']['format_date_sql'] = 1;
  /* Field: SUM(Commerce Order: Order total) */
  $handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['group_type'] = 'sum';
  $handler->display->display_options['fields']['commerce_order_total']['label'] = 'EUR';
  $handler->display->display_options['fields']['commerce_order_total']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_order_total']['type'] = 'commerce_price_no_decimals';
  $handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
    'calculation' => TRUE,
  );
  $handler->display->display_options['fields']['commerce_order_total']['group_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_order_total']['group_columns'] = array(
    'currency_code' => 'currency_code',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Date item: Date (field_date_item_single) */
  $handler->display->display_options['filters']['field_date_item_single_value']['id'] = 'field_date_item_single_value';
  $handler->display->display_options['filters']['field_date_item_single_value']['table'] = 'field_data_field_date_item_single';
  $handler->display->display_options['filters']['field_date_item_single_value']['field'] = 'field_date_item_single_value';
  $handler->display->display_options['filters']['field_date_item_single_value']['relationship'] = 'field_valid_until_target_id';
  $handler->display->display_options['filters']['field_date_item_single_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_date_item_single_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_date_item_single_value']['expose']['operator_id'] = 'field_date_item_single_value_op';
  $handler->display->display_options['filters']['field_date_item_single_value']['expose']['operator'] = 'field_date_item_single_value_op';
  $handler->display->display_options['filters']['field_date_item_single_value']['expose']['identifier'] = 'outgoing_date';
  $handler->display->display_options['filters']['field_date_item_single_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_date_item_single_value']['form_type'] = 'date_popup';
  /* Filter criterion: Commerce Order: Order status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    'feedback' => 'feedback',
    'declined' => 'declined',
    'accepted' => 'accepted',
  );
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'outgoing_status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['status']['expose']['reduce'] = TRUE;
  /* Filter criterion: Commerce Order: Payment type */
  $handler->display->display_options['filters']['payment_type']['id'] = 'payment_type';
  $handler->display->display_options['filters']['payment_type']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['payment_type']['field'] = 'payment_type';
  $handler->display->display_options['filters']['payment_type']['value'] = 'outgoing';
  /* Filter criterion: Global: Exposed date format */
  $handler->display->display_options['filters']['date_format']['id'] = 'date_format';
  $handler->display->display_options['filters']['date_format']['table'] = 'views';
  $handler->display->display_options['filters']['date_format']['field'] = 'date_format';
  $handler->display->display_options['filters']['date_format']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_format']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['date_format']['expose']['label'] = 'Scale';
  $handler->display->display_options['filters']['date_format']['expose']['operator'] = 'date_format_op';
  $handler->display->display_options['filters']['date_format']['expose']['identifier'] = 'outgoing_date_format';
  $handler->display->display_options['filters']['date_format']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['date_format']['expose']['remember_roles'] = array(
    2 => 0,
    0 => 0,
    1 => 0,
  );
  $handler->display->display_options['filters']['date_format']['date_field'] = 'field_date_item_single';
  $handler->display->display_options['filters']['date_format']['date_formats'] = array(
    'month' => 'month',
    'year' => 'year',
  );
  /* Filter criterion: Commerce Order: Order type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'quote' => 'quote',
  );
  $handler->display->display_options['displays'] = array(
    'outgoing_pane' => 'outgoing_pane',
    'default' => 0,
    'ingoing_pane' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $handler->display->display_options['inherit_exposed_filters'] = TRUE;
  
  /* Display: Tax */
  $handler = $view->new_display('panel_pane', 'Tax', 'tax_pane');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Tax';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'chart';
  $handler->display->display_options['style_options']['type'] = 'column';
  $handler->display->display_options['style_options']['library'] = '';
  $handler->display->display_options['style_options']['label_field'] = 'field_date_item_single';
  $handler->display->display_options['style_options']['data_fields'] = array(
    'taxed' => 'taxed',
    'field_date_item_single' => 0,
  );
  $handler->display->display_options['style_options']['field_colors'] = array(
    'taxed' => '#0d233a',
    'field_date_item_single' => '#0d233a',
  );
  $handler->display->display_options['style_options']['title'] = 'Tax report';
  $handler->display->display_options['style_options']['width'] = '1000';
  $handler->display->display_options['style_options']['height'] = '200';
  $handler->display->display_options['style_options']['xaxis_labels_rotation'] = '30';
  $handler->display->display_options['style_options']['yaxis_min'] = '0';
  $handler->display->display_options['style_options']['yaxis_labels_rotation'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Commerce Order: Tax Reports */
  $handler->display->display_options['relationships']['payment_transaction']['id'] = 'payment_transaction';
  $handler->display->display_options['relationships']['payment_transaction']['table'] = 'commerce_order';
  $handler->display->display_options['relationships']['payment_transaction']['field'] = 'payment_transaction';
  /* Relationship: Date item */
  $handler->display->display_options['relationships']['field_valid_until_target_id']['id'] = 'field_valid_until_target_id';
  $handler->display->display_options['relationships']['field_valid_until_target_id']['table'] = 'field_data_field_valid_until';
  $handler->display->display_options['relationships']['field_valid_until_target_id']['field'] = 'field_valid_until_target_id';
  $handler->display->display_options['relationships']['field_valid_until_target_id']['ui_name'] = 'Date item';
  $handler->display->display_options['relationships']['field_valid_until_target_id']['label'] = 'Date item';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: SUM(Commerce Tax Reports: Taxed) */
  $handler->display->display_options['fields']['taxed']['id'] = 'taxed';
  $handler->display->display_options['fields']['taxed']['table'] = 'commerce_reports_tax';
  $handler->display->display_options['fields']['taxed']['field'] = 'taxed';
  $handler->display->display_options['fields']['taxed']['relationship'] = 'payment_transaction';
  $handler->display->display_options['fields']['taxed']['group_type'] = 'sum';
  $handler->display->display_options['fields']['taxed']['label'] = 'EUR';
  $handler->display->display_options['fields']['taxed']['display_format'] = 'raw';
  /* Field: Date item: Date */
  $handler->display->display_options['fields']['field_date_item_single']['id'] = 'field_date_item_single';
  $handler->display->display_options['fields']['field_date_item_single']['table'] = 'field_data_field_date_item_single';
  $handler->display->display_options['fields']['field_date_item_single']['field'] = 'field_date_item_single';
  $handler->display->display_options['fields']['field_date_item_single']['relationship'] = 'field_valid_until_target_id';
  $handler->display->display_options['fields']['field_date_item_single']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_item_single']['settings'] = array(
    'format_type' => 'month',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_date_item_single']['format_date_sql'] = 1;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Date item: Date (field_date_item_single) */
  $handler->display->display_options['filters']['field_date_item_single_value']['id'] = 'field_date_item_single_value';
  $handler->display->display_options['filters']['field_date_item_single_value']['table'] = 'field_data_field_date_item_single';
  $handler->display->display_options['filters']['field_date_item_single_value']['field'] = 'field_date_item_single_value';
  $handler->display->display_options['filters']['field_date_item_single_value']['relationship'] = 'field_valid_until_target_id';
  $handler->display->display_options['filters']['field_date_item_single_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_date_item_single_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_date_item_single_value']['expose']['operator_id'] = 'field_date_item_single_value_op';
  $handler->display->display_options['filters']['field_date_item_single_value']['expose']['operator'] = 'field_date_item_single_value_op';
  $handler->display->display_options['filters']['field_date_item_single_value']['expose']['identifier'] = 'tax_date';
  $handler->display->display_options['filters']['field_date_item_single_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_date_item_single_value']['form_type'] = 'date_popup';
  /* Filter criterion: Commerce Order: Order status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    'feedback' => 'feedback',
    'declined' => 'declined',
    'accepted' => 'accepted',
  );
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'tax_status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['status']['expose']['reduce'] = TRUE;
  /* Filter criterion: Commerce Order: Payment type */
  $handler->display->display_options['filters']['payment_type']['id'] = 'payment_type';
  $handler->display->display_options['filters']['payment_type']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['payment_type']['field'] = 'payment_type';
  $handler->display->display_options['filters']['payment_type']['value'] = 'All';
  $handler->display->display_options['filters']['payment_type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['payment_type']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['payment_type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['payment_type']['expose']['operator'] = 'payment_type_op';
  $handler->display->display_options['filters']['payment_type']['expose']['identifier'] = 'tax_payment_type';
  $handler->display->display_options['filters']['payment_type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Global: Exposed date format */
  $handler->display->display_options['filters']['date_format']['id'] = 'date_format';
  $handler->display->display_options['filters']['date_format']['table'] = 'views';
  $handler->display->display_options['filters']['date_format']['field'] = 'date_format';
  $handler->display->display_options['filters']['date_format']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_format']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['date_format']['expose']['label'] = 'Scale';
  $handler->display->display_options['filters']['date_format']['expose']['operator'] = 'date_format_op';
  $handler->display->display_options['filters']['date_format']['expose']['identifier'] = 'tax_date_format';
  $handler->display->display_options['filters']['date_format']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['date_format']['expose']['remember_roles'] = array(
    2 => 0,
    0 => 0,
    1 => 0,
  );
  $handler->display->display_options['filters']['date_format']['date_field'] = 'field_date_item_single';
  $handler->display->display_options['filters']['date_format']['date_formats'] = array(
    'month' => 'month',
    'year' => 'year',
  );
  /* Filter criterion: Commerce Order: Order type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'quote' => 'quote',
  );
  $handler->display->display_options['pane_category']['name'] = 'ERPAL reports';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'type' => array(
      'type' => 'user',
      'context' => 'entity:crm_core_activity.activity-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Order type',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  
  /* Display: Tax attachment */
  $handler = $view->new_display('attachment', 'Tax attachment', 'tax_attachment');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Summary';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_date_item_single' => 'field_date_item_single',
    'commerce_order_total' => 'commerce_order_total',
    'taxed' => 'taxed',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_date_item_single' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_order_total' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'taxed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h2>Summary</h2>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Commerce Order: Tax Reports */
  $handler->display->display_options['relationships']['payment_transaction']['id'] = 'payment_transaction';
  $handler->display->display_options['relationships']['payment_transaction']['table'] = 'commerce_order';
  $handler->display->display_options['relationships']['payment_transaction']['field'] = 'payment_transaction';
  /* Relationship: Date item */
  $handler->display->display_options['relationships']['field_valid_until_target_id']['id'] = 'field_valid_until_target_id';
  $handler->display->display_options['relationships']['field_valid_until_target_id']['table'] = 'field_data_field_valid_until';
  $handler->display->display_options['relationships']['field_valid_until_target_id']['field'] = 'field_valid_until_target_id';
  $handler->display->display_options['relationships']['field_valid_until_target_id']['ui_name'] = 'Date item';
  $handler->display->display_options['relationships']['field_valid_until_target_id']['label'] = 'Date item';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Date item: Date */
  $handler->display->display_options['fields']['field_date_item_single']['id'] = 'field_date_item_single';
  $handler->display->display_options['fields']['field_date_item_single']['table'] = 'field_data_field_date_item_single';
  $handler->display->display_options['fields']['field_date_item_single']['field'] = 'field_date_item_single';
  $handler->display->display_options['fields']['field_date_item_single']['relationship'] = 'field_valid_until_target_id';
  $handler->display->display_options['fields']['field_date_item_single']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_item_single']['settings'] = array(
    'format_type' => 'month',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_date_item_single']['format_date_sql'] = 1;
  /* Field: SUM(Commerce Order: Order total) */
  $handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['group_type'] = 'sum';
  $handler->display->display_options['fields']['commerce_order_total']['label'] = 'Total';
  $handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_order_total']['type'] = 'commerce_price_no_decimals';
  $handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
    'calculation' => TRUE,
  );
  $handler->display->display_options['fields']['commerce_order_total']['group_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_order_total']['group_columns'] = array(
    'currency_code' => 'currency_code',
  );
  /* Field: SUM(Commerce Tax Reports: Taxed) */
  $handler->display->display_options['fields']['taxed']['id'] = 'taxed';
  $handler->display->display_options['fields']['taxed']['table'] = 'commerce_reports_tax';
  $handler->display->display_options['fields']['taxed']['field'] = 'taxed';
  $handler->display->display_options['fields']['taxed']['relationship'] = 'payment_transaction';
  $handler->display->display_options['fields']['taxed']['group_type'] = 'sum';
  $handler->display->display_options['fields']['taxed']['label'] = 'Tax';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Date item: Date (field_date_item_single) */
  $handler->display->display_options['filters']['field_date_item_single_value']['id'] = 'field_date_item_single_value';
  $handler->display->display_options['filters']['field_date_item_single_value']['table'] = 'field_data_field_date_item_single';
  $handler->display->display_options['filters']['field_date_item_single_value']['field'] = 'field_date_item_single_value';
  $handler->display->display_options['filters']['field_date_item_single_value']['relationship'] = 'field_valid_until_target_id';
  $handler->display->display_options['filters']['field_date_item_single_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_date_item_single_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_date_item_single_value']['expose']['operator_id'] = 'field_date_item_single_value_op';
  $handler->display->display_options['filters']['field_date_item_single_value']['expose']['operator'] = 'field_date_item_single_value_op';
  $handler->display->display_options['filters']['field_date_item_single_value']['expose']['identifier'] = 'tax_date';
  $handler->display->display_options['filters']['field_date_item_single_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_date_item_single_value']['form_type'] = 'date_popup';
  /* Filter criterion: Commerce Order: Order status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    'feedback' => 'feedback',
    'declined' => 'declined',
    'accepted' => 'accepted',
  );
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'tax_status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['status']['expose']['reduce'] = TRUE;
  /* Filter criterion: Commerce Order: Payment type */
  $handler->display->display_options['filters']['payment_type']['id'] = 'payment_type';
  $handler->display->display_options['filters']['payment_type']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['payment_type']['field'] = 'payment_type';
  $handler->display->display_options['filters']['payment_type']['value'] = 'All';
  $handler->display->display_options['filters']['payment_type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['payment_type']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['payment_type']['expose']['label'] = 'Payment type';
  $handler->display->display_options['filters']['payment_type']['expose']['operator'] = 'payment_type_op';
  $handler->display->display_options['filters']['payment_type']['expose']['identifier'] = 'tax_payment_type';
  $handler->display->display_options['filters']['payment_type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Global: Exposed date format */
  $handler->display->display_options['filters']['date_format']['id'] = 'date_format';
  $handler->display->display_options['filters']['date_format']['table'] = 'views';
  $handler->display->display_options['filters']['date_format']['field'] = 'date_format';
  $handler->display->display_options['filters']['date_format']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_format']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['date_format']['expose']['label'] = 'Scale';
  $handler->display->display_options['filters']['date_format']['expose']['operator'] = 'date_format_op';
  $handler->display->display_options['filters']['date_format']['expose']['identifier'] = 'tax_date_format';
  $handler->display->display_options['filters']['date_format']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['date_format']['expose']['remember_roles'] = array(
    2 => 0,
    0 => 0,
    1 => 0,
  );
  $handler->display->display_options['filters']['date_format']['date_field'] = 'field_date_item_single';
  $handler->display->display_options['filters']['date_format']['date_formats'] = array(
    'month' => 'month',
    'year' => 'year',
  );
  /* Filter criterion: Commerce Order: Order type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'quote' => 'quote',
  );
  $handler->display->display_options['displays'] = array(
    'tax_pane' => 'tax_pane',
    'default' => 0,
    'ingoing_pane' => 0,
    'outgoing_pane' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $handler->display->display_options['inherit_exposed_filters'] = TRUE;
  $translatables['erpal_quote_reports'] = array(
    t('Master'),
    t('Ingoing'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('No data by given parameters'),
    t('Date item'),
    t('EUR'),
    t('Date'),
    t('Status'),
    t('Scale'),
    t('ERPAL reports'),
    t('Ingoing attachment'),
    t('Summary'),
    t('<h2>Summary</h2>'),
    t('Outgoing'),
    t('Outgoing attachment'),
    t('Tax'),
    t('Type'),
    t('Tax attachment'),
    t('Total'),
    t('Payment type'),
  );

  return $view;
}
