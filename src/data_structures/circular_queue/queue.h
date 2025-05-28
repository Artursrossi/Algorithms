/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
*/

#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdbool.h>
#include <stdint.h>

/* Constants */
enum {
  QUEUE_SIZE = 5
};
typedef enum {
  QUEUE_RES_OK,
  QUEUE_RES_FULL,
  QUEUE_RES_EMPTY,
  QUEUE_NOT_INITIALIZED
} QUEUE_RES;

/* Functions prototypes */

/**
 * @brief Initialize dynamic variables, allocating an initial size for queue
*/
void queue_init();

/**
 * @brief Free up the space allocated by the function queue_init
 * 
 * @param free_objects If true, free up each object of queue, otherwise, free up only the queue (In second case, you're responsible for free up each object)
*/
void queue_destroy(bool free_objects);

/**
 * @brief Returns the number of elements in queue, avoiding overlapping the internal value
 * 
 * @return Number of objects in queue
*/
uint32_t queue_length();

/**
 * @return Boolean indicating if queue is full
*/
bool queue_full();

/**
 * @return Boolean indicating if queue is empty
*/
bool queue_empty();

/**
 * @brief Add an object to the end of queue (FIFO)
 * 
 * @param obj Object to be added
*/
QUEUE_RES queue_add(void *obj);

/**
 * @brief Remove first entered element from queue (FIFO)
 * 
 * @param obj Pointer of a variable that will receive removed object
*/
QUEUE_RES queue_remove(void **obj);

/**
 * @brief Clone queue valid items to an external variable
 * 
 * @param p_queue_list Pointer of variable that will receive queue objects
*/
QUEUE_RES queue_dump(void ***p_queue_list);

#endif // CIRCULAR_QUEUE_H