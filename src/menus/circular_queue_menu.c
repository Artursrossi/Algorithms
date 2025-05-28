/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "circular_queue_menu.h"
#include "data_structures/circular_queue/queue.h"
#include "utils.h"

static void display_queue_menu(uint16_t *opt){
  printf("\n\nChoose an option \n");
  printf("%d - View circular queue list \n", OPT_QUEUE_VIEW);
  printf("%d - Get queue length \n", OPT_QUEUE_LENGTH);
  printf("%d - Add item to circular queue \n", OPT_QUEUE_ADD);
  printf("%d - Remove item from circular queue \n", OPT_QUEUE_REMOVE);
  printf("%d - Return to main menu \n", OPT_QUEUE_RETURN_MAIN_MENU);

  scanf("%hu", opt);
}

void handle_queue_menu(){
  uint16_t opt = 0;

  QUEUE_RES queue_res;

  do{
    display_queue_menu(&opt);

    switch(opt){
      case OPT_QUEUE_VIEW:
        void **p_queue_items = NULL;

        queue_res = queue_dump(&p_queue_items);

        if(queue_res != QUEUE_RES_OK) break;

        /* Display each element of queue */
        for(uint32_t i = 0; i < queue_length(); i++){
          printf("Item: %s \n", (char *)p_queue_items[i]);
        }

        free(p_queue_items);
        p_queue_items = NULL;

        break;
      case OPT_QUEUE_LENGTH:
        printf("Circular queue length: %d \n", queue_length());

        break;
      case OPT_QUEUE_ADD:
        char *buffer = (char *) malloc(QUEUE_STRING_LENGTH * sizeof(char));
        if(buffer == NULL){
          perror("A memory allocation error has occurred. (circular_queue_menu.c) \n");
          exit(EXIT_FAILURE);
        }

        /* Get user input */
        printf("Digit string to add: \n");
        clear_buffer();
        fgets(buffer, QUEUE_STRING_LENGTH, stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; /* Remove newline (Enter) from stdin */

        queue_res = queue_add(buffer);

      /* If queue cannot insert object, free up the memory space (common cases: Queue Full) */
        if(queue_res != QUEUE_RES_OK){
          free(buffer);
          buffer = NULL;
        }

        break;
      case OPT_QUEUE_REMOVE:
        char *removed_str = NULL;

        queue_res = queue_remove((void**) &removed_str);

        if(queue_res != QUEUE_RES_OK) break;
        
        printf("Removed item: %s \n", removed_str);

        free(removed_str);
        removed_str = NULL;
        
        break;
    }

    /* Catch generic responses */
    if(queue_res == QUEUE_NOT_INITIALIZED)
      printf("Queue not initialized. \n");
      
    if(queue_res == QUEUE_RES_EMPTY)
      printf("Queue is empty, therefore there is nothing to dump. \n");

    if(queue_res == QUEUE_RES_FULL)
      printf("Queue is full \n");

  }while(opt != OPT_QUEUE_RETURN_MAIN_MENU);
}