<?php
/**
 * @file
 * erpal_project_ui.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function erpal_project_ui_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|erpal_project|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'erpal_project';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'author' => array(
      'weight' => '3',
      'label' => 'above',
      'format' => 'author_linked',
    ),
    'post_date' => array(
      'weight' => '2',
      'label' => 'above',
      'format' => 'ds_post_date_short',
    ),
    'field_project_order' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lbw-el' => 'div',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'small-list',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'ul',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'li',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
  );
  $export['node|erpal_project|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|erpal_project|reference';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'erpal_project';
  $ds_fieldsetting->view_mode = 'reference';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => '',
        'class' => '',
        'ft' => array(),
      ),
    ),
  );
  $export['node|erpal_project|reference'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|erpal_task|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'erpal_task';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'author' => array(
      'weight' => '6',
      'label' => 'above',
      'format' => 'author',
    ),
    'post_date' => array(
      'weight' => '5',
      'label' => 'above',
      'format' => 'ds_post_date_short',
    ),
  );
  $export['node|erpal_task|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function erpal_project_ui_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|erpal_project|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'erpal_project';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'field_project_status',
        1 => 'field_date_with_end_ref',
        2 => 'post_date',
        3 => 'author',
      ),
      'left' => array(
        4 => 'field_resource',
        5 => 'body',
      ),
      'right' => array(
        6 => 'field_project_budget_view',
        7 => 'field_project_order',
        8 => 'field_project_line_item',
        9 => 'field_project_payment_modality',
        10 => 'field_project_postpaid_tasks',
      ),
    ),
    'fields' => array(
      'field_project_status' => 'header',
      'field_date_with_end_ref' => 'header',
      'post_date' => 'header',
      'author' => 'header',
      'field_resource' => 'left',
      'body' => 'left',
      'field_project_budget_view' => 'right',
      'field_project_order' => 'right',
      'field_project_line_item' => 'right',
      'field_project_payment_modality' => 'right',
      'field_project_postpaid_tasks' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'hide_page_title' => '0',
    'page_option_title' => '',
  );
  $export['node|erpal_project|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|erpal_project|reference';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'erpal_project';
  $ds_layout->view_mode = 'reference';
  $ds_layout->layout = 'panels-naked';
  $ds_layout->settings = array(
    'regions' => array(
      'content' => array(
        0 => 'title',
      ),
    ),
    'fields' => array(
      'title' => 'content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|erpal_project|reference'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|erpal_task|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'erpal_task';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'field_task_project',
        1 => 'field_task_parent',
        2 => 'field_task_priority',
        3 => 'field_task_type',
        4 => 'field_task_status',
        5 => 'post_date',
        6 => 'author',
      ),
      'left' => array(
        7 => 'field_resource',
        8 => 'body',
      ),
      'right' => array(
        9 => 'field_project_budget_view',
        10 => 'field_task_line_item',
        11 => 'field_task_payment_modality',
      ),
    ),
    'fields' => array(
      'field_task_project' => 'header',
      'field_task_parent' => 'header',
      'field_task_priority' => 'header',
      'field_task_type' => 'header',
      'field_task_status' => 'header',
      'post_date' => 'header',
      'author' => 'header',
      'field_resource' => 'left',
      'body' => 'left',
      'field_project_budget_view' => 'right',
      'field_task_line_item' => 'right',
      'field_task_payment_modality' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'hide_page_title' => '0',
    'page_option_title' => '',
  );
  $export['node|erpal_task|full'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function erpal_project_ui_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'reference';
  $ds_view_mode->label = 'Reference';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['reference'] = $ds_view_mode;

  return $export;
}