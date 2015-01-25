<?php

/**
 * @file
 * Contains default pages for ERPAL Reports dashboard.
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function _erpal_reports_pages_default_dashboard() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'report_dashboard';
  $page->task = 'page';
  $page->admin_title = 'Report Dashboard';
  $page->admin_description = '';
  $page->path = 'reports/dashboard';
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
    'type' => 'default tab',
    'title' => 'Dashboard',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'normal',
      'title' => 'Reports',
      'name' => 'erpal-menu',
      'weight' => '10',
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
  $handler->name = 'page_report_dashboard_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'report_dashboard';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Report dashboard',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
    'middle' => array(
      'style' => 'default',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '3921845a-7aae-4d9a-a281-fee5e3be9db6';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-13d189ec-6ff1-45c0-862a-09f0bfc2528b';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Empty text',
    'title' => '',
    'body' => 'Sorry, currently this page in development status. <br />
You can find info on separated tabs:
<ul class="links--inline">
<li><a href="reports/quotes">Quotes</a></li>
<li><a href="reports/orders">Orders</a></li>
<li><a href="reports/invoices">Invoices</a></li>
</ul>',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '13d189ec-6ff1-45c0-862a-09f0bfc2528b';
  $display->content['new-13d189ec-6ff1-45c0-862a-09f0bfc2528b'] = $pane;
  $display->panels['middle'][0] = 'new-13d189ec-6ff1-45c0-862a-09f0bfc2528b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;

  return $page;
}
