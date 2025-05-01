/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
* Last modification date: 2025-05-01
*/

#ifndef ARRAY_LIST_MENU_H
#define ARRAY_LIST_MENU_H

/* Constants */
enum {
  OPT_ARRAY_VIEW = 1,
  OPT_ARRAY_FIND,
  OPT_ARRAY_GET,
  OPT_ARRAY_PUSH,
  OPT_ARRAY_POP,
  OPT_ARRAY_REMOVE,
  OPT_ARRAY_SET,
  OPT_ARRAY_SORT_ASC,
  OPT_ARRAY_SORT_DESC,
  OPT_ARRAY_RETURN_MAIN_MENU
};

/* Functions prototypes */

/**
 * @brief Handle array list menu flow
*/
void handle_array_menu();

#endif // ARRAY_LIST_MENU_H