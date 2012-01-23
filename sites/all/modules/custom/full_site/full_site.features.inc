<?php
/**
 * @file
 * full_site.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function full_site_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "relation" && $api == "relation_type_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function full_site_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function full_site_image_default_styles() {
  $styles = array();

  // Exported image style: collection_thumb
  $styles['collection_thumb'] = array(
    'name' => 'collection_thumb',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '100',
          'height' => '100',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function full_site_node_info() {
  $items = array(
    'blog' => array(
      'name' => t('Blog'),
      'base' => 'node_content',
      'description' => t('Create a blog post here'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'collection' => array(
      'name' => t('Collection'),
      'base' => 'node_content',
      'description' => t('A collection is a list of images of designs. Any preneur can have multiple collections, e.g summer, winter, spring, etc...'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'events' => array(
      'name' => t('Events'),
      'base' => 'node_content',
      'description' => t('Add an event'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'item' => array(
      'name' => t('Item'),
      'base' => 'node_content',
      'description' => t('Upload an image of the item. Each item is part of a collection'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'press' => array(
      'name' => t('Press'),
      'base' => 'node_content',
      'description' => t('Add press items'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'resources' => array(
      'name' => t('Resources'),
      'base' => 'node_content',
      'description' => t('Resources'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'simplenews' => array(
      'name' => t('Simplenews newsletter'),
      'base' => 'node_content',
      'description' => t('A newsletter issue to be sent to subscribed email addresses.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'webform' => array(
      'name' => t('Webform'),
      'base' => 'node_content',
      'description' => t('Create a new form or questionnaire accessible to users. Submission results and statistics are recorded and accessible to privileged users.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implements hook_default_profile2_type().
 */
function full_site_default_profile2_type() {
  $items = array();
  $items['main'] = entity_import('profile2_type', '{
    "userCategory" : false,
    "userView" : false,
    "type" : "main",
    "label" : "Main profile",
    "weight" : "0",
    "data" : { "registration" : 0, "use_page" : 1 },
    "rdf_mapping" : []
  }');
  $items['opportunity'] = entity_import('profile2_type', '{
    "userCategory" : false,
    "userView" : false,
    "type" : "opportunity",
    "label" : "Opportunity",
    "weight" : "0",
    "data" : { "registration" : 0, "use_page" : 1 },
    "rdf_mapping" : []
  }');
  $items['preneur'] = entity_import('profile2_type', '{
    "userCategory" : false,
    "userView" : false,
    "type" : "preneur",
    "label" : "Preneur",
    "weight" : "0",
    "data" : { "registration" : 0, "use_page" : 1 },
    "rdf_mapping" : []
  }');
  return $items;
}
