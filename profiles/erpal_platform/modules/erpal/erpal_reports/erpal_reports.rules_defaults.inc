<?php
/**
 * @file
 * erpal_reports.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function erpal_reports_default_rules_configuration() {
  $items = array();

  $items['rules_create_money_output_entities_for_reports'] = entity_import('rules_config', '{ "rules_create_money_output_entities_for_reports" : {
      "LABEL" : "Create money output entities for reports",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Erpal Reports" ],
      "REQUIRES" : [ "rules", "erpal_reports", "entity" ],
      "ON" : { "commerce_line_item_insert" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "commerce-line-item" ],
            "type" : "commerce_line_item",
            "bundle" : { "value" : { "invoice" : "invoice" } }
          }
        }
      ],
      "DO" : [
        { "erpal_reports_create_money_output" : { "commerce_line_item" : [ "commerce_line_item" ] } }
      ]
    }
  }');
  $items['rules_delete_money_output_on_line_item_deletion'] = entity_import('rules_config', '{ "rules_delete_money_output_on_line_item_deletion" : {
      "LABEL" : "Delete money output on line item deletion",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Erpal Reports" ],
      "REQUIRES" : [ "rules", "erpal_reports", "entity" ],
      "ON" : { "commerce_line_item_delete" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "commerce-line-item" ],
            "type" : "commerce_line_item",
            "bundle" : { "value" : { "invoice" : "invoice" } }
          }
        }
      ],
      "DO" : [
        { "erpal_reports_delete_line_item" : { "commerce_line_item" : [ "commerce_line_item" ] } }
      ]
    }
  }');
  $items['rules_update_output_on_line_item_update'] = entity_import('rules_config', '{ "rules_update_output_on_line_item_update" : {
      "LABEL" : "Update output on line item update",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Erpal Reports" ],
      "REQUIRES" : [ "rules", "erpal_reports", "entity" ],
      "ON" : { "commerce_line_item_update" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "commerce-line-item" ],
            "type" : "commerce_line_item",
            "bundle" : { "value" : { "invoice" : "invoice" } }
          }
        }
      ],
      "DO" : [
        { "erpal_reports_update_line_item" : { "commerce_line_item" : [ "commerce_line_item" ] } }
      ]
    }
  }');

  return $items;
}
