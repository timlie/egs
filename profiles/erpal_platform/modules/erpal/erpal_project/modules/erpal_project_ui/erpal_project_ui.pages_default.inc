<?php

/**
 * @file
 * Contains default pages for ERPAL project UI module.
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function erpal_project_ui_default_page_manager_handlers() {
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Project',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_project' => 'erpal_project',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
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
  $display->title = '';
  $display->uuid = 'eee665cc-8719-4644-82fa-0bba05b728d3';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-5bfcf435-ceb8-434c-9910-e0394ef60535';
  $pane->panel = 'middle';
  $pane->type = 'entity_view';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => 'Project',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '5bfcf435-ceb8-434c-9910-e0394ef60535';
  $display->content['new-5bfcf435-ceb8-434c-9910-e0394ef60535'] = $pane;
  $display->panels['middle'][0] = 'new-5bfcf435-ceb8-434c-9910-e0394ef60535';
  $pane = new stdClass();
  $pane->pid = 'new-263fac26-3cc7-432f-ad04-ec5dcb2af7f2';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'erpal_project-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_entity_id:node_1',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '263fac26-3cc7-432f-ad04-ec5dcb2af7f2';
  $display->content['new-263fac26-3cc7-432f-ad04-ec5dcb2af7f2'] = $pane;
  $display->panels['middle'][1] = 'new-263fac26-3cc7-432f-ad04-ec5dcb2af7f2';
  $pane = new stdClass();
  $pane->pid = 'new-a46cdc4b-5d8c-45bd-82c9-c3a2c09be5a1';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'erpal_project_budget-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'a46cdc4b-5d8c-45bd-82c9-c3a2c09be5a1';
  $display->content['new-a46cdc4b-5d8c-45bd-82c9-c3a2c09be5a1'] = $pane;
  $display->panels['middle'][2] = 'new-a46cdc4b-5d8c-45bd-82c9-c3a2c09be5a1';
  $pane = new stdClass();
  $pane->pid = 'new-ca939224-3927-4883-805c-6efc044c4108';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'erpal_invoice_line_items-panel_pane_2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_entity_id:node_1',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'ca939224-3927-4883-805c-6efc044c4108';
  $display->content['new-ca939224-3927-4883-805c-6efc044c4108'] = $pane;
  $display->panels['middle'][3] = 'new-ca939224-3927-4883-805c-6efc044c4108';
  $pane = new stdClass();
  $pane->pid = 'new-55d927f7-0287-4653-a8b7-f59f5ac04200';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'erpal_project_output-panel_pane_3';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '55d927f7-0287-4653-a8b7-f59f5ac04200';
  $display->content['new-55d927f7-0287-4653-a8b7-f59f5ac04200'] = $pane;
  $display->panels['middle'][4] = 'new-55d927f7-0287-4653-a8b7-f59f5ac04200';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;

  $export['node_view_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_2';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Task',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_task' => 'erpal_task',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
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
  $display->title = '';
  $display->uuid = '89f4a5cf-15d7-4226-a3d0-92a6e7281824';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-ff6f8048-e57a-41e8-a798-39cf1cc96cd1';
  $pane->panel = 'middle';
  $pane->type = 'entity_view';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => 'Task',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'ff6f8048-e57a-41e8-a798-39cf1cc96cd1';
  $display->content['new-ff6f8048-e57a-41e8-a798-39cf1cc96cd1'] = $pane;
  $display->panels['middle'][0] = 'new-ff6f8048-e57a-41e8-a798-39cf1cc96cd1';
  $pane = new stdClass();
  $pane->pid = 'new-5511fc57-2037-4571-820e-82823ce04279';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'erpal_project_budget-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '5511fc57-2037-4571-820e-82823ce04279';
  $display->content['new-5511fc57-2037-4571-820e-82823ce04279'] = $pane;
  $display->panels['middle'][1] = 'new-5511fc57-2037-4571-820e-82823ce04279';
  $pane = new stdClass();
  $pane->pid = 'new-636281d3-3b8c-4a7a-a564-686ae768bf7e';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'erpal_time_tracking-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_entity_id:node_1',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '636281d3-3b8c-4a7a-a564-686ae768bf7e';
  $display->content['new-636281d3-3b8c-4a7a-a564-686ae768bf7e'] = $pane;
  $display->panels['middle'][2] = 'new-636281d3-3b8c-4a7a-a564-686ae768bf7e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_2'] = $handler;

  return $export;
}
