/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
* Date: 2025-03-17
*/

#include "menu.h"
#include "dynamic_stack/stack.h"
#include "circular_queue/queue.h"

int main(int argc, char * argv[]){
  stack_initialize();

  menu_initialize();

  stack_free();

  return 0;
}