/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
* Last modification date: 2025-05-01
*/

#ifndef CIRCULAR_QUEUE_MENU_H
#define CIRCULAR_QUEUE_MENU_H

/* Constants */
enum {
  OPT_QUEUE_VIEW = 1,
  OPT_QUEUE_ADD,
  OPT_QUEUE_REMOVE,
  OPT_QUEUE_RETURN_MAIN_MENU
};

/* Functions prototypes */

/**
 * @brief Handle queue menu flow
*/
void handle_queue_menu();

#endif // CIRCULAR_QUEUE_MENU_H