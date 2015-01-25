<?php
/**
 * @file
 * erpal_budget_ui.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function erpal_budget_ui_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'erpal_budget|money|full';
  $ds_layout->entity_type = 'erpal_budget';
  $ds_layout->bundle = 'money';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_budget_reference_view',
        2 => 'field_budget_available',
        3 => 'field_budget_negative',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_budget_reference_view' => 'ds_content',
      'field_budget_available' => 'ds_content',
      'field_budget_negative' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['erpal_budget|money|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'erpal_budget|time|default';
  $ds_layout->entity_type = 'erpal_budget';
  $ds_layout->bundle = 'time';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_budget_available',
        2 => 'field_budget_total',
        3 => 'field_budget_negative',
        4 => 'field_resource',
        5 => 'field_budget_type',
        6 => 'field_budget_outputs',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_budget_available' => 'ds_content',
      'field_budget_total' => 'ds_content',
      'field_budget_negative' => 'ds_content',
      'field_resource' => 'ds_content',
      'field_budget_type' => 'ds_content',
      'field_budget_outputs' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['erpal_budget|time|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'erpal_budget|time|full';
  $ds_layout->entity_type = 'erpal_budget';
  $ds_layout->bundle = 'time';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_budget_reference_view',
        2 => 'field_budget_available',
        3 => 'field_budget_type',
        4 => 'field_budget_negative',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_budget_reference_view' => 'ds_content',
      'field_budget_available' => 'ds_content',
      'field_budget_type' => 'ds_content',
      'field_budget_negative' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['erpal_budget|time|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'erpal_output|money|default';
  $ds_layout->entity_type = 'erpal_output';
  $ds_layout->bundle = 'money';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_output_delivered_date',
        1 => 'field_output_delivered',
        2 => 'field_resource',
        3 => 'field_output_unit',
        4 => 'saldo',
        5 => 'field_output_budget',
      ),
    ),
    'fields' => array(
      'field_output_delivered_date' => 'ds_content',
      'field_output_delivered' => 'ds_content',
      'field_resource' => 'ds_content',
      'field_output_unit' => 'ds_content',
      'saldo' => 'ds_content',
      'field_output_budget' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['erpal_output|money|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'erpal_output|money|full';
  $ds_layout->entity_type = 'erpal_output';
  $ds_layout->bundle = 'money';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_output_delivered_date',
        1 => 'field_output_unit',
        2 => 'field_budget_reference_view',
        3 => 'field_output_budget',
        4 => 'field_output_delivered',
      ),
    ),
    'fields' => array(
      'field_output_delivered_date' => 'ds_content',
      'field_output_unit' => 'ds_content',
      'field_budget_reference_view' => 'ds_content',
      'field_output_budget' => 'ds_content',
      'field_output_delivered' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['erpal_output|money|full'] = $ds_layout;

  return $export;
}
