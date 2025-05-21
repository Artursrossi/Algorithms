/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
*/

#include <stdio.h>
#include <stdint.h>

#include "menu.h"
#include "utils.h"
#include "dynamic_stack_menu.h"
#include "circular_queue_menu.h"
#include "array_list_menu.h"
#include "linked_list_menu.h"
#include "sorting/test_sorting_algorithm.h"
#include "sorting/bubble_sort.h"
#include "sorting/selection_sort.h"
#include "sorting/insertion_sort.h"

static void display_main_menu(uint16_t *opt){
  printf("\n\nChoose an algorithm \n");
  printf("%d - Dynamic Stack \n", OPT_STACK_MENU);
  printf("%d - Circular Queue \n", OPT_QUEUE_MENU);
  printf("%d - Array List \n", OPT_ARRAY_LIST);
  printf("%d - Linked List \n", OPT_LINKED_LIST);
  printf("%d - Bubble Sort \n", OPT_BUBBLE_SORT);
  printf("%d - Selection Sort \n", OPT_SELECTION_SORT);
  printf("%d - Insertion Sort \n", OPT_INSERTION_SORT);
  printf("%d - Quit \n", OPT_QUIT);

  scanf("%hu", opt);
}

static void handle_main_menu(){
  uint16_t opt = 0;

  do{
    display_main_menu(&opt);
    
    switch(opt){
      case OPT_STACK_MENU:
        handle_stack_menu();
        break;
      
      case OPT_QUEUE_MENU:
        handle_queue_menu();
        break;

      case OPT_ARRAY_LIST:
        handle_array_menu();
        break;

      case OPT_LINKED_LIST:
        handle_linked_list_menu();
        break;

      case OPT_BUBBLE_SORT:
        test_sorting_algorithm(bubble_sort);
        break;

      case OPT_SELECTION_SORT:
        test_sorting_algorithm(selection_sort);
        break;

      case OPT_INSERTION_SORT:
        test_sorting_algorithm(insertion_sort);
        break;
    }
  }while(opt != OPT_QUIT);
}

void menu_init(){
  handle_main_menu();
}