/*jshint -W032 */;/*jshint +W032 */
(function ($) {
  Drupal.behaviors.erpalThemeMenuHide = {
    attach: function (context, settings) {
      var cookieName = 'erpal-collapsed-sidebar',
        collapsedClass = 'collapsed-sidebar',
        $el = $('.erpalsitetemplate');

      $('.erpalsitetemplate-left .region-title', context).click(function () {
        if ($.cookie(cookieName) == 'true') {
          $.cookie(cookieName, 'false', { path: '/' });
          $el.removeClass(collapsedClass);
        } else {
          $.cookie(cookieName, 'true', { path: '/' });
          $el.addClass(collapsedClass);
        }
      });
    }
  };

  // temporary helper to move the tabs to the desired destination
  // "nothing is more permanent than the temporary" - Greek proverb
  Drupal.behaviors.erpalMoveTabs = {
    attach: function (context, settings) {
      var tabs = $('.pane-page-content .ui-tabs-nav');
      //change classes to match drupal default tabs classes
      tabs.removeClass('ui-tabs-nav ui-helper-reset ui-helper-clearfix ui-widget-header ui-corner-all')
        .addClass('tabs links--inline')
        .children('li').removeClass('ui-state-default ui-corner-top');
      $('.erpalsitetemplate-right-tabs .tabs').before(tabs);
    }
  };

  // wrap upload-inputs to give them some style
  // "who needs a medical-license if you got style" - Dr. Zed
  Drupal.behaviors.fileuploadWithStyle = {
    attach: function () {
      $('input[type="file"]').fileUpload({
        fieldText:  Drupal.t('No File Selected'),
        buttonText: Drupal.t('Select File')
      });
    }
  };

  // bootstrap tooltips, bootstrap tooltips everywhere.
  Drupal.behaviors.tooltips = {
    attach: function () {
      $('[data-toggle="tooltip"]').tooltipster({
        contentAsHTML: true,
        delay: 50
      });
      $('.pane-menu-erpal-menu a').tooltipster({
        position: 'right',
        contentAsHTML: true,
        delay: 50
      });
    }
  };

  // budget-widget project & task table helper
  Drupal.behaviors.budgetWidgetTable = {
    attach: function () {
      $('.budget-row').each(function () {
        var $self = $(this);
        $self.find('.budget-wrapper').detach().appendTo($self);
      });
    }
  };


  // add class to body inside a jq ui dialog iframe
  Drupal.behaviors.iframeDetection = {
    attach: function () {
      function inIframe () {
        try {
          return window.self !== window.top;
        } catch (e) {
          return true;
        }
      }

      if (inIframe()) {
        $('body').addClass('iniframe');
      }
    }
  };
})(jq1111);
