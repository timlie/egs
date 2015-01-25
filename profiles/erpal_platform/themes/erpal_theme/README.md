== ERPAL theme ==
This is the theme for ERPAL.
Find more information at http://dgo.to/erpal_theme

== Compiling Sass ==
needs Grunt, Guard & Bundler

1.A) Sass/Compass with Bundler & Guard
  1. $ bundle install
  2. $ bundle exec guard

1.B) Sass/Compass with Grunt
  1. $ npm install
  2.
     a) compiling once (using bundler & guard)
        $ grunt shell:compass
     b) compiling once with sass-linting and generating sass-doc
        $ grunt compile
     c) watching (using guard) - maybe useless option
        $ grunt guard
     d) watch
        $ grunt dev


== Using Grunt ==
scsslint, jshint and casper will be run - make sure all packages are installed (1.B.1)

2.A) run the general lint & test
  1. $ grunt test

2.B) run dedicated tests (eg. login)
  1. $ grunt casper:login