<?php
/**
 * @file
 * full_site.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function full_site_user_default_roles() {
  $roles = array();

  // Exported role: admin
  $roles['admin'] = array(
    'name' => 'admin',
    'weight' => '5',
  );

  // Exported role: administrator
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => '2',
  );

  // Exported role: opportunity
  $roles['opportunity'] = array(
    'name' => 'opportunity',
    'weight' => '4',
  );

  // Exported role: preneur
  $roles['preneur'] = array(
    'name' => 'preneur',
    'weight' => '3',
  );

  return $roles;
}
