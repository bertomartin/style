<?php
/**
 * @file
 * full_site.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function full_site_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass;
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|blog|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'blog';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'comments' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'post_date' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'ds_post_date_long',
    ),
  );
  $export['node|blog|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass;
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|blog|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'blog';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => 'blog-title',
      ),
    ),
    'post_date' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'ds_post_date_medium',
    ),
  );
  $export['node|blog|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass;
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|events|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'events';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h2',
        'class' => 'event-title',
      ),
    ),
  );
  $export['node|events|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass;
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|press|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'press';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h2',
        'class' => 'press-title',
      ),
    ),
  );
  $export['node|press|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass;
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|press|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'press';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h2',
        'class' => 'press-title',
      ),
    ),
  );
  $export['node|press|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass;
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|resources|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'resources';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h2',
        'class' => 'resource-name-title',
      ),
    ),
  );
  $export['node|resources|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function full_site_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass;
  $ds_field->api_version = 1;
  $ds_field->field = 'prevnextnav';
  $ds_field->label = 'prevnextnav';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php 
$nid = [node:nid];
$ntype = [node:content-type];

$prev = db_query("SELECT nid, title FROM {node} WHERE nid < :nid AND type = :ntype AND status = 1 ORDER BY nid DESC LIMIT 1", array(\':nid\' => $nid, \':ntype\' => $ntype));

$next = db_query("SELECT nid, title FROM {node} WHERE nid > :nid AND type = :ntype AND status = 1 ORDER BY nid DESC LIMIT 1", array(\':nid\' => $nid, \':ntype\' => $ntype));

 $prev_link = "";
 $next_link = "";

foreach ($prev as $prev_node) {

$prev_link = \'<a href="/\' . drupal_lookup_path(\'alias\', \'node/\' . $prev_node->nid) . \'" title="previous"><span>\' .$prev_node->title. \'</span></a>\';

}

 

foreach ($next as $next_node) {

$next_link = \'<a href="/\' . drupal_lookup_path(\'alias\', \'node/\' . $next_node->nid) . \'" title="next"><span>\' .$next_node->title. \'</span></a>\';

}

 

$output = \'

<ul id="erf_pager">

<li>\'. $prev_link .\'</li>

<li>\'. $next_link .\'</li>

</ul>

\';

 
echo $output;

 ?>',
      'format' => 'php_code',
    ),
    'use_token' => 1,
  );
  $export['prevnextnav'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function full_site_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass;
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|blog|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'blog';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'post_date',
        1 => 'field_image',
        2 => 'body',
        3 => 'comments',
      ),
    ),
    'fields' => array(
      'post_date' => 'ds_content',
      'field_image' => 'ds_content',
      'body' => 'ds_content',
      'comments' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|blog|full'] = $ds_layout;

  $ds_layout = new stdClass;
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|blog|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'blog';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'post_date',
        2 => 'field_image',
        3 => 'body',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'post_date' => 'ds_content',
      'field_image' => 'ds_content',
      'body' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|blog|teaser'] = $ds_layout;

  $ds_layout = new stdClass;
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|collection|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'collection';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'left' => array(
        0 => 'field_image',
      ),
      'right' => array(
        0 => 'field_season',
        1 => 'field_theme',
        2 => 'field_inspiration',
        3 => 'field_linesheet',
      ),
      'footer' => array(
        0 => 'collection_items_entity_view_1',
      ),
    ),
    'fields' => array(
      'field_image' => 'left',
      'field_season' => 'right',
      'field_theme' => 'right',
      'field_inspiration' => 'right',
      'field_linesheet' => 'right',
      'collection_items_entity_view_1' => 'footer',
    ),
    'classes' => array(),
  );
  $export['node|collection|default'] = $ds_layout;

  $ds_layout = new stdClass;
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|collection|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'collection';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'left' => array(
        0 => 'field_image',
      ),
      'right' => array(
        0 => 'field_season',
        1 => 'field_theme',
        2 => 'field_inspiration',
        3 => 'field_linesheet',
      ),
      'footer' => array(
        0 => 'collection_items_entity_view_1',
      ),
    ),
    'fields' => array(
      'field_image' => 'left',
      'field_season' => 'right',
      'field_theme' => 'right',
      'field_inspiration' => 'right',
      'field_linesheet' => 'right',
      'collection_items_entity_view_1' => 'footer',
    ),
    'classes' => array(),
  );
  $export['node|collection|teaser'] = $ds_layout;

  $ds_layout = new stdClass;
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|events|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'events';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_image',
        2 => 'field_date',
        3 => 'field_location',
        4 => 'body',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_image' => 'ds_content',
      'field_date' => 'ds_content',
      'field_location' => 'ds_content',
      'body' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|events|full'] = $ds_layout;

  $ds_layout = new stdClass;
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|press|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'press';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_image',
        1 => 'field_date',
        2 => 'title',
      ),
    ),
    'fields' => array(
      'field_image' => 'ds_content',
      'field_date' => 'ds_content',
      'title' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|press|default'] = $ds_layout;

  $ds_layout = new stdClass;
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|press|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'press';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_image',
        1 => 'field_date',
        2 => 'title',
      ),
    ),
    'fields' => array(
      'field_image' => 'ds_content',
      'field_date' => 'ds_content',
      'title' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|press|teaser'] = $ds_layout;

  $ds_layout = new stdClass;
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|resources|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'resources';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'header' => array(
        0 => 'title',
      ),
      'left' => array(
        0 => 'field_image',
      ),
      'right' => array(
        0 => 'field_specialty',
        1 => 'field_contactperson',
        2 => 'field_contactnumber',
        3 => 'field_location',
        4 => 'field_site',
      ),
      'footer' => array(
        0 => 'body',
      ),
    ),
    'fields' => array(
      'title' => 'header',
      'field_image' => 'left',
      'field_specialty' => 'right',
      'field_contactperson' => 'right',
      'field_contactnumber' => 'right',
      'field_location' => 'right',
      'field_site' => 'right',
      'body' => 'footer',
    ),
    'classes' => array(),
  );
  $export['node|resources|teaser'] = $ds_layout;

  $ds_layout = new stdClass;
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|webform|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'webform';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
  );
  $export['node|webform|teaser'] = $ds_layout;

  $ds_layout = new stdClass;
  $ds_layout->api_version = 1;
  $ds_layout->id = 'profile2|preneur|page';
  $ds_layout->entity_type = 'profile2';
  $ds_layout->bundle = 'preneur';
  $ds_layout->view_mode = 'page';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'header' => array(
        0 => 'field_name',
      ),
      'left' => array(
        0 => 'field_image',
      ),
      'right' => array(
        0 => 'field_school',
        1 => 'field_website',
        2 => 'field_location',
        3 => 'field_bio',
      ),
    ),
    'fields' => array(
      'field_name' => 'header',
      'field_image' => 'left',
      'field_school' => 'right',
      'field_website' => 'right',
      'field_location' => 'right',
      'field_bio' => 'right',
    ),
    'classes' => array(),
  );
  $export['profile2|preneur|page'] = $ds_layout;

  return $export;
}
