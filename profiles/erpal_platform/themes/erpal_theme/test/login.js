/*
  login test
 */

var config = {
  url:  'http://local.erpal-3.de/',
  login : {
    user: 'admin',
    pass: 'admin'
  }
};

casper.test.begin('login', 3, function suite (test) {
  casper.start(config.url + 'user', function () {
    var loginFormID = 'user-login',
      submitButton = '#edit-submit';

    // check for elements
    this.echo('‣ checking for elements');
    this.test.assertExists('form[id="' + loginFormID + '"]', 'login-form is present');
    this.test.assertVisible(submitButton, 'submit-button is visible');

    // loggin in
    this.echo('‣ logging in');
    casper.waitForSelector('form[id="' + loginFormID + '"]', function () {
      this.fillSelectors('form#' + loginFormID, {
        '[name="name"]': config.login.user,
        '[name="pass"]': config.login.pass
      });
    }, false); // login but don't submit

    // submit via button
    casper.then(function(){
      this.click(submitButton);
    });

    // check if user is logged in
    this.echo('‣ waiting for page');
    casper.wait(500, function(){
      test.assertUrlMatch(config.url + 'users/admin', 'user is logged in and url is correct');
    });
  });

  casper.run(function () {
    test.done();
  });
});