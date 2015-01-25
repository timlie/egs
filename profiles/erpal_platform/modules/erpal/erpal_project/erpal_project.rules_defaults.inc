<?php
/**
 * @file
 * erpal_project.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function erpal_project_default_rules_configuration() {
  $items = array();

  $items['rules_create_core_stuff_for_projects_and_tasks'] = entity_import('rules_config', '{ "rules_create_core_stuff_for_projects_and_tasks" : {
      "LABEL" : "Create erpal core stuff for projects and tasks",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Erpal Project" ],
      "REQUIRES" : [ "rules", "erpal_project" ],
      "ON" : { "node_insert" : [] },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "erpal_project" : "erpal_project", "erpal_task" : "erpal_task" } }
          }
        }
      ],
      "DO" : [
        { "erpal_project_create_acceptance" : { "node" : [ "node" ] } },
        { "erpal_project_create_budgets" : { "node" : [ "node" ] } }
      ]
    }
  }');

  $items['rules_set_project_or_task_to_delivered_or_not'] = entity_import('rules_config', '{ "rules_set_project_or_task_to_delivered_or_not" : {
      "LABEL" : "Set project or task to delivered or not",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Erpal Project" ],
      "REQUIRES" : [ "rules", "erpal_project" ],
      "ON" : { "node_update" : [] },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "erpal_project" : "erpal_project", "erpal_task" : "erpal_task" } }
          }
        }
      ],
      "DO" : [
        { "erpal_project_delivery_action" : { "node" : [ "node" ], "node_unchanged" : [ "node_unchanged" ] } }
      ]
    }
  }');

  $items['rules_after_project_task_update_recreate_all_data'] = entity_import('rules_config', '{ "rules_after_project_task_update_recreate_all_data" : {
      "LABEL" : "After project\/task update recreate all data",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Erpal Project" ],
      "REQUIRES" : [ "rules", "erpal_project" ],
      "ON" : { "node_update" : [] },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "erpal_project" : "erpal_project", "erpal_task" : "erpal_task" } }
          }
        }
      ],
      "DO" : [
        { "erpal_project_update" : { "node" : [ "node" ], "node_unchanged" : [ "node_unchanged" ] } }
      ]
    }
  }');

  $items['rules_delete_project_or_task'] = entity_import('rules_config', '{ "rules_delete_project_or_task" : {
      "LABEL" : "Delete project or task",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Erpal Project" ],
      "REQUIRES" : [ "rules", "erpal_project" ],
      "ON" : { "node_delete" : [] },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "erpal_project" : "erpal_project", "erpal_task" : "erpal_task" } }
          }
        }
      ],
      "DO" : [ { "erpal_project_delete" : { "node" : [ "node" ] } } ]
    }
  }');

  $items['rules_check_if_need_create_invoice_line_item_on_time_insert'] = entity_import('rules_config', '{ "rules_check_if_need_create_invoice_line_item_on_time_insert" : {
      "LABEL" : "Check if need create/update invoice line item on time insert/update",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "5",
      "OWNER" : "rules",
      "TAGS" : [ "Erpal Project" ],
      "REQUIRES" : [ "rules", "erpal_project", "erpal_output" ],
      "ON" : { "erpal_output_presave" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "erpal-output" ],
            "type" : "erpal_output",
            "bundle" : { "value" : { "time" : "time" } }
          }
        }
      ],
      "DO" : [
        { "erpal_project_update_time" : { "erpal_output" : [ "erpal_output" ] } }
      ]
    }
  }');

  $items['rules_check_if_need_delete_invoice_line_item_on_time_delete'] = entity_import('rules_config', '{ "rules_check_if_need_delete_invoice_line_item_on_time_delete" : {
    "LABEL" : "Check if need delete invoice line item on time delete",
    "PLUGIN" : "reaction rule",
    "OWNER" : "rules",
    "TAGS" : [ "Erpal Project" ],
    "REQUIRES" : [ "erpal_project", "erpal_output" ],
    "ON" : { "erpal_output_delete" : [] },
    "DO" : [
      { "erpal_project_delete_time" : { "erpal_output" : [ "erpal_output" ] } }
    ]
  }
}');
  return $items;
}
