/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
#include <stdint.h>

/* Constants */
struct LL_Node {
  int32_t data;
  struct LL_Node *next;
};
typedef struct LL_Node ll_node_t;

/* Functions prototypes */

/**
 * @brief Free up the space allocated by the Nodes
*/
void linked_list_destroy();

/**
 * @brief Insert value to the linked list (ordering by ascending)
 * 
 * @param data Value to be added
*/
void linked_list_insert(int32_t data);

/**
 * @brief Remove element by value
 * 
 * @param data Value to be removed
 * 
 * @return True for removed, False for not found
*/
bool linked_list_remove(int32_t data);

/**
 * @brief Execute a function for each data of linked list (for generic iteration)
 * 
 * @param iteration_fnc Pointer to a generic function that will receive each data of array list
*/
void linked_list_iteration(void (*iteration_fnc)(int32_t));

/**
 * @brief Returns the number of elements in linked list
 * 
 * @return Number of elements in linked list
*/
int32_t linked_list_length();

/**
 * @brief Reverse linked list
 * 
 * @example
 *  HEAD -> 1 -> 2 -> 3 -> 4 -> 5 -> NULL
 *  NULL <- 1 <- 2 <- 3 <- 4 <- 5 <- HEAD
 * 
*/
void linked_list_reverse();

#endif // LINKED_LIST_H
