<?php
/**
 * @file
 * erpal_project_ui.cat.inc
 */

/**
 * Implements hook_cat_items_settings_info().
 */
function erpal_project_ui_cat_items_settings_info() {
  $export = array();
  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'add_project';
  $cat_item->name = 'Add project';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = '';
  $cat_item->path = 'projects';
  $cat_item->data = array(
    'access' => array(),
    'active_trail_path' => '',
    'arguments' => array(),
    'name' => 'Add project',
    'path' => 'projects',
    'category' => '',
    'cat_actions' => array(
      0 => array(
        'path' => 'node/add/erpal-project',
        'path_router' => 'node/add/erpal-project',
        'path_original' => 'node/add/erpal-project',
        'path_pattern' => 'node/%/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Add project',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
    ),
    'cat_tabs' => array(),
    'machine_name' => 'add_project',
    'path_original' => 'projects',
    'path_pattern' => 'projects',
    'path_query' => array(),
    'path_router' => 'projects',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = 0;

  $export['add_project'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'add_task';
  $cat_item->name = 'Add task';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = '';
  $cat_item->path = 'node/%';
  $cat_item->data = array(
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_project' => 'erpal_project',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => '',
    'arguments' => array(
      1 => array(
        'argument_name' => 'node',
        'argument_type' => 'path',
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'name' => 'Add task',
    'path' => 'node/%',
    'category' => '',
    'cat_actions' => array(
      0 => array(
        'path' => 'node/add/erpal-task',
        'path_router' => 'node/add/erpal-task',
        'path_original' => 'node/add/erpal-task',
        'path_pattern' => 'node/%/%',
        'path_query' => array(
          'project' => '[node:nid]',
        ),
        'path_destination' => FALSE,
        'title' => 'Add task',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
    ),
    'cat_tabs' => array(),
    'machine_name' => 'add_task',
    'path_original' => 'node/%node',
    'path_pattern' => 'node/%',
    'path_query' => array(),
    'path_router' => 'node/%',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = 0;
  $export['add_task'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'create_time_tracking';
  $cat_item->name = 'Create Time tracking';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = '';
  $cat_item->path = 'node/%';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:node',
          'settings' => array(
            'type' => array(
              'erpal_project' => 'erpal_project',
              'erpal_task' => 'erpal_task',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => '',
    'arguments' => array(
      1 => array(
        'argument_name' => 'node',
        'argument_type' => 'path',
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'name' => 'Create Time tracking',
    'path' => 'node/%',
    'category' => '',
    'cat_actions' => array(
      0 => array(
        'path' => 'output/add/time',
        'path_router' => 'output/add/time',
        'path_original' => 'output/add/time',
        'path_pattern' => 'output/%/%',
        'path_query' => array(
          'task' => '[node:nid]',
        ),
        'path_destination' => TRUE,
        'title' => 'Create Time tracking',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
    ),
    'cat_tabs' => array(),
    'machine_name' => 'create_time_tracking',
    'path_original' => 'node/%node',
    'path_pattern' => 'node/%',
    'path_query' => array(),
    'path_router' => 'node/%',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = 0;
  $export['create_time_tracking'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'create_project_budget';
  $cat_item->name = 'Create project budget';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = '';
  $cat_item->path = 'node/%';
  $cat_item->data = array(
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:node',
          'settings' => array(
            'type' => array(
              'erpal_project' => 'erpal_project',
              'erpal_task' => 'erpal_task',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => '',
    'arguments' => array(
      1 => array(
        'argument_name' => 'node',
        'argument_type' => 'path',
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'name' => 'Create project budget',
    'path' => 'node/%',
    'category' => '',
    'cat_actions' => array(
      0 => array(
        'path' => 'budget/add',
        'path_router' => 'budget/add',
        'path_original' => 'budget/add',
        'path_pattern' => 'budget/%',
        'path_query' => array(
          'field_resource' => '[node:field-resource:resource-id]',
        ),
        'path_destination' => FALSE,
        'title' => 'Create budget',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
      ),
    ),
    'cat_tabs' => array(),
    'machine_name' => 'create_project_budget',
    'path_original' => 'node/%node',
    'path_pattern' => 'node/%',
    'path_query' => array(),
    'path_router' => 'node/%',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = 0;
  $export['create_project_budget'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'create_subtask';
  $cat_item->name = 'Create Sub-task';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = '';
  $cat_item->path = 'node/%';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:node',
          'settings' => array(
            'type' => array(
              'erpal_task' => 'erpal_task',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => '',
    'arguments' => array(
      1 => array(
        'argument_name' => 'node',
        'argument_type' => 'path',
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'name' => 'Create Sub-task',
    'path' => 'node/%',
    'category' => '',
    'cat_actions' => array(
      0 => array(
        'path' => 'node/add/erpal-task',
        'path_router' => 'node/add/erpal-task',
        'path_original' => 'node/add/erpal-task',
        'path_pattern' => 'node/%/%',
        'path_query' => array(
          'field_task_parent' => '[node:nid]',
        ),
        'path_destination' => TRUE,
        'title' => 'Create subtask',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
    ),
    'cat_tabs' => array(),
    'machine_name' => 'create_subtask',
    'path_original' => 'node/%node',
    'path_pattern' => 'node/%',
    'path_query' => array(),
    'path_router' => 'node/%',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = 0;
  $export['create_subtask'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'create_expense';
  $cat_item->name = 'Create Expense';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = '';
  $cat_item->path = 'node/%';
  $cat_item->data = array(
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_project' => 'erpal_project',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => '',
    'arguments' => array(
      1 => array(
        'argument_name' => 'node',
        'argument_type' => 'path',
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'name' => 'Create Expense',
    'path' => 'node/%',
    'category' => '',
    'cat_actions' => array(
      0 => array(
        'path' => 'output/add/money',
        'path_router' => 'output/add/money',
        'path_original' => 'output/add/money',
        'path_pattern' => 'output/%/%',
        'path_query' => array(
          'field_resource' => '[node:field-resource:resource-id]',
        ),
        'path_destination' => FALSE,
        'title' => 'Create expense',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
      ),
    ),
    'cat_tabs' => array(),
    'machine_name' => 'create_expense',
    'path_original' => 'node/%node',
    'path_pattern' => 'node/%',
    'path_query' => array(),
    'path_router' => 'node/%',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = 0;
  $export['create_expense'] = $cat_item;


  return $export;
}
