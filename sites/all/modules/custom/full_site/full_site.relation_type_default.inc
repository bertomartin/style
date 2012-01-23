<?php
/**
 * @file
 * full_site.relation_type_default.inc
 */

/**
 * Implements hook_relation_default_relation_types().
 */
function full_site_relation_default_relation_types() {
  $export = array();

  $relation_type = new stdClass;
  $relation_type->disabled = FALSE; /* Edit this to true to make a default relation_type disabled initially */
  $relation_type->api_version = 1;
  $relation_type->relation_type = 'membership';
  $relation_type->label = 'Membership';
  $relation_type->reverse_label = 'Membership';
  $relation_type->directional = 0;
  $relation_type->transitive = 0;
  $relation_type->r_unique = 0;
  $relation_type->min_arity = 2;
  $relation_type->max_arity = 2;
  $relation_type->source_bundles = array(
    0 => 'node:collection',
    1 => 'user:user',
  );
  $relation_type->target_bundles = array();
  $export['membership'] = $relation_type;

  return $export;
}
