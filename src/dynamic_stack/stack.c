/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
* Last modification date: 2025-04-06
*/

#include "stack.h"

/* Variables */
static void **stack = NULL;
static unsigned int stack_position = 0;
static unsigned int stack_max_size = 0;

void stack_initialize(){
  if(stack != NULL) return;

  /* Allocate memory space (in BYTES) for stack, using STACK_INITIAL_SIZE */
  stack = (void**) malloc(STACK_INITIAL_SIZE * sizeof(void*));
  stack_max_size = STACK_INITIAL_SIZE;
}

static bool stack_grow() {
  if(stack == NULL) return false;

  unsigned int temp_max_size = stack_max_size + STACK_GROWTH_QNT;

  /* Increase memory space of stack, allocating more BYTES */
  stack = realloc(stack, temp_max_size * sizeof(void*));
  if(stack == NULL) return false;

  stack_max_size = temp_max_size;

  return true;
}

unsigned int stack_size(){
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
  if(stack_full()){
    bool stack_grow_res = stack_grow();
    if(!stack_grow_res) return STACK_RES_MEM_ALLOC_ERR;
  }
  
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
  if((*p_stack_clone) == NULL) return STACK_RES_MEM_ALLOC_ERR;

  /* Clone stack elements to an external stack variable */
  for(int i = 0; i < stack_position; i++){
    (*p_stack_clone)[i] = stack[i];
  }

  return STACK_RES_OK;
}

void stack_free(bool free_objects){
  if(stack == NULL) return;

  /* Free up memory space for each stack object */
  if(free_objects){
    for(int i = 0; i < stack_position; i++){
      free(stack[i]);
      stack[i] = NULL;
    }
  }

  /* Free up memory space for stack */
  free(stack);
  stack = NULL;
}