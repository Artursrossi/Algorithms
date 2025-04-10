/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
* Last modification date: 2025-04-06
*/

#include "menu.h"
#include "dynamic_stack/stack.h"
#include "circular_queue/queue.h"

int main(int argc, char * argv[]){
  stack_init();

  menu_initialize();

  stack_destroy(true);

  return 0;
}