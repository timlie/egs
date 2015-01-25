<?php

/**
 * @file
 * Default date item types.
 */

/**
 * Returns default date item types.
 */
function _date_item_default_date_item_type() {
  $t = get_t();

  return array(
    array(
      'label' => $t('Single'),
      'machine_name' => 'single',
      'description' => $t('Single date'),
      'module' => 'date_item',
    ),
    array(
      'label' => $t('With end date'),
      'machine_name' => 'with_end',
      'description' => $t('Date with end date'),
      'module' => 'date_item',
    ),
    array(
      'label' => $t('Repeatable'),
      'machine_name' => 'repeatable',
      'description' => $t('Repeatable date'),
      'module' => 'date_item',
    ),
  );
}
