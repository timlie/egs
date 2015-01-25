<?php
/**
 * @file
 * Template for erpaltworow.
 *
 * This template provides a two column panel display layout, with
 * additional areas for the top and the bottom.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 */
?>
<div class="erpaltworow">
  <div class="erpaltworow-header">
    <?php print $content['header']; ?>
  </div>
  <div class="erpaltworow-body">
    <?php print $content['body']; ?>
  </div>
</div>

