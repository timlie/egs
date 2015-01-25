
-- SUMMARY --

Units module provides very simple API for working with unit types collections,
that makes units pluggable via hooks. Units module introduces ability to create
units and make conversions between them. This module does not provide any
external impact but defining 2 new entity types and a callback function for
converting values from one unit into another. Probably you will install this
module only if another one depends on it.

-- REQUIREMENTS --

The Units module requires the following modules:
* Entity API

-- INSTALLATION --

Install as usual, units.module brings in ability to import Unit and Measure
entities from code. If you want to have user interface on top of it, where you
will be able to manually alter/edit/create/delete entities, please, additionally
intall units_ui.module

-- CONFIGURATION --

* The module itself does not provide any configuration as of the moment, as it
imports all data from other modules. However, units_ui.module does provide
configuration pages. Having installed units_ui.module go to
Structure -> Measures, and there you will be able to manage available units and
measures.
