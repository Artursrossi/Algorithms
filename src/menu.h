/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
* Last modification date: 2025-03-17
*/

#ifndef MENU_H
#define MENU_H

#include <stdio.h>

/* Constants */
enum{
  OPT_RETURN_MAIN_MENU,
  OPT_STACK_MENU,
  OPT_QUEUE_MENU,
  OPT_QUIT
};
enum {
  OPT_QUEUE_VIEW = 1,
  OPT_QUEUE_ADD,
  OPT_QUEUE_REMOVE
};
enum {
  OPT_STACK_VIEW = 1,
  OPT_STACK_PUSH,
  OPT_STACK_POP
};

/* Functions prototypes */

unsigned short display_main_menu();
unsigned short display_stack_menu();
unsigned short display_queue_menu();
void handle_main_menu(unsigned short *opt);
void handle_stack_menu(unsigned short *opt);
void handle_queue_menu(unsigned short *opt);
void menu_initialize();

#endif // MENU_H