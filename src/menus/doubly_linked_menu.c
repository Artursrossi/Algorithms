/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "doubly_linked_menu.h"
#include "data_structures/doubly_linked_list/doubly_linked.h"
#include "utils.h"

static void display_doubly_linked_menu(uint16_t *opt){
  printf("\n\nChoose an option \n");
  printf("%d - View doubly linked list \n", OPT_DOUBLY_LINKED_VIEW);
  printf("%d - Get length \n", OPT_DOUBLY_LINKED_GET_LENGTH);
  printf("%d - Insert element \n", OPT_DOUBLY_LINKED_INSERT);
  printf("%d - Remove element \n", OPT_DOUBLY_LINKED_REMOVE);
  printf("%d - Reverse list \n", OPT_DOUBLY_LINKED_REVERSE);
  printf("%d - Return to main menu \n", OPT_DOUBLY_LINKED_RETURN_MAIN_MENU);

  scanf("%hu", opt);
}

void doubly_linked_print_fnc(int32_t data) {
  printf("Data: %d \n", data);
}

void handle_doubly_linked_menu(){
  uint16_t opt = 0;

  do{
    display_doubly_linked_menu(&opt);

    switch(opt){
      case OPT_DOUBLY_LINKED_VIEW:
        doubly_linked_iteration(doubly_linked_print_fnc);

        break;

      case OPT_DOUBLY_LINKED_GET_LENGTH:
        printf("Doubly linked list length: %d", doubly_linked_length());

        break;

      case OPT_DOUBLY_LINKED_INSERT:
        int32_t data_to_insert = 0;

        /* Get user input */
        printf("Digit a number to insert: \n");
        scanf("%d", &data_to_insert);

        doubly_linked_insert(data_to_insert);

        break;

      case OPT_DOUBLY_LINKED_REMOVE:
        int32_t data_to_remove = 0;

        /* Get user input */
        printf("Digit a number to remove: \n");
        scanf("%d", &data_to_remove);

        bool is_deleted = doubly_linked_remove(data_to_remove);

        if(!is_deleted) printf("Element not found.");

        break;

      case OPT_DOUBLY_LINKED_REVERSE:
        doubly_linked_reverse();

        break;
    }

  }while(opt != OPT_DOUBLY_LINKED_RETURN_MAIN_MENU);
}