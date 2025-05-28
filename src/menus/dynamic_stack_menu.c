/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "dynamic_stack_menu.h"
#include "data_structures/dynamic_stack/stack.h"
#include "utils.h"

static void display_stack_menu(uint16_t *opt){
  printf("\n\nChoose an option \n");
  printf("%d - View stack \n", OPT_STACK_VIEW);
  printf("%d - Add item to stack \n", OPT_STACK_PUSH);
  printf("%d - Remove item from stack \n", OPT_STACK_POP);
  printf("%d - Return to main menu \n", OPT_STACK_RETURN_MAIN_MENU);

  scanf("%hu", opt);
}

void handle_stack_menu(){
  uint16_t opt = 0;

  STACK_RES stack_res;
  const uint32_t STRING_SIZE = 64;

  do{
    display_stack_menu(&opt);

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
        if(str == NULL){
          perror("A memory allocation error has occurred. (dynamic_stack_menu.c) \n");
          exit(EXIT_FAILURE);
        }

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
  }while(opt != OPT_STACK_RETURN_MAIN_MENU);
}