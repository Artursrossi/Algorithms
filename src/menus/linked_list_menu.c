/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "linked_list_menu.h"
#include "data_structures/linked_list/linked_list.h"
#include "utils.h"

static void display_linked_list_menu(uint16_t *opt){
  printf("\n\nChoose an option \n");
  printf("%d - View linked list \n", OPT_LINKED_LIST_VIEW);
  printf("%d - Get length \n", OPT_LINKED_LIST_GET_LENGTH);
  printf("%d - Insert element \n", OPT_LINKED_LIST_INSERT);
  printf("%d - Remove element \n", OPT_LINKED_LIST_REMOVE);
  printf("%d - Reverse list \n", OPT_LINKED_LIST_REVERSE);
  printf("%d - Return to main menu \n", OPT_LINKED_LIST_RETURN_MAIN_MENU);

  scanf("%hu", opt);
}

void print_fnc(int32_t data) {
  printf("Data: %d \n", data);
}

void handle_linked_list_menu(){
  uint16_t opt = 0;

  do{
    display_linked_list_menu(&opt);

    switch(opt){
      case OPT_LINKED_LIST_VIEW:
        linked_list_iteration(print_fnc);

        break;

      case OPT_LINKED_LIST_GET_LENGTH:
        printf("Linked list length: %d", linked_list_length());

        break;

      case OPT_LINKED_LIST_INSERT:
        int32_t data_to_insert = 0;

        /* Get user input */
        printf("Digit a number to insert: \n");
        scanf("%d", &data_to_insert);

        linked_list_insert(data_to_insert);

        break;

      case OPT_LINKED_LIST_REMOVE:
        int32_t data_to_remove = 0;

        /* Get user input */
        printf("Digit a number to remove: \n");
        scanf("%d", &data_to_remove);

        bool is_deleted = linked_list_remove(data_to_remove);

        if(!is_deleted) printf("Element not found.");

        break;

      case OPT_LINKED_LIST_REVERSE:
        linked_list_reverse();

        break;
    }

  }while(opt != OPT_LINKED_LIST_RETURN_MAIN_MENU);
}