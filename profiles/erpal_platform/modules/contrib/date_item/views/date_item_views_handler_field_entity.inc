<?php

/**
 * @file
 * Contains integration with Views module.
 * Outputs reference field as entity.
 */

/**
 * Implementing referencing entity field.
 */
class date_item_views_handler_field_entity extends entity_views_handler_field_entity {

  /**
   * Overrides entity_views_handler_field_entity::options_form().
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    // Adds all available views modes, because we don't know which type of referencing entity.
    $entities_info = entity_get_info();
    $options = array();
    foreach ($entities_info as $entity_info) {

      if (!empty($entity_info['view modes'])) {
        foreach ($entity_info['view modes'] as $mode => $settings) {
          $options[$mode] = $settings['label'];
        }
      }
    }

    if (count($options) > 1) {
      $options = array('default' => t('Default')) + $options;
      $form['view_mode'] = array(
        '#type' => 'select',
        '#options' => $options,
        '#title' => t('View mode'),
        '#default_value' => $this->options['view_mode'],
        '#dependency' => array('edit-options-display' => array('view')),
      );
    }
  }

  /**
   * Overrides entity_views_handler_field_entity::render_entity_link().
   *
   * Change $type variable, because it doesn't work with 'entity' field type and views.
   */
  public function render_entity_link($entity, $values) {
    $type = $this->field_entity_type;

    // Overrides type of the entity. This is the main difference from tparent method.
    if ($this->field == 'referencing_entity') {
      $type = $values->_field_data['diid']['entity']->entity_type;
    }
    if (!is_object($entity) && isset($entity) && $entity !== FALSE) {
      $entity = entity_load_single($type, $entity);
    }
    if (!$entity) {
      return '';
    }
    $render = $this->render_single_value($entity, $values);
    if (!$this->options['link_to_entity'] || $this->options['display'] == 'view') {
      return $render;
    }
    if (is_object($entity) && ($url = entity_uri($type, $entity))) {
      return l($render, $url['path'], array('html' => TRUE) + $url['options']);
    }
    return $render;
  }

  /**
   * Overrides entity_views_handler_field_entity::render_single_value().
   *
   * Change $type variable, because it doesn't work with 'entity' field type and views.
   */
  public function render_single_value($entity, $values) {
    $type = $this->field_entity_type;

    // Overrides type of the entity. This is the main difference from the parent method.
    if ($this->field == 'referencing_entity') {
      $type = $values->_field_data['diid']['entity']->entity_type;
    }
    if (!is_object($entity) && isset($entity) && $entity !== FALSE) {
      $entity = entity_load_single($type, $entity);
    }
    // Make sure the entity exists and access is either given or bypassed.
    if (!$entity || !(!empty($this->options['bypass_access']) || entity_access('view', $type, $entity))) {
      return '';
    }

    if ($this->options['display'] === 'view') {
      $entity_view = entity_view($type, array($entity), $this->options['view_mode']);
      return render($entity_view);
    }

    if ($this->options['display'] == 'label') {
      $value = entity_label($type, $entity);
    }
    // Either $options[display] == 'id', or we have no label.
    if (empty($value)) {
      $value = entity_id($type, $entity);
    }
    $value = $this->sanitize_value($value);

    return $value;
  }
}
