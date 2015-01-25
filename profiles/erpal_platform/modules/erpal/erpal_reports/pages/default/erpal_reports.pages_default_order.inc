<?php

/**
 * @file
 * Contains default pages for ERPAL Reports order.
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function _erpal_reports_pages_default_order() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'order_reports';
  $page->task = 'page';
  $page->admin_title = 'Order reports';
  $page->admin_description = '';
  $page->path = 'reports/orders';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'view erpal reports',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Orders',
    'name' => 'navigation',
    'weight' => '4',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_order_reports_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'order_reports';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Order reports',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '.view-erpal-reports-basic .view-content {
  clear: both;
}',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => array(
        'region_title' => '',
        'region_title_tag' => 'none',
        'region_class' => '',
        'panel_tab_id_pattern' => 'region',
      ),
    ),
    'middle' => array(
      'style' => 'tabs',
    ),
  );
  $display->cache = array();
  $display->title = 'Order reports';
  $display->uuid = 'b116249a-ff09-4b9a-8bb3-14b901a849a2';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-0e239097-d8e3-40c9-992b-91af69e31250';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'erpal_reports_basic-ingoing_pane';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '0e239097-d8e3-40c9-992b-91af69e31250';
  $display->content['new-0e239097-d8e3-40c9-992b-91af69e31250'] = $pane;
  $display->panels['middle'][0] = 'new-0e239097-d8e3-40c9-992b-91af69e31250';
  $pane = new stdClass();
  $pane->pid = 'new-c1fecbc1-2976-4e51-8530-13c91ebadc73';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'erpal_reports_basic-outgoing_pane';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'c1fecbc1-2976-4e51-8530-13c91ebadc73';
  $display->content['new-c1fecbc1-2976-4e51-8530-13c91ebadc73'] = $pane;
  $display->panels['middle'][1] = 'new-c1fecbc1-2976-4e51-8530-13c91ebadc73';
  $pane = new stdClass();
  $pane->pid = 'new-1d06e9a7-83c6-4bb8-8032-ad8ac11e30c3';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'erpal_reports_basic-tax_pane';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '1d06e9a7-83c6-4bb8-8032-ad8ac11e30c3';
  $display->content['new-1d06e9a7-83c6-4bb8-8032-ad8ac11e30c3'] = $pane;
  $display->panels['middle'][2] = 'new-1d06e9a7-83c6-4bb8-8032-ad8ac11e30c3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;

  return $page;
}
