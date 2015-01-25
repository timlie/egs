<?php

/**
 * @file
 * Contains default pages for ERPAL Reports quote.
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function _erpal_reports_pages_default_quote() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'quote_reports';
  $page->task = 'page';
  $page->admin_title = 'Quote reports';
  $page->admin_description = '';
  $page->path = 'reports/quotes';
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
    'title' => 'Quotes',
    'name' => 'navigation',
    'weight' => '2',
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
  $handler->name = 'page_quote_reports_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'quote_reports';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Quote reports',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '.view-erpal-quote-reports .view-content {
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
  $display->title = 'Quote reports';
  $display->uuid = 'b116249a-ff09-4b9a-8bb3-14b901a849a2';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-e54f28e2-e99d-443b-922d-8402b0a6761c';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'erpal_quote_reports-ingoing_pane';
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
  $pane->uuid = 'e54f28e2-e99d-443b-922d-8402b0a6761c';
  $display->content['new-e54f28e2-e99d-443b-922d-8402b0a6761c'] = $pane;
  $display->panels['middle'][0] = 'new-e54f28e2-e99d-443b-922d-8402b0a6761c';
  $pane = new stdClass();
  $pane->pid = 'new-64e6631e-303b-4338-9421-984fa414bf11';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'erpal_quote_reports-outgoing_pane';
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
  $pane->uuid = '64e6631e-303b-4338-9421-984fa414bf11';
  $display->content['new-64e6631e-303b-4338-9421-984fa414bf11'] = $pane;
  $display->panels['middle'][1] = 'new-64e6631e-303b-4338-9421-984fa414bf11';
  $pane = new stdClass();
  $pane->pid = 'new-5ac186a4-d51b-44d0-a597-6555b8f01c16';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'erpal_quote_reports-tax_pane';
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
  $pane->uuid = '5ac186a4-d51b-44d0-a597-6555b8f01c16';
  $display->content['new-5ac186a4-d51b-44d0-a597-6555b8f01c16'] = $pane;
  $display->panels['middle'][2] = 'new-5ac186a4-d51b-44d0-a597-6555b8f01c16';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;

  return $page;
}
