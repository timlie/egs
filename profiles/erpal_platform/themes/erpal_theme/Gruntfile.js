'use strict';

module.exports = function (grunt) {
  // show elapsed time at the end
  require('time-grunt')(grunt);

  // Load all grunt tasks matching the `grunt-*` pattern.
  require('load-grunt-tasks')(grunt);

  var config = {
    base:       './',
    livereload: 35729,
    scss:       'sass',
    css:        'css',
    img:        'images',
    tests:      'test',
    sassdoc:    'sass-doc'
  };

  var lrSnippet = require('connect-livereload')({
    port: config.livereload
  });

  var mountFolder = function (connect, dir) {
    return connect.static(require('path').resolve(dir));
  };

  var pkg = grunt.file.readJSON('package.json');

  grunt.initConfig({
    pkg: pkg,

    conf: config,

    watch: {
      compass: {
        files: ['<%= conf.scss %>/**/*.scss'],
        tasks: ['compass:dev']
      },
      livereload: {
        options: {
          livereload: config.livereload
        },
        files: [
          '<%= conf.css %>/{,*/}*.css',
          '<%= conf.js %>/{,*/}*.js'
        ]
      }
    },

    shell: {
      theme:   {
        command: 'drush cache-clear theme-registry'
      }
    },

    connect: {
      options: {
        port: 9000,
        // change this to '0.0.0.0' to access the server from outside
        hostname: 'localhost'
      },
      livereload: {
        options: {
          middleware: function (connect) {
            return [
              lrSnippet,
              mountFolder(connect, config.base)
            ];
          }
        }
      },
      dist: {
        options: {
          middleware: function (connect) {
            return [
              mountFolder(connect, yeomanConfig.dist)
            ];
          }
        }
      }
    },

    compass: {
      options: {
        config:     'config.rb',
        bundleExec: true
      },
      dist: {
        options: {
          environment: 'production'
        }
      },
      dev: {
        options: {
          debugInfo: true,
          environment: 'development'
        }
      }
    },

    scsslint: {
      allFiles: [
        '<%= conf.scss %>/**/*.scss'
      ],
      options:  {
        bundleExec:     true,
        config:         '.scss-lint.yml',
        reporterOutput: 'scss-lint-report.xml',
        colorizeOutput: true
      }
    },

    jshint: {
      all: ['js/*.js', 'js/custom/*.js']
    },

    sassdoc: {
      default: {
        src:     '<%= conf.scss %>',
        dest:    '<%= conf.sassdoc %>',
        options: {
          verbose:  true,
          display:  {
            access:    ['public', 'private'],
            alias:     true,
            watermark: true
          },
          groups:   {
            'undefined': 'General',
            'button':    'Buttons',
            'color':     'Colors',
            'typo':      'Typographie'
          },
          package:  pkg,
          theme:    'default',
          basePath: '../<%= conf.scss %>'
        }
      }
    },

    concurrent: {
      dev: [
        'devtools',
        'watch'
      ],
      dist: [
        'compass:dist'
      ],
      options: {
        limit: 5,
        logConcurrentOutput: true
      }
    },

    casper: {
      options: {
        test: true
      },
      login:   {
        src: ['<%= conf.tests %>/login.js']
      }
    }
  });


  // linting
  grunt.registerTask('lint', [
    'scsslint',
    'jshint'
  ]);

  // default task - $ grunt
  grunt.registerTask('default', [
    'concurrent:dev'
  ]);

  // build distribution
  grunt.registerTask('build', [
    'compass:dist'
  ]);
};
