<?php
/*
 * @file views-view-field--erpal-crm-activities--type.theme.inc.
 */

/*
 * Implements theme_views_view_field().
 */
function erpal_theme_views_view_field__erpal_crm_activities__type(&$variables) {
  $type = $variables['output'];

  return sprintf(
    '<span class="activity-type activity-type-%1$s" title="%2$s">%2$s</span>',
    strtolower(preg_replace(array('/[^a-zA-Z0-9 -]/', '/[ -]+/', '/^-|-$/'),
      array('', '-', ''), $type)),
    $type
  );
}
