/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
* Date: 2025-03-13
*/

#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdbool.h>
#include <string.h>

// Constants
enum {
  QUEUE_SIZE = 5,
  QUEUE_STRING_LENGTH = 31
};
typedef enum {
  QUEUE_RES_OK,
  QUEUE_RES_FULL,
  QUEUE_RES_EMPTY,
  QUEUE_RES_MEM_ALLOC_ERR,
  QUEUE_RES_GENERIC_ERR
} QUEUE_RES;

// Variables
extern unsigned short queue_elements;

// Functions
bool queue_full();
bool queue_empty();
QUEUE_RES queue_add(char *str);
QUEUE_RES queue_remove(char *str);
QUEUE_RES queue_dump(char ***p_queue_list);
QUEUE_RES queue_dump_free(char ***p_queue_list);

#endif // CIRCULAR_QUEUE_H