/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
*/

#ifndef LINKED_LIST_MENU_H
#define LINKED_LIST_MENU_H

/* Constants */
enum {
  OPT_LINKED_LIST_VIEW = 1,
  OPT_LINKED_LIST_GET_LENGTH,
  OPT_LINKED_LIST_INSERT,
  OPT_LINKED_LIST_REMOVE,
  OPT_LINKED_LIST_REVERSE,
  OPT_LINKED_LIST_RETURN_MAIN_MENU
};

/* Functions prototypes */

/**
 * @brief Handle linked list menu flow
*/
void handle_linked_list_menu();

#endif // LINKED_LIST_MENU_H