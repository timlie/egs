<?php
/*
 * @file form-element.theme.inc.
 */

/*
 * Implements theme_field().
 */
function erpal_theme_field($variables, $tag = 'div', $itemsep = '') {
  $label = '';
  $items = array();
  // additional markup
  $renderTitleOnField = false;
  $titleAttr = '';


  // prepare rendering
  // - contact-data field
  if ($variables['field_name_css'] == 'field-contact-data-privacy') {
    // add custom class based on output
    $variables['classes'] .= ' contact-data-privacy contact-data-privacy-'
      . strtolower($variables['element'][0]['#markup']);

    // enable title rendering
    $renderTitleOnField = $variables['element'][0]['#markup'];
  }


  // Render the label, if it's not hidden.
  if (!$variables['label_hidden']) {
    $label = sprintf(
      '<div class="field-label" %1$s>%2$s:&nbsp;</div>',
      $variables['title_attributes'],
      $variables['label']
    );
  }


  // prepare title-attribute rendering... or not?
  if ($renderTitleOnField !== false) {
    $titleAttr = 'title="' . $renderTitleOnField . '"';
  }


  // render the items
  foreach ($variables['items'] as $delta => $item) {
    array_push($items, sprintf(
      '<div class="field-item %1$s" %2$s>%3$s</div>',
      ($delta % 2) ? 'odd' : 'even',
      $variables['item_attributes'][$delta],
      drupal_render($item)
    ));
  }

  // implode & wrap the items
  $items = '<div class="field-items"' . $variables['content_attributes'] .
    '>' . implode('', $items) . '</div>';


  // render the top-level DIV.
  $output = sprintf(
    '<%1$s class="%2$s" %3$s %4$s>%5$s</%1$s>',
    $tag,
    $variables['classes'],
    $variables['attributes'],
    $titleAttr,
    $label . $items
  );

  return $output;
}
