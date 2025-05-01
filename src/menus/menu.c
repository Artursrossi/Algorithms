/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
* Last modification date: 2025-04-06
*/

#include <stdio.h>
#include <stdint.h>

#include "menu.h"
#include "utils.h"
#include "dynamic_stack_menu.h"
#include "circular_queue_menu.h"
#include "array_list_menu.h"
#include "sorting/bubble_sort.h"

static void display_main_menu(uint16_t *opt){
  printf("\n\nChoose an algorithm \n");
  printf("%d - Dynamic Stack \n", OPT_STACK_MENU);
  printf("%d - Circular Queue \n", OPT_QUEUE_MENU);
  printf("%d - Array List \n", OPT_ARRAY_LIST);
  printf("%d - Bubble Sort \n", OPT_BUBBLE_SORT);
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

      case OPT_BUBBLE_SORT:
        int32_t vec[20] = {99,105,75,34,87,22,6,8,7,245,690,11,230,111,144,132,3,55,1};

        printf("\n Original vector: ");
        for(int32_t i = 0; i < 20; i++){
          printf(" %d", vec[i]);
        }

        bubble_sort(vec, 20);

        printf("\n Vector after applying bubble sort ascending algorithm: ");
        for(int32_t i = 0; i < 20; i++){
          printf(" %d", vec[i]);
        }

        break;
    }
  }while(opt != OPT_QUIT);
}

void menu_init(){
  handle_main_menu();
}