<?php

/**
 * Implements hook_preprocess_erpalsitetemplate().
 */
function erpal_theme_preprocess_erpalsitetemplate(&$variables) {
  // You can use preprocess hooks to modify the variables before they are passed
  // to the theme function or template file.
//  dpm($variables,'variables');
  if(isset($_COOKIE['erpal-collapsed-sidebar']) && $_COOKIE['erpal-collapsed-sidebar'] == 'true'){
    $variables['collapsed_sidebar'] = 'collapsed-sidebar';
  }else{
    $variables['collapsed_sidebar'] = '';
  }
}
