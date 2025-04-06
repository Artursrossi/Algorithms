/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
* Last modification date: 2025-04-06
*/

#include "menu.h"
#include "dynamic_stack/stack.h"
#include "circular_queue/queue.h"

int main(int argc, char * argv[]){
  stack_initialize();

  menu_initialize();

  stack_free(true);

  return 0;
}