/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
* Last modification date: 2025-03-17
*/

#ifndef STACK_H
#define STACK_H

#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>

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
extern unsigned short stack_elements;

/* Functions prototypes */

void stack_initialize();
STACK_RES stack_push(char ch);
STACK_RES stack_pop(char *ch);
STACK_RES stack_dump(char **p_stack_clone);
STACK_RES stack_dump_free(char **p_stack_clone);
void stack_free();

#endif // STACK_H
