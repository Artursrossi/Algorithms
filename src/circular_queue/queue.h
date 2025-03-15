/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
* Last modification date: 2025-03-15
*/

#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdbool.h>
#include <string.h>

/* Constants */
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

/* Variables */
extern unsigned short queue_elements; // Number of valid element in queue

/* Functions prototypes */

/**
 * @return Boolean indicating if queue is full
*/
bool queue_full();

/**
 * @return Boolean indicating if queue is empty
*/
bool queue_empty();

/**
 * @brief Add element to queue
 * 
 * @param str String to be added
*/
QUEUE_RES queue_add(char *str);

/**
 * @brief Remove first entered element from queue (FIFO)
 * 
 * @param str String that will receive removed item value
*/
QUEUE_RES queue_remove(char *str);

/**
 * @brief Clone queue valid items to external matrix
 * 
 * @param p_queue_list Pointer of matrix that will receive queue items
*/
QUEUE_RES queue_dump(char ***p_queue_list);

/**
 * @brief Free up the space allocated by the function queue_dump
 * 
 * @param p_queue_list Pointer of matrix to be de-allocated
*/
QUEUE_RES queue_dump_free(char ***p_queue_list);

#endif // CIRCULAR_QUEUE_H