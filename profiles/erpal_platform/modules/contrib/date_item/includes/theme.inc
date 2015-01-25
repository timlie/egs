<?php

/**
 * @file
 * Theme functions for the Date Item module.
 */

/**
 * Implements hook_theme().
 */
function date_item_theme() {
  return array(
    'date_item' => array(
      'render element' => 'element',
    ),
  );
}

/**
 * Output fields without entity object wrapper.
 */
function theme_date_item($variables) {
  return render($variables['content']);
}
