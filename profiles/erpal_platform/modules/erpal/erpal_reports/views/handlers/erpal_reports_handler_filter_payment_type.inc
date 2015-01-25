<?php

/**
 * Filter by payment type.
 */
class erpal_reports_handler_filter_payment_type extends views_handler_filter_boolean_operator {

  /**
   * Set filter label.
   */
  function construct() {
    parent::construct();
    $this->value_value = t('Payment type');
  }

  /**
   * Set filter summary.
   */
  function admin_summary() {
    if ($this->is_a_group()) {
      return t('grouped');
    }
    if (!empty($this->options['exposed'])) {
      return t('exposed');
    }
    if (empty($this->value_options)) {
      $this->get_value_options();
    }
    return $this->value_options[$this->value];
  }

  /**
   * Define options.
   */
  function get_value_options() {
    if (!isset($this->value_options)) {
      $this->value_title = t('Payment type');
      $this->value_options = array(
        'ingoing' => t('Ingoing'),
        'outgoing' => t('Outgoing'),
      );
    }
  }

  /**
   * Override parent query method.
   *
   * Compare order customer and vendor in settings.
   * -Ingoing if customer is not vendor.
   * -Outgoing if customer if vendor.
   */
  function query() {
    $this->ensure_my_table();

    $vendor_settings = variable_get('erpal_vendor_settings', array());

    // Attach table with customer field.
    $join = new views_join();
    $def = array(
      'table' => 'field_data_field_customer',
      'field' => 'entity_id',
      'left_table' => $this->table_alias,
      'left_field' => 'order_id',
    );
    $join->definition = $def;
    $join->construct();
    $join->adjusted = TRUE;
    $this->table_alias = $this->query->add_table('field_data_field_customer', $this->relationship, $join);

    // Get operator.
    $operator = '=';
    if ($this->value == 'ingoing') {
      $operator = '<>';
    }
    $field = "$this->table_alias.$this->real_field";

    // Add where to query.
    $this->query->add_where($this->options['group'], $field, $vendor_settings['vendor_id'], $operator);
  }
}
