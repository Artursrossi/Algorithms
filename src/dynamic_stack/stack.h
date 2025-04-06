/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
* Last modification date: 2025-04-06
*/

#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

/* Constants */
enum {
  STACK_INITIAL_SIZE = 64,
  STACK_GROWTH_QNT = 8
};
typedef enum {
  STACK_RES_OK,
  STACK_RES_EMPTY,
  STACK_RES_MEM_ALLOC_ERR,
  STACK_RES_GENERIC_ERR,
  STACK_NOT_INITIALIZED
} STACK_RES;

/* Functions prototypes */

/**
 * @brief Initialize dynamic variables, allocating an initial size for stack
*/
void stack_initialize();

/**
 * @brief Returns the number of elements in stack, avoiding overlapping the value of stack_position
 * 
 * @return Number of elements in stack
*/
uint32_t stack_size();

/**
 * @brief Push an object to the top of Stack
 * 
 * @param obj Pointer of the object to be pushed
*/
STACK_RES stack_push(void *obj);

/**
 * @brief Remove last entered object from stack (LIFO)
 * 
 * @param obj Pointer of variable that will receive popped object pointer
*/
STACK_RES stack_pop(void **obj);

/**
 * @brief Clone stack objects to an external variable
 * 
 * @param p_stack_clone Pointer of variable that will receive object pointers
*/
STACK_RES stack_dump(void ***p_stack_clone);

/**
 * @brief Free up the space allocated by the function stack_initialize
 * 
 * @param free_objects If true, free up each object of stack, otherwise, free up only the stack (In second case, you're responsible for free up each object)
*/
void stack_free(bool free_objects);

#endif // STACK_H
