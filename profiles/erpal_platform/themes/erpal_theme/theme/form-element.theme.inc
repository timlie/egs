<?php
/*
 * @file form-element.theme.inc.
 */

function erpal_theme_form_element(array $variables) {
  $element = &$variables['element'];

  // This function is invoked as theme wrapper, but the rendered form element
  // may not necessarily have been processed by form_builder().
  $element += array(
    '#title_display' => 'before',
  );

  // Add element #id for #type 'item'.
  if (isset($element['#markup']) && !empty($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  // Add element's #type and #name as class to aid with JS/CSS selectors.
  $attributes['class'] = array('form-item');
  if (!empty($element['#type'])) {
    $attributes['class'][] = 'form-type-' . strtr($element['#type'], '_', '-');
  }
  if (!empty($element['#name'])) {
    $attributes['class'][] = 'form-item-' . strtr($element['#name'], array(
          ' ' => '-',
          '_' => '-',
          '[' => '-',
          ']' => ''
        ));
  }
  // Add a class for disabled elements to facilitate cross-browser styling.
  if (!empty($element['#attributes']['disabled'])) {
    $attributes['class'][] = 'form-disabled';
  }
  // add description class for tooltip positioning
  if (!empty($element['#description'])) {
    $attributes['class'][] = 'has-tooltip';

    if ($element['#title_display'] == 'none' || $element['#title_display'] == 'invisible') {
      $attributes['class'][] = 'has-no-title';
    }
  }

  // changing description markup for bootstrap tooltip support
  $desc = '';
  if (!empty($element['#description'])) {
    $desc = sprintf(
      '<div class="description" data-toggle="tooltip" title="%s"></div>',
      htmlspecialchars($element['#description'])
    );
  }

  // If #title is not set, we don't display any label or required marker.
  if (!isset($element['#title'])) {
    $element['#title_display'] = 'none';
  }
  $prefix = isset($element['#field_prefix']) ? '<span class="field-prefix">' . $element['#field_prefix'] . '</span> ' : '';
  $suffix = isset($element['#field_suffix']) ? ' <span class="field-suffix">' . $element['#field_suffix'] . '</span>' : '';

  $children = $prefix . $element['#children'] . $suffix;

  // @TODO manipulate field by type > should be done by a widget
  if (!empty($element['#array_parents']) && count($element['#array_parents'])) {
    $field_type = array_pop($element['#array_parents']);
    switch ($field_type) {
      case 'date':
      case 'time':
        // special state
        $element['#title_display'] = 'focus';
        $attributes['class'][] = 'tooltip-onfocus';
        $children = '<div class="field-wrap-' . $field_type . '">' . $children . '</div>';
        break;
    }
  }

  // output handling
  $output = '<div' . drupal_attributes($attributes) . '>' . "\n";

  switch ($element['#title_display']) {
    case 'before':
    case 'invisible':
      $output .= sprintf(
        ' <div class="field-label">%s %s</div> %s' . "\n",
        theme('form_element_label', $variables),
        $desc,
        $children
      );
      break;

    case 'after':
      $output .= sprintf(
        ' %s <div class="field-label">%s %s</div>' . "\n",
        $children,
        theme('form_element_label', $variables),
        $desc
      );
      break;

    case 'focus':
    case 'none':
    case 'attribute':
      // Output no label and no required marker, only the children.
      $output .= ' ' . $children . "\n" . $desc;
      break;
  }

  $output .= "</div>\n";

  return $output;
}
