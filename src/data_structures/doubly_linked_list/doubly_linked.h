/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
*/

#ifndef DOUBLY_LINKED_h
#define DOUBLY_LINKED_h

#include <stdbool.h>
#include <stdint.h>

/* Constants */
struct Doubly_Node {
  int32_t data;
  struct Doubly_Node *next;
  struct Doubly_Node *prev;
};
typedef struct Doubly_Node doubly_node_t;

void doubly_linked_destroy();

void doubly_linked_insert(int32_t data);

bool doubly_linked_remove(int32_t data);

void doubly_linked_iteration(void (*iteration_fnc)(int32_t));

int32_t doubly_linked_length();

void doubly_linked_reverse();

#endif // DOUBLY_LINKED_H
