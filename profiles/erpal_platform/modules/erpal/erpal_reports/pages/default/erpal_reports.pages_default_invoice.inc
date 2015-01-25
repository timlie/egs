<?php

/**
 * @file
 * Contains default pages for ERPAL Reports invoice.
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function _erpal_reports_pages_default_invoice() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'invoice_reports';
  $page->task = 'page';
  $page->admin_title = 'Invoice reports';
  $page->admin_description = '';
  $page->path = 'reports/invoices';
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
    'title' => 'Invoices',
    'name' => 'navigation',
    'weight' => '6',
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
  $handler->name = 'page_invoice_reports_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'invoice_reports';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Invoice reports',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '.view-erpal-invoice-reports .view-content {
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
  $display->title = 'Invoice reports';
  $display->uuid = 'b116249a-ff09-4b9a-8bb3-14b901a849a2';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-aaa47e75-7c03-428a-bf14-e4c820458c55';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'erpal_invoice_reports-ingoing_pane';
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
  $pane->uuid = 'aaa47e75-7c03-428a-bf14-e4c820458c55';
  $display->content['new-aaa47e75-7c03-428a-bf14-e4c820458c55'] = $pane;
  $display->panels['middle'][0] = 'new-aaa47e75-7c03-428a-bf14-e4c820458c55';
  $pane = new stdClass();
  $pane->pid = 'new-9c3ce1f5-98e7-4873-8beb-16dc0238f82c';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'erpal_invoice_reports-outgoing_pane';
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
  $pane->uuid = '9c3ce1f5-98e7-4873-8beb-16dc0238f82c';
  $display->content['new-9c3ce1f5-98e7-4873-8beb-16dc0238f82c'] = $pane;
  $display->panels['middle'][1] = 'new-9c3ce1f5-98e7-4873-8beb-16dc0238f82c';
  $pane = new stdClass();
  $pane->pid = 'new-ef7327c1-ad5a-42ee-b48c-380dd7a1ef19';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'erpal_invoice_reports-tax_pane';
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
  $pane->uuid = 'ef7327c1-ad5a-42ee-b48c-380dd7a1ef19';
  $display->content['new-ef7327c1-ad5a-42ee-b48c-380dd7a1ef19'] = $pane;
  $display->panels['middle'][2] = 'new-ef7327c1-ad5a-42ee-b48c-380dd7a1ef19';
  $pane = new stdClass();
  $pane->pid = 'new-3189186c-f3e8-4714-941e-c013e6b6bf9b';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'erpal_invoice_reports-not_billed_pane';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '3189186c-f3e8-4714-941e-c013e6b6bf9b';
  $display->content['new-3189186c-f3e8-4714-941e-c013e6b6bf9b'] = $pane;
  $display->panels['middle'][3] = 'new-3189186c-f3e8-4714-941e-c013e6b6bf9b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;

  return $page;
}
