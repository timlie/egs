(function($) {
  /**
   * Initialization
   */
  Drupal.behaviors.jquery_ui_multiselect_widget = {
    /**
     * Run Drupal module JS initialization.
     * 
     * @param context
     * @param settings
     */
    attach: function(context, settings) {
      var multiselects = new Array();
      // Global context!
      var filter = "select";
      if (settings.jquery_ui_multiselect_widget.multiple) {
        // Multiple only
        filter = filter + '[multiple=multiple]';
      }
      var elements = $(context).find(filter);
      if (jQuery.trim(settings.jquery_ui_multiselect_widget.subselector) != '') {
        // Subselector
        elements = elements.filter(settings.jquery_ui_multiselect_widget.subselector);
      }
      // Convert int 1 to boolean so that the header works correctly.
      if (settings.jquery_ui_multiselect_widget.header === 1) {
        settings.jquery_ui_multiselect_widget.header = true;
      }
      elements.each(function () {
        // In case of ajax loading without this check the widget is applied multiple times and eventually stops working
        if (!$(this).hasClass('multiProcessed')) {
          $(this).addClass('multiProcessed');
          var isMultiselect = $(this).is('[multiple]');
          var multiselect = $(this).multiselect({
            // Get default options from drupal to make them easier accessible.
            selectedList: settings.jquery_ui_multiselect_widget.selectedlist,
            selectedText: function (numChecked, numTotal, checkedItems) {
              // Override text to make it translateable.
              return Drupal.t('@numChecked of @numTotal checked', {'@numChecked': numChecked, '@numTotal': numTotal});
            },
            multiple: isMultiselect,
            autoOpen: settings.jquery_ui_multiselect_widget.autoOpen,
            header: settings.jquery_ui_multiselect_widget.header,
            height: settings.jquery_ui_multiselect_widget.height,
            classes: settings.jquery_ui_multiselect_widget.classes,
            checkAllText: Drupal.t('Check all'),
            uncheckAllText: Drupal.t('Uncheck all'),
            noneSelectedText: Drupal.t('Select option(s)'),
            selectedText: Drupal.t('# selected')
          });
          if (settings.jquery_ui_multiselect_widget.filter) {
            // Allow filters
            multiselect.multiselectfilter({
              label: Drupal.t('Filter'),
              placeholder: Drupal.t('Enter keywords'),
              width: settings.jquery_ui_multiselect_widget.filter_width,
              autoReset: settings.jquery_ui_multiselect_widget.filter_auto_reset
            });
          }
          multiselects.push(multiselect);
        }
      });

      // Attach object globally to make access easy for custom usage.
      Drupal.behaviors.jquery_ui_multiselect_widget.multiselect = {multiselects: multiselects};
    }
  };
})(jQuery);