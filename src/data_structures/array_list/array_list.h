/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
* Last modification date: 2025-05-01
*/

#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stdbool.h>
#include <stdint.h>

/* Constants */
enum {
  ARRAY_INITIAL_SIZE = 8,
  ARRAY_GROWTH_QNT = 4
};
typedef enum {
  ARRAY_RES_OK,
  ARRAY_RES_EMPTY,
  ARRAY_RES_NOT_FOUND,
  ARRAY_RES_NOT_INITIALIZED
} ARRAY_RES;

/* Functions prototypes */
void array_init();
void array_destroy();
ARRAY_RES array_dump(int32_t **p_array_dump);
int32_t array_length();

int32_t array_find(int32_t value);
ARRAY_RES array_get(int32_t index, int32_t *getted_value);

ARRAY_RES array_push(int32_t value);

ARRAY_RES array_pop(int32_t *removed_value);
ARRAY_RES array_remove(int32_t value);

ARRAY_RES array_set(int32_t index, int32_t value);

ARRAY_RES array_sort(bool is_asc);

#endif //ARRAY_LIST_H
