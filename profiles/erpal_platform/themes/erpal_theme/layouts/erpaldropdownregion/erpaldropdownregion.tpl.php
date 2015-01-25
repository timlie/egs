<?php
/**
 * @file
 * Template for erpaldropdownregion.
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
<div class="erpaldropdownregion">
  <div class="erpaldropdownregion-trigger">
    <?php print $content['trigger']; ?>
    <div class="erpaldropdownregion-dropdown">
      <?php print $content['dropdown']; ?>
    </div>
  </div>
</div>

