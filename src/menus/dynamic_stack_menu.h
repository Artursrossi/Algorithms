/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
* Last modification date: 2025-05-01
*/

#ifndef DYNAMIC_STACK_MENU_H
#define DYNAMIC_STACK_MENU_H

/* Constants */
enum {
  OPT_STACK_VIEW = 1,
  OPT_STACK_PUSH,
  OPT_STACK_POP,
  OPT_STACK_RETURN_MAIN_MENU
};

/* Functions prototypes */

/**
 * @brief Handle stack menu flow
*/
void handle_stack_menu();

#endif // DYNAMIC_STACK_MENU_H