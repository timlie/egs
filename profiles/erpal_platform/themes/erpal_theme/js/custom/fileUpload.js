/*jshint -W032 */;/*jshint +W032 */
(function ($, window, document, undefined) {
  $.fn.fileUpload = function (options) {
    var settings = $.extend(
        {
          fieldText:   'No File Selected',
          buttonText:  'Select File',
          wrapContent: '<div class="ui-fileupload"></div>',
          fakeContent: '<div class="fake"><button></button><input type="text" disabled="disabled" class="filename" /></div>'
        },
        options
      ),
      $this = $(this),
      $next;

    // prevent double wrapping
    if ($this.parent().hasClass('ui-fileupload')) {
      return false;
    }

    // init
    $this.wrap(settings.wrapContent)
      .after(settings.fakeContent)
      .on('change.file', function () {
        var val = $(this).val().split('\\');
        $(this).next().find('.filename').val(val.slice(-1)[0]);
      });

    $next = $this.next();
    $next.find('.filename').val(settings.fieldText);
    $next.find('button').text(settings.buttonText);

    return this;
  };
})(jq1111, window, document);