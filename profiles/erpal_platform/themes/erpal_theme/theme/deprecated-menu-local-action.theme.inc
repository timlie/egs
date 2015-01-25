<?php
/*
 * @file menu-local-action.theme.inc.
 */

/*
 * Implements theme_menu_local_action().
 * It renders the local actions to be a bootstrap button dropdown.
 */
function erpal_theme_menu_local_action($variables) {
  $link = $variables['element']['#link'];

  $output = '';
  $output .= '<li>';
  if (isset($link['href'])) {
    $output .= l($link['title'], $link['href'], isset($link['localized_options']) ? $link['localized_options'] : array());
  }
  elseif (!empty($link['localized_options']['html'])) {
    $output .= $link['title'];
  }
  else {
    $output .= check_plain($link['title']);
  }
  $output .= "</li>\n";

  return $output;
}
