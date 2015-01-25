<?php
/**
 * @file
 * Template for erpalsitetemplate.
 *
 * This template provides a two column panel display layout, with
 * additional areas for the top and the bottom.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['top']: Content in the top row.
 *   - $content['left']: Content in the left column.
 *   - $content['right']: Content in the right column.
 *   - $content['bottom']: Content in the bottom row.
 */
?>
<div class="erpalsitetemplate-pageheader">
  <div class="inner">
    <div class="erpalsitetemplate-pageheaderleft">
      <?php print $content['page-header-left']; ?>
    </div>
    <div class="erpalsitetemplate-pageheaderright">
      <?php print $content['page-header-right']; ?>
    </div>
    <div class="clearfix"></div>
  </div>
</div>


<div
  class="erpalsitetemplate <?php print isset($collapsed_sidebar)? $collapsed_sidebar : '' ?>" <?php if (!empty($css_id)) {
  print "id=\"$css_id\"";
} ?>>

  <div class="erpalsitetemplate-left">
    <h2 class="region-title"><?php print t('Menu'); ?></h2>

    <div class="wrapper">
      <?php print $content['left']; ?>
    </div>
  </div>
  <div class="erpalsitetemplate-content">
    <div class="erpalsitetemplate-right">
      <div class="erpalsitetemplate-right-tabs">
        <?php print $content['righttabs']; ?>
      </div>
      <div class="erpalsitetemplate-right-content">
        <?php print $content['right']; ?>
      </div>
    </div>
    <?php if ($content['bottom']): ?>
      <div class="erpalsitetemplate-bottom">
        <?php print $content['bottom']; ?>
      </div>
    <?php endif; ?>
  </div>

</div>
