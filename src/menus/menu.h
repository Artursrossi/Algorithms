/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
*/

#ifndef MENU_H
#define MENU_H

/* Constants */
enum{
  OPT_STACK_MENU = 1,
  OPT_QUEUE_MENU,
  OPT_ARRAY_LIST,
  OPT_LINKED_LIST,
  OPT_DOUBLY_LINKED,
  OPT_BUBBLE_SORT,
  OPT_SELECTION_SORT,
  OPT_INSERTION_SORT,
  OPT_QUIT
};

/* Functions prototypes */

/**
 * @brief Initialize menus flow
*/
void menu_init();

#endif // MENU_H