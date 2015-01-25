<?php

// Plugin definition
$plugin = array(
  'title' => t('ERPAL dropdown region'),
  'category' => t('ERPAL'),
  'icon' => 'erpaldropdownregion.png',
  'theme' => 'erpaldropdownregion',
  'css' => 'erpaldropdownregion.css',
  'regions' => array(
    'trigger' => t('Trigger'),
    'dropdown' => t('Dropdown')
  ),
);


//// Preprocess this layout.
//function erpal_theme_preprocess_erpaldropdownregion(&$vars) {
//  drupal_add_js($vars['layout']['path'] . '/erpaldropdownregion.js', 'file');
//}
