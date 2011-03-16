<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function enterprise_podcast_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function enterprise_podcast_imagecache_default_presets() {
  $items = array(
    'podcast_normal' => array(
      'presetname' => 'podcast_normal',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '300',
            'height' => '200',
          ),
        ),
      ),
    ),
    'podcast_thumbnail' => array(
      'presetname' => 'podcast_thumbnail',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '100',
            'height' => '66',
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function enterprise_podcast_node_info() {
  $items = array(
    'podcast' => array(
      'name' => t('Podcast Episode'),
      'module' => 'features',
      'description' => t('Creates an audio episode of a podcast.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function enterprise_podcast_views_api() {
  return array(
    'api' => '2',
  );
}
