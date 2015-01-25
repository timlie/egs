<?php

/**
 * @file
 * Contains Date Item type entity definition and API functions.
 */

/**
 * Implements hook_entity_info().
 */
function _date_item_type_entity_info() {
  return array(
    'date_item_type' => array(
      'label' => t('Date item type'),
      'entity class' => 'DateItemType',
      'controller class' => 'EntityAPIControllerExportable',
      'base table' => 'date_item_type',
      'fieldable' => TRUE,
      'exportable' => TRUE,
      'bundle of' => 'date_item',
      'entity keys' => array(
        'id' => 'machine_name',
        'name' => 'machine_name',
        'label' => 'label',
      ),
      'module' => 'date_item',
      'admin ui' => array(),
      'label callback' => 'entity_class_label',
      'access callback' => 'date_item_type_access',
    ),
  );
}

/**
 * Access callback for date item type.
 */
function date_item_type_access() {
  return user_access('administer date item types');
}

/**
 * Load date item type object.
 *
 * @param $type_name
 *   Machine name of Date item type.
 *
 * @return array
 *   Date item type entity.
 */
function date_item_type_load($type_name) {
  return date_item_types($type_name);
}

/**
 * List of date item types by type name.
 *
 * @param string $type_name
 *   (optional) Machine name of Date item type.
 *
 * @return DateItemType|array
 *   Single DateItemType object by given type name or an array of DateItemType objects
 *   if none is specified.
 */
function date_item_types($type_name = NULL) {
  $date_item_types = entity_load_multiple_by_name('date_item_type', isset($type_name) ? array($type_name) : FALSE);
  return isset($type_name) ? reset($date_item_types) : $date_item_types;
}


/**
 * Creates a new date item type entity object.
 *
 * @param array $values
 *   Values by which date item entity will be created:
 *    - machine_name: The name of this date item type.
 *    - label: The human-readable name of this date item type.
 *    - description: The description for date item type.
 *
 * @return DateItemType
 *   DateItemType object what has been created.
 */
function date_item_type_create($values) {
  return entity_create('date_item_type', $values);
}

/**
 * Saves date item type entity.
 *
 * @param DateItemType $date_item_type
 *   DateItemType object.
 */
function date_item_type_save(DateItemType $date_item_type) {
  entity_save('date_item_type', $date_item_type);
}

/**
 * Delete single date item type entity.
 *
 * @param DateItemType $date_item_type
 *   DateItemType object.
 */
function date_item_type_delete(DateItemType $date_item_type) {
  entity_delete('date_item_type', entity_id('date_item_type', $date_item_type));
}
