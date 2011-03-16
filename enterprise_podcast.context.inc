<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function enterprise_podcast_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'podcast';
  $context->description = 'Podcast Blocks';
  $context->tag = 'Podcast';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'podcast' => 'podcast',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'views' => array(
      'values' => array(
        'podcast' => 'podcast',
        'podcast:page_1' => 'podcast:page_1',
        'podcast:page_2' => 'podcast:page_2',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-podcast-block_2' => array(
          'module' => 'views',
          'delta' => 'podcast-block_2',
          'region' => 'right',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Podcast');
  t('Podcast Blocks');

  $export['podcast'] = $context;
  return $export;
}
