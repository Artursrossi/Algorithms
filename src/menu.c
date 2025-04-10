/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
* Last modification date: 2025-04-06
*/

#include <stdio.h>
#include <stdint.h>

#include "menu.h"
#include "utils.h"
#include "dynamic_stack/stack.h"
#include "circular_queue/queue.h"
#include "sorting/bubble_sort.h"

/* Variables */
static uint16_t opt = 0;

static void display_main_menu(){
  printf("\n\nChoose an algorithm \n");
  printf("%d - Dynamic Stack \n", OPT_STACK_MENU);
  printf("%d - Circular Queue \n", OPT_QUEUE_MENU);
  printf("%d - Test Bubble Sort \n", OPT_TEST_BUBBLE_SORT);
  printf("%d - Quit \n", OPT_QUIT);

  scanf("%hu", &opt);
}

static void display_stack_menu(){
  printf("\n\nChoose an option \n");
  printf("%d - View stack \n", OPT_STACK_VIEW);
  printf("%d - Add item to stack \n", OPT_STACK_PUSH);
  printf("%d - Remove item from stack \n", OPT_STACK_POP);
  printf("%d - Return to main menu \n", OPT_RETURN_MAIN_MENU);

  scanf("%hu", &opt);
}

static void display_queue_menu(){
  printf("\n\nChoose an option \n");
  printf("%d - View circular queue list \n", OPT_QUEUE_VIEW);
  printf("%d - Add item to circular queue \n", OPT_QUEUE_ADD);
  printf("%d - Remove item from circular queue \n", OPT_QUEUE_REMOVE);
  printf("%d - Return to main menu \n", OPT_RETURN_MAIN_MENU);

  scanf("%hu", &opt);
}

static void handle_stack_menu(){
  STACK_RES stack_res;
  const uint32_t STRING_SIZE = 64;

  do{
    display_stack_menu();

    switch(opt){
      case OPT_STACK_VIEW:
        char **stack_clone = NULL;

        stack_res = stack_dump((void ***) &stack_clone);

        /* Catch exceptions  */
        if(stack_res == STACK_NOT_INITIALIZED){
          printf("Stack not initialized. \n");
          break;
        }
        if(stack_res == STACK_RES_EMPTY){
          printf("Stack is empty. \n");
          break;
        }
        if(stack_res != STACK_RES_OK) printf("A error has ocurred while listing stack items. \n");

        /* Display each element of stack */
        for(uint32_t i = 0; i < stack_size(); i++){
          printf("Element %d: %s \n", (i+1), (char *) stack_clone[i]);
        }

        free(stack_clone);
        stack_clone = NULL;

        break;
      case OPT_STACK_PUSH:
        char *str = (char *) malloc(STRING_SIZE * sizeof(char));

        /* Get user input */
        printf("Digit a text to be added to stack: \n");
        clear_buffer();
        fgets(str, STRING_SIZE, stdin);
        str[strcspn(str, "\n")] = '\0'; /* Remove newline (Enter) from stdin */

        /* Prevent NULL pointer from fgets() */
        if(str == NULL){
          printf("A memory allocation error has ocurred. \n");
          break;
        }

        stack_res = stack_push(str);

        /* Catch exceptions  */
        if(stack_res == STACK_NOT_INITIALIZED){
          printf("Stack not initialized. \n");
          break;
        }
        if(stack_res != STACK_RES_OK) printf("A error has ocurred while adding stack element. \n");

        break;
      case OPT_STACK_POP:
        char *removed_str = NULL;

        stack_res = stack_pop((void**) &removed_str);

        /* Catch exceptions  */
        if(stack_res == STACK_NOT_INITIALIZED){
          printf("Stack not initialized. \n");
          break;
        }
        if(stack_res == STACK_RES_EMPTY){
          printf("Stack is empty. \n");
          break;
        }
        if(stack_res != STACK_RES_OK) printf("A error has ocurred while removing stack element. \n");

        if(removed_str != NULL){
          /* Print removed stack element */
          printf("Removed element: %s \n", removed_str);
  
          /* Free up temp removed_str variable*/
          free(removed_str);
          removed_str = NULL;
        }

        break;
    }
  }while(opt != OPT_RETURN_MAIN_MENU);
}

static void handle_queue_menu(){
  QUEUE_RES queue_res;

  do{
    display_queue_menu();

    switch(opt){
      case OPT_QUEUE_VIEW:
        char **p_queue_items = NULL;

        queue_res = queue_dump(&p_queue_items);

        /* Catch exceptions  */
        if(queue_res == QUEUE_RES_EMPTY){
          printf("Queue is empty, therefore there is nothing to dump. \n");
          break;
        }
        if(queue_res == QUEUE_RES_MEM_ALLOC_ERR){
          printf("A memory allocation error has ocurred. \n");
          break;
        }
        if(queue_res != QUEUE_RES_OK){
          printf("A error has ocurred while dumping queue. \n");
          break;
        }

        /* Display each element of queue */
        for(uint32_t i = 0; i < queue_elements; i++){
          printf("Item: %s \n", p_queue_items[i]);
        }

        queue_dump_free(&p_queue_items);

        break;
      case OPT_QUEUE_ADD:
        char buffer[QUEUE_STRING_LENGTH];

        /* Get user input */
        printf("Digit string to add: \n");
        clear_buffer();
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        queue_res = queue_add(buffer);

        /* Catch exceptions  */
        if(queue_res == QUEUE_RES_FULL) {
          printf("Queue is full \n");
          break;
        }
        if(queue_res != QUEUE_RES_OK) printf("A error has ocurred while adding item to queue. \n");

        break;
      case OPT_QUEUE_REMOVE:
        char removed_str[QUEUE_STRING_LENGTH];

        queue_res = queue_remove(removed_str);

        /* Catch exceptions  */
        if(queue_res == QUEUE_RES_EMPTY) {
          printf("Queue is empty \n");
          break;
        }
        if(queue_res != QUEUE_RES_OK) printf("A error has ocurred while removing queue item. \n");

        printf("Removed item: %s \n", removed_str);

        break;
    }

  }while(opt != OPT_RETURN_MAIN_MENU);
}

static void handle_main_menu(){
  do{
    display_main_menu();
    
    switch(opt){
      case OPT_STACK_MENU:
        handle_stack_menu();
        break;
      
      case OPT_QUEUE_MENU:
        handle_queue_menu();
        break;

      case OPT_TEST_BUBBLE_SORT:
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

void menu_initialize(){
  handle_main_menu();
}