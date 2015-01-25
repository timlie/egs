<?php

/**
 * @file
 * Views for the ERPAL reports.
 */

/**
 * Implements hook_views_default_views().
 */
function erpal_reports_views_default_views() {
  $views = array();
  $default_views = array(
    'invoice',
    'order',
    'quote',
  );

  // Include files with default pages.
  foreach ($default_views as $view_name) {
    module_load_include('inc', 'erpal_reports', 'views/default/erpal_reports.views_default_' . $view_name);
    $view = call_user_func('_erpal_reports_views_default_' . $view_name);
    $views[$view->name] = $view;
  }

  return $views;
}
