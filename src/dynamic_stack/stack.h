/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
* Last modification date: 2025-03-17
*/

#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

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

/* Variables */
extern unsigned short stack_elements; // Number of elements in stack

/* Functions prototypes */

/**
 * @brief Initialize dynamic variables, allocating an initial size for stack
*/
void stack_initialize();

/**
 * @brief Push element to the top of Stack
 * 
 * @param ch Character to be added
*/
STACK_RES stack_push(char ch);

/**
 * @brief Remove last entered element from stack (LIFO)
 * 
 * @param ch Character that will receive removed item value
*/
STACK_RES stack_pop(char *ch);

/**
 * @brief Clone stack elements to external variable
 * 
 * @param p_stack_clone Pointer of char vector that will receive stack elements
*/
STACK_RES stack_dump(char **p_stack_clone);

/**
 * @brief Free up the space allocated by the function stack_dump
 * 
 * @param p_stack_clone Pointer of char vector to be de-allocated
*/
STACK_RES stack_dump_free(char **p_stack_clone);

/**
 * @brief Free up the space allocated by the function stack_initialize
*/
void stack_free();

#endif // STACK_H
