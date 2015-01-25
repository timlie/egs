<?php
/*
 * @file menu-link.theme.inc.
 */

function erpal_theme_menu_link(array $variables) {
  $element = $variables['element'];
  if ($element['#theme'] == 'menu_link__erpal_menu') {
    $element['#localized_options']['attributes']['class'][] = preg_replace('@[^a-z0-9-]+@','-', strtolower($element['#title']));
    $element['#localized_options']['attributes']['title'] = $element['#title'];
  }

  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}