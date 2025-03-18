/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
* Last modification date: 2025-03-17
*/

#include "stack.h"

/* Variables */
static char *stack = NULL;
static unsigned short stack_position = 0;
static unsigned short stack_max_size = 0;
unsigned short stack_elements = 0;

void stack_initialize(){
  /* Allocate memory space (in BYTES) for stack, using STACK_INITIAL_SIZE */
  stack = (char*) malloc(STACK_INITIAL_SIZE * sizeof(char));
  stack_max_size = STACK_INITIAL_SIZE;
}

static bool stack_grow() {
  if(stack == NULL) return false;

  unsigned short temp_max_size = stack_max_size + STACK_GROWTH_QNT;

  /* Increase memory space of stack, allocating more BYTES */
  stack = realloc(stack, temp_max_size * sizeof(char));
  if(stack == NULL) return false;

  stack_max_size = temp_max_size;

  return true;
}

static bool stack_full() {  
  return stack_position == stack_max_size;
}

static bool stack_empty() {  
  return stack_position == 0;
}

STACK_RES stack_push(char ch) {
  if(stack == NULL) return STACK_NOT_INITIALIZED;

  /* If stack is full, reallocate more memory */
  if(stack_full()){
    bool stack_grow_res = stack_grow();
    if(!stack_grow_res) return STACK_RES_MEM_ALLOC_ERR;
  }
  
  stack[stack_position] = ch;
  stack_position++;
  stack_elements++;

  return STACK_RES_OK;
}

STACK_RES stack_pop(char *ch) {
  if(stack == NULL) return STACK_NOT_INITIALIZED;

  if (stack_empty()) return STACK_RES_EMPTY;
  
  stack_position--;
  *ch = stack[stack_position];
  stack_elements--;

  return STACK_RES_OK;
}

STACK_RES stack_dump(char **p_stack_clone){
  if(stack == NULL) return STACK_NOT_INITIALIZED;
  if (stack_empty()) return STACK_RES_EMPTY;

  /* Allocate memory space (in BYTES) for external stack variable (char vector) */
  *p_stack_clone = (char*) malloc(stack_elements * sizeof(char));
  if(*p_stack_clone == NULL) return STACK_RES_MEM_ALLOC_ERR;

  /* Clone stack elements to an external stack variable (char vector) */
  for(int i = 0; i < stack_elements; i++){
    (*p_stack_clone)[i] = stack[i];
  }

  return STACK_RES_OK;
}

STACK_RES stack_dump_free(char **p_stack_clone){
  if(*p_stack_clone == NULL) return STACK_RES_OK;

  /* Free up memory space for external stack variable (char vector) */
  free(*p_stack_clone);
  *p_stack_clone = NULL;

  return STACK_RES_OK;
}

void stack_free(){
  /* Free up memory space for stack */
  free(stack);
  stack = NULL;
}