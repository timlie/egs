<?php

/**
 * @file
 * Documentation for Units module.
 */

/**
 * Deprecated! A hook to introduce units defined in your module.
 *
 * This hook is *deprecated* in favor of exporting/importing units and measures
 * using Features module. See https://drupal.org/node/2027185 for more details.
 * This hook is designed to introduce to Units module various units and measures
 * defined in other modules.
 *
 * @return array
 *   Array of units and measures. Each key of array represents machine-readable
 *   name of measure, while keys of the sub array are the following:
 *     label - human readable name of measure
 *     description - (defaults to '') human readable description of measure
 *     units - array of units in which this measure can be measured (see below)
 *     convert_callback - (defaults to UNITS_DEFAULT_CONVERT_CALLBACK) a PHP
 *       function that handles conversion of value measured in one unit into
 *       value measured in another unit of this measure
 *   Each key of array of 'units' should represent machine-readable name of
 *   unit, while keys of the sub array are the following:
 *     label - human readable name of unit
 *     symbol - (defaults to '') human readable short name of unit (its symbol)
 *     description - (defaults to '') human readable description of unit
 *     factor - (defaults to 1) a constant factor multiplying by which value
 *       from this unit will be converted to the SI unit of this measure or any
 *       other standard unit for this measure. Note: based on this parameter the
 *       default convert callback function does its conversions.
 *
 */
function hook_units_info() {
  return array(
    'length' => array(
      'label' => 'Length',
      'description' => 'bla bla bla',
      'units' => array(
        'meter' => array(
          'label' => 'Meter',
          'symbol' => 'm',
          'factor' => 1,
          'description' => 'Meter',
        ),
        'centimeter' => array(
          'label' => 'Centimeter',
          'symbol' => 'cm',
          'factor' => 0.01,
          'description' => 'Centimeter',
        ),
      ),
    ),
    'dummy' => array(
      'label' => 'Dummy Length',
      'description' => 'There is a russian cartoon where a curious parrot asks himself how long is boa, measuring in parrots. According to him, one boa is 38 parrots long.',
      'units' => array(
        'parrot' => array(
          'label' => 'Parrot',
          'factor' => 1,
          'description' => 'A parrot unit',
        ),
        'boa' => array(
          'label' => 'boa',
          'factor' => 38,
          'description' => 'A boa unit',
        ),
      ),
    ),
    'random' => array(
      'label' => 'Random Converter',
      'description' => 'A test group of units. Do not try to find out dependency in factors between units of this group. The result of a conversion in this group is always a random number.',
      'units' => array(
        'a' => array(
          'label' => 'Unit Measure 1',
          'description' => 'Unit #1',
        ),
        'b' => array(
          'label' => 'Unit Measure 2',
          'description' => 'Unit #2',
        ),
      ),
      'convert_callback' => 'units_convert_random',
    ),
  );
}

/**
 * Convert value measured in one unit into value measured in another unit.
 *
 * @param float $value
 *   Value to be converted
 * @param string $from
 *   Units in which $value is measured. Supply machine-readable name of the unit
 * @param string $to
 *   Units in which $value needs to be converted. Supply machine-readable name
 *   of the unit
 * @param string $measure
 *   Optional. Measure of value to be converted, normally the measure is looked
 *   up using the provided $form and $to, but in case the same unit measure is
 *   used in different measures, this parameter may narrow down unit measures
 *   to necessary scope of the supplied measure.
 *
 * @return float
 *   Value $value, converted from $from units into $to units
 */
function units_convert_random($value, $from, $to, $measure = NULL) {
  // Normally we would load $from and $to and do some manipulations with it.
  // But in our case the result is just a random number.

  return rand();
}
