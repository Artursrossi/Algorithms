/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
* Last modification date: 2025-05-01
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

  }while(opt != OPT_QUEUE_RETURN_MAIN_MENU);
}