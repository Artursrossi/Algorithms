/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
*/

#include <stdlib.h>
#include <time.h>

#include "menus/menu.h"
#include "data_structures/dynamic_stack/stack.h"
#include "data_structures/circular_queue/queue.h"
#include "data_structures/array_list/array_list.h"
#include "data_structures/linked_list/linked_list.h"
#include "data_structures/doubly_linked_list/doubly_linked.h"

int main(){
  srand(time(NULL));

  stack_init();
  array_init();
  
  menu_init();
  
  stack_destroy(true);
  array_destroy();
  linked_list_destroy();
  doubly_linked_destroy();

  return 0;
}