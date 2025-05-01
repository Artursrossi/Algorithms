/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
* Last modification date: 2025-05-01
*/

#include "menus/menu.h"
#include "data_structures/dynamic_stack/stack.h"
#include "data_structures/circular_queue/queue.h"
#include "data_structures/array_list/array_list.h"

int main(){
  stack_init();
  array_init();
  
  menu_init();
  
  stack_destroy(true);
  array_destroy();

  return 0;
}