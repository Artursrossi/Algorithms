/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
*/

#ifndef BINARY_TREE_MENU_H
#define BINARY_TREE_MENU_H

/* Constants */
enum {
  OPT_BINARY_TREE_VIEW = 1,
  OPT_BINARY_TREE_GET_LENGTH,
  OPT_BINARY_TREE_GET_HEIGHT,
  OPT_BINARY_TREE_INSERT,
  OPT_BINARY_TREE_SEARCH,
  OPT_BINARY_TREE_REMOVE,
  OPT_BINARY_TREE_RETURN_MAIN_MENU
};

/* Functions prototypes */

/**
 * @brief Handle binary tree menu flow
*/
void handle_binary_tree_menu();

#endif // BINARY_TREE_MENU_H