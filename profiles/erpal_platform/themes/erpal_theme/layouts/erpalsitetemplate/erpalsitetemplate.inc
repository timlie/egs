<?php

// Plugin definition
$plugin = array(
  'title' => t('ERPAL site template'),
  'category' => t('ERPAL'),
  'icon' => 'erpalsitetemplate.png',
  'theme' => 'erpalsitetemplate',
  'css' => 'erpalsitetemplate.css',
  'regions' => array(
    'page-header-left' => t('Page header left'),
    'page-header-right' => t('Page header right'),
    'left' => t('Left side'),
    'righttabs' => t('Right side tabs'),
    'right' => t('Right side content'),
    'bottom' => t('Bottom')
  ),
);
