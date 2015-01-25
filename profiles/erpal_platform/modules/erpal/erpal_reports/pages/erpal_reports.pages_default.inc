<?php

/**
 * @file
 * Contains default pages for ERPAL Reports.
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function erpal_reports_default_page_manager_pages() {
  $pages = array();
  $default_pages = array(
    'dashboard',
    'invoice',
    'order',
    'quote',
  );

  // Include files with default pages.
  foreach ($default_pages as $page_name) {
    module_load_include('inc', 'erpal_reports', 'pages/default/erpal_reports.pages_default_' . $page_name);
    $page = call_user_func('_erpal_reports_pages_default_' . $page_name);
    $pages[$page->name] = $page;
  }

  return $pages;
}
