/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
*/

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

/* Variables */
static void  **queue = NULL;
static uint32_t queue_start = 0; // Always pointing to first valid element [0 <= queue_start < QUEUE_SIZE]
static uint32_t queue_end = 0; // Always pointing to next element position [0 <= queue_end < QUEUE_SIZE]
static uint32_t length = 0;

void queue_init(){
  if(queue != NULL) return;

  /* Allocate memory space (in BYTES) for queue, using QUEUE_SIZE */
  queue = (void**) malloc(QUEUE_SIZE * sizeof(void*));
  if(queue == NULL){
    perror("A memory allocation error has occurred. (queue.c) \n");
    exit(EXIT_FAILURE);
  }
}

void queue_destroy(bool free_objects){
  if(queue == NULL) return;

  /* Free up memory space for each queue object */
  if(free_objects){
    uint32_t temp_start = queue_start;

    /* Free up memory space for each queue object */
    for(uint32_t i = 0; i < length; i++){
      free(queue[temp_start]);
      queue[temp_start] = NULL;
  
      /* Prevent temp_start variable to be non valid queue index, and doing queue cycling */
      (temp_start == QUEUE_SIZE - 1) ? temp_start = 0 : temp_start++;
    }
  }

  /* Free up memory space for queue */
  free(queue);
  queue = NULL;
}

bool queue_full(){
  return length == QUEUE_SIZE;
}

uint32_t queue_length(){
  return length;
}

bool queue_empty(){
  return length == 0;
}

QUEUE_RES queue_add(void *obj){
  if(queue == NULL) return QUEUE_NOT_INITIALIZED;
  if(queue_full()) return QUEUE_RES_FULL;

  queue[queue_end] = obj;
  length++;

  /* Prevent queue_end variable to be non valid queue index, and doing queue cycling */
  (queue_end == QUEUE_SIZE - 1) ? queue_end = 0 : queue_end++;

  return QUEUE_RES_OK;
}

QUEUE_RES queue_remove(void **obj){
  if(queue == NULL) return QUEUE_NOT_INITIALIZED;
  if(queue_empty()) return QUEUE_RES_EMPTY;

  length--;
  *obj = queue[queue_start];

  /* Prevent queue_start variable to be non valid queue index, and doing queue cycling */
  (queue_start == QUEUE_SIZE - 1) ? queue_start = 0 : queue_start++;

  return QUEUE_RES_OK;
}

QUEUE_RES queue_dump(void ***p_queue_list){
  if(queue == NULL) return QUEUE_NOT_INITIALIZED;
  if(queue_empty()) return QUEUE_RES_EMPTY;

  /* Allocate memory space (in BYTES) for external queue variable */
  *p_queue_list = (void**) malloc(length * sizeof(void*));
  if(*p_queue_list == NULL){
    perror("A memory allocation error has occurred. (queue.c) \n");
    exit(EXIT_FAILURE);
  }

  uint32_t temp_start = queue_start;

  for(uint32_t i = 0; i < length; i++){
    (*p_queue_list)[i] = queue[temp_start];

    /* Prevent temp_start variable to be non valid queue index, and doing queue cycling */
    (temp_start == QUEUE_SIZE - 1) ? temp_start = 0 : temp_start++;
  }

  return QUEUE_RES_OK;
}