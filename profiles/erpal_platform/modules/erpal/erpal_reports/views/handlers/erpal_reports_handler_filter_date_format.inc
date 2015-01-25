<?php

/**
 * @file
 * Definition of erpal_reports_views_handler_filter_date_format.
 */

/**
 * Exposed filter to chose date field format.
 *
 * @ingroup views_filter_handlers
 */
class erpal_reports_handler_filter_date_format extends views_handler_filter {
  var $always_required = TRUE;

  function admin_summary() { }
  function query() { }

  /**
   * Set default values for the date filter.
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['date_field'] = array('default' => '');
    $options['date_formats'] = array('default' => array());
    return $options;
  }

  /**
   * Provide default options for exposed filters.
   */
  function expose_options() {
    parent::expose_options();

    // Expose filter by default.
    $this->options['exposed'] = TRUE;
  }

  /**
   * Provide form for filter settings.
   */
  function expose_form(&$form, &$form_state) {
    parent::expose_form($form, $form_state);

    // Hide unnecessary elements.
    $form['expose']['multiple']['#access'] = FALSE;
    $form['expose']['remember']['#access'] = FALSE;
    $form['expose']['remember_roles']['#access'] = FALSE;

    // Get a list of the available date fields.
    $options = array();
    foreach ($this->view->display_handler->get_handlers('field') as $field => $handler) {

      if (!empty($handler->field_info['type']) &&
        ($handler->field_info['type'] == 'datetime' || $handler->field_info['type'] == 'datestamp')) {

        $options[$field] = check_plain($handler->ui_name());
      }
    }

    if (!empty($options)) {
      // Field with available date fields.
      $form['expose']['date_field'] = array(
        '#type' => 'select',
        '#title' => t('Date field'),
        '#options' => $options,
      );

      // Field with available date formats.
      $form['expose']['date_formats'] = array(
        '#type' => 'select',
        '#multiple' => TRUE,
        '#title' => t('Date formats'),
        '#options' => $this->date_formats(),
        '#default_value' => !empty($this->options['date_formats']) ? $this->options['date_formats'] : array(),
      );
    }
    else {
      // Output message if date fields has not been added.
      $form['expose']['notice'] = array(
        '#markup' => t('Add date field before to use this filter.'),
      );
    }
  }

  /**
   * Provide the basic form for filter options.
   */
  function options_form(&$form, &$form_state) {

    // Set default options if needed.
    if (empty($this->options['expose']['identifier'])) {
      $this->expose_options();
    }
    parent::options_form($form, $form_state);

    // Hide unnecessary elements.
    $form['expose_button']['#disabled'] = TRUE;
    $form['relationship']['#access'] = FALSE;
  }

  /**
   * Provide a selectbox with date formats on exposed form.
   */
  function value_form(&$form, &$form_state) {
    parent::value_form($form, $form_state);

    if (!empty($form_state['exposed']) && !empty($this->options['date_field'])) {

      // Get default format for filter.
      $field = $this->options['date_field'];

      // Set Date field format by default.
      $field_format = $form_state['view']->display_handler->handlers['field'][$field]->options['settings']['format_type'];

      if (!empty($this->options['date_formats']) && empty($this->options['date_formats'][$field_format])) {
        $field_format = reset($this->options['date_formats']);
      }

      $options = $this->date_formats();
      if (!empty($this->options['date_formats'])) {
        $options = array_intersect_key($options, $this->options['date_formats']);
      }
      $form['value'] = array(
        '#type' => 'select',
        '#options' => $options,
        '#default_value' => $field_format,
      );
    }
  }

  /**
   * Value validation.
   *
   * Store filter options in options array.
   */
  function value_validate($form, &$form_state) {
    parent::value_validate($form, $form_state);

    $options = &$form_state['values']['options'];
    $this->options['date_field'] = $options['expose']['date_field'];
    $this->options['date_formats'] = $options['expose']['date_formats'];
  }

  /**
   * Exposed form submit function.
   *
   * Replace date field format to chosen in filter format.
   */
  function exposed_submit(&$form, &$form_state) {
    $field = $this->options['date_field'];

    if (!empty($field) && !empty($form_state['view']->display_handler->handlers['field'][$field])) {

      // Get format value for filter.
      $field_format = $form_state['view']->display_handler->handlers['field'][$field]->options['settings']['format_type'];
      if (!empty($this->view->exposed_input[$this->options['expose']['identifier']])) {
        $value = $this->view->exposed_input[$this->options['expose']['identifier']];
      }
      elseif (!empty($this->options['date_formats'][$field_format])) {
        $value = $field_format;
      }
      else {
        $value = reset($this->options['date_formats']);
      }

      // Replace date format.
      $form_state['view']->display_handler->handlers['field'][$field]->options['settings']['format_type'] = $value;
    }
  }

  /**
   * Creates an array of date format types for use as an options list.
   */
  function date_formats() {
    $options = array();
    $format_types = system_get_date_types();
    if (!empty($format_types)) {
      foreach ($format_types as $type => $type_info) {
        $options[$type] = $type_info['title'];
      }
    }
    return $options;
  }

}
