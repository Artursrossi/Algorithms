/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
* Last modification date: 2025-03-15
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

/* Variables */
static uint16_t queue_start = 0; // Always pointing to first valid element [0 <= queue_start < QUEUE_SIZE]
static uint16_t queue_end = 0; // Always pointing to next element position [0 <= queue_end < QUEUE_SIZE]
uint16_t queue_elements = 0;
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

  /* Prevent queue_end variable to be non valid queue index, and doing queue cycling */
  (queue_end == QUEUE_SIZE - 1) ? queue_end = 0 : queue_end++;

  return QUEUE_RES_OK;
}

QUEUE_RES queue_remove(char *str){
  if(queue_empty()) return QUEUE_RES_EMPTY;

  strcpy(str, queue[queue_start]);
  queue_elements--;

  /* Prevent queue_start variable to be non valid queue index, and doing queue cycling */
  (queue_start == QUEUE_SIZE - 1) ? queue_start = 0 : queue_start++;

  return QUEUE_RES_OK;
}

QUEUE_RES queue_dump(char ***p_queue_list){
  if(*p_queue_list != NULL) return QUEUE_RES_GENERIC_ERR;

  if(queue_empty()) return QUEUE_RES_EMPTY;

  /* Allocate memory space (in BYTES) for matrix row */
  *p_queue_list = (char**) malloc(queue_elements * sizeof(char*));
  if(*p_queue_list == NULL) return QUEUE_RES_MEM_ALLOC_ERR;

  uint16_t temp_start = queue_start;

  for(uint16_t i = 0; i < queue_elements; i++){
    /* Allocate memory space (in BYTES) for each matrix column */
    (*p_queue_list)[i] = (char*) malloc(QUEUE_STRING_LENGTH * sizeof(char));
    if((*p_queue_list)[i] == NULL) return QUEUE_RES_MEM_ALLOC_ERR;

    strcpy((*p_queue_list)[i], queue[temp_start]);

    /* Prevent temp_start variable to be non valid queue index, and doing queue cycling */
    (temp_start == QUEUE_SIZE - 1) ? temp_start = 0 : temp_start++;
  }

  return QUEUE_RES_OK;
}

QUEUE_RES queue_dump_free(char ***p_queue_list){
  if(*p_queue_list == NULL) return QUEUE_RES_OK;

  /* Free up memory space for each matrix column */
  for(uint16_t i = 0; i < queue_elements; i++){
    free((*p_queue_list)[i]);
  }

  /* Free up memory space for matrix row */
  free(*p_queue_list);
  *p_queue_list = NULL;

  return QUEUE_RES_OK;
}