<?php
/*
 * @file date_display_single.theme.inc.
 */

/*
 * Implements theme_date_display_single().
 * better time/date display using html5-tag
 */
function erpal_theme_date_display_single(&$variables) {
  return sprintf(
    '<time datetime="%1$s" class="date-display-single" %2$s>%3$s</time>',
    $variables['dates']['value']['formatted_iso'],
    drupal_attributes($variables['attributes']),
    $variables['date'] . $variables['timezone']
  );
}
