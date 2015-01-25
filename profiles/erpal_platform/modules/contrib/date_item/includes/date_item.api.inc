<?php

/**
 * @file
 * Contains Date Item entity definition and API functions.
 */

/**
 * Defines date_item entity.
 * Calls from implementation of hook_entity_info().
 */
function _date_item_entity_info() {
  return array(
    'date_item' => array(
      'label' => t('Date item'),
      'entity class' => 'DateItem',
      'controller class' => 'EntityAPIController',
      'metadata controller class' => 'DateItemMetadataController',
      'inline entity form' => array(
        'controller' => 'DateItemInlineEntityFormController',
      ),
      'base table' => 'date_item',
      'fieldable' => TRUE,
      'entity keys' => array(
        'id' => 'diid',
        'bundle' => 'type',
      ),
      'bundle keys' => array(
        'bundle' => 'machine_name',
      ),
      'bundles' => array(),
      'view modes' => array(),
      'load hook' => 'date_item_load',
      'module' => 'date_item',
      'label callback' => 'entity_class_label',
      'uri callback' => 'entity_class_uri',
      'access callback' => 'date_item_access'
    ),
  );
}

/**
 * Attach bundles to the date_item entity.
 * Calls from implementation of hook_entity_info_alter().
 */
function _date_item_entity_info_alter(&$entity_info) {
  $date_item_bundles = date_item_types();

  foreach ($date_item_bundles as $type => $info) {
    $entity_info['date_item']['bundles'][$type] = array(
      'label' => $info->label,
      'admin' => array(
        'path' => DATE_ITEM_ADMIN_PATH . '/manage/%date_item_type',
        'real path' => DATE_ITEM_ADMIN_PATH . '/manage/' . $type,
        'bundle argument' => 4,
        'access callback' => FALSE,
      )
    );
  }
}

/**
 * Implements hook_views_data_alter().
 *
 * Overrides handler for referencing_entity field. To use field in views as entity type.
 */
function date_item_views_data_alter(&$data) {

  $data['views_entity_date_item']['referencing_entity']['field']['handler'] = 'date_item_views_handler_field_entity';
}

/**
 * Entity metadata callback: returns the referencing entity.
 *
 * @see DateItemMetadataController::entityPropertyInfo()
 */
function date_item_get_entity_property($data = FALSE, array $options, $name) {

  // Do not process entity if it has no required properties.
  if (empty($data->entity_type) || empty($data->entity_id)) {
    return FALSE;
  }

  $entity = entity_load_single($data->entity_type, $data->entity_id);
  return entity_metadata_wrapper($data->entity_type, $entity);
}

/**
 * Access callback for date_item entity.
 */
function date_item_access() {
  return TRUE;
}

/**
 * Create a new date_item entity object.
 *
 * @param string $type
 *   Machine name of date item type.
 * @param array $values
 *   Values by which date item entity will be created:
 *    - entity_type: Machine name of the related entity type.
 *    - entity_id: ID of the related entity.
 *
 * @return DateItem
 *   DateItem object what has been created.
 */
function date_item_create($type, $values = array()) {
  $values['type'] = $type;
  return entity_create('date_item', $values);
}

/**
 * Load a date item entity by id.
 *
 * @param integer $diid
 *   Date item entity id.
 *
 * @param bool $reset
 *   Whether to reset the internal cache for the requested entity type.
 *
 * @return DateItem
 *   DateItem object.
 */
function date_item_load($diid, $reset = FALSE) {
  $date_items = date_item_load_multiple(array($diid), array(), $reset);
  return reset($date_items);
}

/**
 * Load multiple date items based on certain conditions.
 *
 * @param $diids
 *   Array of date_item entities ids.
 *
 * @param array $conditions
 *   Array of confitions to load entities.
 *
 * @param bool $reset
 *   Whether to reset the internal cache for the requested entity type.
 *
 * @return array
 *   An array of DateItem objects.
 */
function date_item_load_multiple($diids = FALSE, $conditions = array(), $reset = FALSE) {
  return entity_load('date_item', $diids, $conditions, $reset);
}

/**
 * Saves date_item object.
 *
 * @param DateItem $date_item
 *   DateItem object.
 */
function date_item_save($date_item) {
  entity_save('date_item', $date_item);
}

/**
 * Updates referencing entity for date item.
 *
 * @param integer $date_item_id
 *   Date item entity id.
 *
 * @param string $entity_type
 *   Machine name of the related entity type.
 *
 * @param integer $entity_id
 *   ID of the related entity.
 */
function date_item_update_entity_id($date_item_id, $entity_type, $entity_id) {

  $date_item = date_item_load($date_item_id);
  $date_item->entity_type = $entity_type;
  $date_item->entity_id = $entity_id;
  date_item_save($date_item);
}

/**
 * Delete single date_item object.
 *
 * @param DateItem $date_item
 *   DateItem object.
 */
function date_item_delete($date_item) {
  entity_delete('date_item', entity_id('date_item', $date_item));
}

/**
 * Delete multiple date_items.
 *
 * @param array $rids
 *   An array of DateItem object ids.
 */
function date_item_delete_multiple($rids) {
  entity_delete_multiple('date_item', $rids);
}
