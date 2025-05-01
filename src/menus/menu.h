/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
* Last modification date: 2025-03-17
*/

#ifndef MENU_H
#define MENU_H

/* Constants */
enum{
  OPT_STACK_MENU = 1,
  OPT_QUEUE_MENU,
  OPT_ARRAY_LIST,
  OPT_BUBBLE_SORT,
  OPT_QUIT
};

/* Functions prototypes */

/**
 * @brief Initialize menus flow
*/
void menu_init();

#endif // MENU_H