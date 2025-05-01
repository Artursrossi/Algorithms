/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
* Last modification date: 2025-04-06
*/

#include <stdbool.h>
#include <stdint.h>

#include "stack.h"

/* Variables */
static void **stack = NULL;
static uint32_t stack_position = 0;
static uint32_t stack_max_size = 0;

void stack_init(){
  if(stack != NULL) return;

  /* Allocate memory space (in BYTES) for stack, using STACK_INITIAL_SIZE */
  stack = (void**) malloc(STACK_INITIAL_SIZE * sizeof(void*));
  if(stack == NULL){
    perror("A memory allocation error has occurred. (stack.c) \n");
    exit(EXIT_FAILURE);
  }

  stack_max_size = STACK_INITIAL_SIZE;
}

static void stack_grow() {
  uint32_t temp_max_size = stack_max_size + STACK_GROWTH_QNT;

  /* Increase memory space of stack, allocating more BYTES */
  stack = realloc(stack, temp_max_size * sizeof(void*));
  if(stack == NULL){
    perror("A memory allocation error has occurred. (stack.c) \n");
    exit(EXIT_FAILURE);
  }

  stack_max_size = temp_max_size;
}

uint32_t stack_size(){
  return stack_position;
}

static bool stack_full() {  
  return stack_position == stack_max_size;
}

static bool stack_empty() {  
  return stack_position == 0;
}

STACK_RES stack_push(void *obj) {
  if(stack == NULL) return STACK_NOT_INITIALIZED;

  /* If stack is full, reallocate more memory */
  if(stack_full()) stack_grow();
  
  stack[stack_position] = obj;
  stack_position++;

  return STACK_RES_OK;
}

STACK_RES stack_pop(void **obj) {
  if(stack == NULL) return STACK_NOT_INITIALIZED;

  if (stack_empty()) return STACK_RES_EMPTY;
  
  stack_position--;
  *obj = stack[stack_position];

  return STACK_RES_OK;
}

STACK_RES stack_dump(void ***p_stack_clone){
  if(stack == NULL) return STACK_NOT_INITIALIZED;
  if (stack_empty()) return STACK_RES_EMPTY;

  /* Allocate memory space (in BYTES) for external stack variable */
  *p_stack_clone = (void**) malloc(stack_position * sizeof(void*));
  if((*p_stack_clone) == NULL){
    perror("A memory allocation error has occurred. (stack.c) \n");
    exit(EXIT_FAILURE);
  }

  /* Clone stack elements to an external stack variable */
  for(uint32_t i = 0; i < stack_position; i++){
    (*p_stack_clone)[i] = stack[i];
  }

  return STACK_RES_OK;
}

void stack_destroy(bool free_objects){
  if(stack == NULL) return;

  /* Free up memory space for each stack object */
  if(free_objects){
    for(uint32_t i = 0; i < stack_position; i++){
      free(stack[i]);
      stack[i] = NULL;
    }
  }

  /* Free up memory space for stack */
  free(stack);
  stack = NULL;
}