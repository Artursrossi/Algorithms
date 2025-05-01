/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "array_list_menu.h"
#include "data_structures/array_list/array_list.h"
#include "utils.h"

static void display_array_menu(uint16_t *opt){
  printf("\n\nChoose an option \n");
  printf("%d - View array list \n", OPT_ARRAY_VIEW);
  printf("%d - Find item by value \n", OPT_ARRAY_FIND);
  printf("%d - Get item by index \n", OPT_ARRAY_GET);
  printf("%d - Push item to array list \n", OPT_ARRAY_PUSH);
  printf("%d - Pop last item of array list \n", OPT_ARRAY_POP);
  printf("%d - Remove item by value \n", OPT_ARRAY_REMOVE);
  printf("%d - Replace item by index \n", OPT_ARRAY_SET);
  printf("%d - Sort array list by asc \n", OPT_ARRAY_SORT_ASC);
  printf("%d - Sort array list by desc \n", OPT_ARRAY_SORT_DESC);
  printf("%d - Return to main menu \n", OPT_ARRAY_RETURN_MAIN_MENU);

  scanf("%hu", opt);
}

void handle_array_menu(){
  uint16_t opt = 0;

  ARRAY_RES array_res;

  do{
    display_array_menu(&opt);

    switch(opt){
      case OPT_ARRAY_VIEW:
        int32_t *p_array_list = NULL;

        array_res = array_dump(&p_array_list);

        if(array_res != ARRAY_RES_OK) break;

        /* Display each element of array list */
        for(int32_t i = 0; i < array_length(); i++){
          printf("Item: %d \n", p_array_list[i]);
        }

        free(p_array_list);
        p_array_list = NULL;

        break;

      case OPT_ARRAY_FIND:
        int32_t value_to_find = 0;
        int32_t value_index = -1;

        /* Get user input */
        printf("Digit a value to find: \n");
        scanf("%d", &value_to_find);

        value_index = array_find(value_to_find);

        if(value_index != -1)
          printf("The index of value is: %d \n", value_index);
        
        break;

      case OPT_ARRAY_GET:
        int32_t get_index = -1;
        int32_t getted_value = 0;

        /* Get user input */
        printf("Get value by index: \n");
        scanf("%d", &get_index);

        array_res = array_get(get_index, &getted_value);

        if(array_res != ARRAY_RES_OK) break;

        printf("The value of index %d is: %d", get_index, getted_value);
        
        break;

      case OPT_ARRAY_PUSH:
        int32_t value_to_push = 0;

        /* Get user input */
        printf("Digit a number to add: \n");
        scanf("%d", &value_to_push);

        array_res = array_push(value_to_push);
        
        break;

      case OPT_ARRAY_POP:
        int32_t removed_value = 0;

        array_res = array_pop(&removed_value);

        if(array_res != ARRAY_RES_OK) break;

        printf("Removed item: %d \n", removed_value);
        
        break;

      case OPT_ARRAY_REMOVE:
        int32_t value_to_remove = 0;

        /* Get user input */
        printf("Digit a number to remove: \n");
        scanf("%d", &value_to_remove);

        array_res = array_remove(value_to_remove);
        
        break;

      case OPT_ARRAY_SET:
        int32_t set_index = 0;
        int32_t set_new_value = 0;

        /* Get user input */
        printf("Digit a index to set: \n");
        scanf("%d", &set_index);
        printf("Digit the new value to set: \n");
        scanf("%d", &set_new_value);

        array_res = array_set(set_index, set_new_value);
        
        break;

      case OPT_ARRAY_SORT_ASC:
        array_res = array_sort(true);
        
        break;

      case OPT_ARRAY_SORT_DESC:
      array_res = array_sort(false);
        
        break;
    }

    /* Catch array response  */
    if(array_res == ARRAY_RES_NOT_INITIALIZED)
      printf("Array list not initialized. \n");
    
    if(array_res == ARRAY_RES_EMPTY)
      printf("Array list is empty. \n");
    
    if(array_res == ARRAY_RES_NOT_FOUND) 
      printf("Item not found. \n");

  }while(opt != OPT_ARRAY_RETURN_MAIN_MENU);
}