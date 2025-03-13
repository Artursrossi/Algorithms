/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
* Date: 2025-03-13
*/

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

// Variables
static unsigned short queue_start = 0;
static unsigned short queue_end = 0;
unsigned short queue_elements = 0;
static char queue[QUEUE_SIZE][QUEUE_STRING_LENGTH];

bool queue_full(){
  return queue_elements == QUEUE_SIZE;
}

bool queue_empty(){
  return queue_elements == 0;
}

QUEUE_RES queue_add(char *str){
  if(queue_full()) return QUEUE_RES_FULL;

  strcpy(queue[queue_end], str);
  queue_elements++;
  (queue_end == QUEUE_SIZE - 1) ? queue_end = 0 : queue_end++;
  return QUEUE_RES_OK;
}

QUEUE_RES queue_remove(char *str){
  if(queue_empty()) return QUEUE_RES_EMPTY;

  strcpy(str, queue[queue_start]);
  strcpy(queue[queue_start], ""); // Not necessary
  queue_elements--;
  (queue_start == QUEUE_SIZE - 1) ? queue_start = 0 : queue_start++;
  return QUEUE_RES_OK;
}

QUEUE_RES queue_dump(char ***p_queue_list){
  if(*p_queue_list != NULL) return QUEUE_RES_GENERIC_ERR;

  if(queue_empty()) return QUEUE_RES_EMPTY;

  *p_queue_list = (char**) malloc(queue_elements * sizeof(char*));
  if(*p_queue_list == NULL) return QUEUE_RES_MEM_ALLOC_ERR;

  unsigned short temp_start = queue_start;

  for(int i = 0; i < queue_elements; i++){
    (*p_queue_list)[i] = (char*) malloc(QUEUE_STRING_LENGTH * sizeof(char));
    if((*p_queue_list)[i] == NULL) return QUEUE_RES_MEM_ALLOC_ERR;

    strcpy((*p_queue_list)[i], queue[queue_start]);
  }

  return QUEUE_RES_OK;
}

QUEUE_RES queue_dump_free(char ***p_queue_list){
  if(*p_queue_list == NULL) return QUEUE_RES_OK;

  for(int i = 0; i < queue_elements; i++){
    free((*p_queue_list)[i]);
  }

  free(*p_queue_list);
  *p_queue_list = NULL;

  return QUEUE_RES_OK;
}