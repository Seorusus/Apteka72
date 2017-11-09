<?php
hide($comment_form['actions']['preview']);
$comment_form['actions']['submit']['#value'] = 'Отправить';
hide($comment_form['comment_body'][LANGUAGE_NONE][0]['format']);
$comment_form['comment_body'][LANGUAGE_NONE][0]['value']['#title_display'] = 'none';
hide($comment_form['author']);
$comment_form['comment_body'][LANGUAGE_NONE][0]['value']['#attributes']['placeholder'] = t('Текст комментария'); 
print drupal_render_children($comment_form);