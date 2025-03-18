/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
* Last modification date: 2025-03-17
*/

#include <stdio.h>

#include "menu.h"
#include "utils.h"
#include "dynamic_stack/stack.h"
#include "circular_queue/queue.h"

/* Variables */
static unsigned short opt = 0;

static void display_main_menu(){
  printf("\n\nChoose an algorithm \n");
  printf("%d - Dynamic Stack \n", OPT_STACK_MENU);
  printf("%d - Circular Queue \n", OPT_QUEUE_MENU);
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

  do{
    display_stack_menu();

    switch(opt){
      case OPT_STACK_VIEW:
        char *stack_clone = NULL;

        stack_res = stack_dump(&stack_clone);

        /* Catch exceptions  */
        if(stack_res == STACK_NOT_INITIALIZED){
          printf("Stack not initialized. \n");
          break;
        }
        if(stack_res == STACK_RES_EMPTY){
          printf("Stack is empty. \n");
          break;
        }
        if(stack_res == STACK_RES_MEM_ALLOC_ERR){
          printf("A memory allocation error has ocurred. \n");
          break;
        }
        if(stack_res != STACK_RES_OK) printf("A error has ocurred while listing stack items. \n");

        /* Display each element of stack */
        for(int i = 0; i < stack_elements; i++){
          printf("Item: %c \n", stack_clone[i]);
        }

        stack_dump_free(&stack_clone);

        break;
      case OPT_STACK_PUSH:
        char ch;

        /* Get user input */
        printf("Digit a character to add: \n");
        clear_buffer();
        ch = getchar();

        stack_res = stack_push(ch);

        /* Catch exceptions  */
        if(stack_res == STACK_NOT_INITIALIZED){
          printf("Stack not initialized. \n");
          break;
        }
        if(stack_res == STACK_RES_MEM_ALLOC_ERR){
          printf("A memory allocation error has ocurred. \n");
          break;
        }
        if(stack_res != STACK_RES_OK) printf("A error has ocurred while adding stack item. \n");

        break;
      case OPT_STACK_POP:
        char removed_ch;

        stack_res = stack_pop(&removed_ch);

        /* Catch exceptions  */
        if(stack_res == STACK_NOT_INITIALIZED){
          printf("Stack not initialized. \n");
          break;
        }
        if(stack_res == STACK_RES_EMPTY){
          printf("Stack is empty. \n");
          break;
        }
        if(stack_res != STACK_RES_OK) printf("A error has ocurred while removing stack item. \n");

        printf("Removed item: %c \n", removed_ch);

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
        for(int i = 0; i < queue_elements; i++){
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
    }
  }while(opt != OPT_QUIT);
}

void menu_initialize(){
  handle_main_menu();
}