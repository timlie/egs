<?php
/*
 * @file button.theme.inc.
 */

/*
 * Implements theme_button().
 * Instead of an input this returns a button because this is better themeable.
 */
function erpal_theme_button($variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'submit';
  element_set_attributes($element, array('id', 'name', 'value'));

  $element['#attributes']['class'][] = 'form-' . $element['#button_type'];
  if (!empty($element['#attributes']['disabled'])) {
    $element['#attributes']['class'][] = 'form-button-disabled';
  }

  return '<button' . drupal_attributes($element['#attributes']) . ' >' . $element['#attributes']['value'] . '</button>';
}
