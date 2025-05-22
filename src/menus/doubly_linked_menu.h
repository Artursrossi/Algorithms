/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
*/

#ifndef DOUBLY_LINKED_MENU_H
#define DOUBLY_LINKED_MENU_H

/* Constants */
enum {
  OPT_DOUBLY_LINKED_VIEW = 1,
  OPT_DOUBLY_LINKED_GET_LENGTH,
  OPT_DOUBLY_LINKED_INSERT,
  OPT_DOUBLY_LINKED_REMOVE,
  OPT_DOUBLY_LINKED_REVERSE,
  OPT_DOUBLY_LINKED_RETURN_MAIN_MENU
};

/* Functions prototypes */

/**
 * @brief Handle doubly linked list menu flow
*/
void handle_doubly_linked_menu();

#endif // DOUBLY_LINKED_MENU_H