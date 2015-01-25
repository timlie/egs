<?php

/**
 * @file
 * Contains controller classes for DateItem and DateItemType entities.
 */

/**
 * DateItem class.
 */
class DateItem extends Entity {

  /**
   * The primary identifier for the date item entity.
   *
   * @var integer
   */
  public $diid;

  /**
   * The type of this date item.
   *
   * @var string
   */
  public $type;

  /**
   * Machine name of related entity type.
   *
   * @var string
   */
  public $entity_type;

  /**
   * ID of the related entity.
   *
   * @var integer
   */
  public $entity_id;

  /**
   * Returns default label.
   */
  protected function defaultLabel() {
    return $this->diid;
  }
}

/**
 * DateItemType class.
 */
class DateItemType extends Entity {

  /**
   * The name of this date item type.
   *
   * @var string
   */
  public $machine_name;

  /**
   * The human-readable name of this date item type.
   *
   * @var string
   */
  public $label;

  /**
   * The description for date item type.
   *
   * @var string
   */
  public $description;

  public function __construct($values = array()) {
    parent::__construct($values, 'date_item_type');
  }

  function isLocked() {
    return isset($this->status) && empty($this->is_new) && (($this->status & ENTITY_IN_CODE) || ($this->status & ENTITY_FIXED));
  }

  protected function defaultLabel() {
    return $this->label;
  }
}

/**
 * @see hook_entity_property_info()
 */
class DateItemMetadataController extends EntityDefaultMetadataController {

  public function entityPropertyInfo() {
    $info = parent::entityPropertyInfo();

    $properties = &$info['date_item']['properties'];
    $properties['referencing_entity'] = array(
      'label' => t('Referencing entity'),
      'type' => 'entity',
      'description' => t('The Referencing entity to the date item.'),
      'getter callback' => 'date_item_get_entity_property',
      'entity views field' => TRUE,
    );
    $properties['type'] = array(
      'label' => t('Date item type'),
      'type' => 'date_item_type',
      'description' => t('The type of the date item.'),
      'setter callback' => 'entity_property_verbatim_set',
      'required' => TRUE,
      'schema field' => 'type',
    );
    return $info;
  }

}

/**
 * Overrides EntityInlineEntityFormController.
 */
class DateItemInlineEntityFormController extends EntityInlineEntityFormController {

  /**
   * Overrides EntityInlineEntityFormController::entityForm().
   */
  public function entityForm($entity_form, &$form_state) {
    $line_item = $entity_form['#entity'];
    field_attach_form('date_item', $line_item, $entity_form, $form_state);

    return $entity_form;
  }

  /**
   * Overrides EntityInlineEntityFormController::entityFormValidate().
   */
  public function entityFormValidate($entity_form, &$form_state) {
    $line_item = $entity_form['#entity'];
    field_attach_form_validate('date_item', $line_item, $entity_form, $form_state);
  }

  /**
   * Overrides EntityInlineEntityFormController::entityFormSubmit().
   */
  public function entityFormSubmit(&$entity_form, &$form_state) {
    $date_item = $entity_form['#entity'];

    // Store entity reference field to update entity_id in feature. @see: date_item_entity_update().
    if (empty($date_item->entity_id) || $date_item->entity_id == 0) {
      $form_state['build_info']['args'][0]->date_item_update_field = $entity_form['#parents'][0];
    }

    field_attach_submit('date_item', $date_item, $entity_form, $form_state);
  }
}
