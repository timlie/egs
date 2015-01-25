<?php
/*
 * @file ctools-menu-local-actions-wrapper.theme.inc.
 */

/*
 * Implements theme_ctools_menu_local_actions_wrapper().
 * It renders the local actions to be a bootstrap button dropdown.
 */
function erpal_theme_ctools_menu_local_actions_wrapper($variables){
  $links = drupal_render($variables['links']);

  if (empty($links)) {
    return;
  }
  $output = '';
//  $output .= '<ul class="action-links">' . $links . '</ul>';
  $output .= '<div class="btn-group">';
  $output .= '<button type="button" class="btn btn-primary">'.t('Actions').'</button>';
  $output .= '<button type="button" class="btn btn-primary dropdown-toggle" data-toggle="dropdown">';
  $output .= '<span class="caret"></span>';
  $output .= '<span class="sr-only">Toggle Dropdown</span>';
  $output .= '</button>';
  $output .= '<ul class="dropdown-menu" role="menu">';
  $output .= $links;
  $output .= '</ul>';
  $output .= '</div>';
  return $output;
}
