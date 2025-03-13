/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
* Date: 2025-03-13
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "circular_queue/queue.h"

enum{
  OPT_QUIT,
  OPT_QUEUE_LIST_ITEMS,
  OPT_QUEUE_ADD_ITEM,
  OPT_QUEUE_REMOVE_ITEM,
} MENU_OPT;

int menu(){
  unsigned short opt = 0;
  QUEUE_RES res;

  do{
    printf("\n\nChoose an option: \n");
    printf("View circular queue list: %d \n", OPT_QUEUE_LIST_ITEMS);
    printf("Add item to circular queue: %d \n", OPT_QUEUE_ADD_ITEM);
    printf("Remove item from circular queue: %d \n", OPT_QUEUE_REMOVE_ITEM);
    printf("Quit: %d \n", OPT_QUIT);

    scanf("%hu", &opt);
    if(opt == OPT_QUIT) return 0;

    switch(opt){
      case OPT_QUEUE_LIST_ITEMS:
        char **p_queue_items = NULL;
        res = queue_dump(&p_queue_items);

        if(res == QUEUE_RES_MEM_ALLOC_ERR){
          printf("A memory allocation error has ocurred. \n");
          break;
        }
        if(res != QUEUE_RES_OK){
          printf("A error has ocurred while dumping queue. \n");
          break;
        }

        for(int i = 0; i < queue_elements; i++){
          printf("Item: %s \n", p_queue_items[i]);
        }

        queue_dump_free(&p_queue_items);

        break;
      case OPT_QUEUE_ADD_ITEM:
        res = queue_add("String to add");

        if(res == QUEUE_RES_FULL) printf("Queue is full \n");
        if(res != QUEUE_RES_OK) printf("A error has ocurred while adding item to queue. \n");


        break;
      case OPT_QUEUE_REMOVE_ITEM:
        char removed_str[QUEUE_STRING_LENGTH];

        res = queue_remove(removed_str);

        if(res == QUEUE_RES_EMPTY) printf("Queue is empty \n");
        if(res != QUEUE_RES_OK) printf("A error has ocurred while removing queue item. \n");

        printf("Removed item: %s \n", removed_str);

        break;
    }

  }while(opt != OPT_QUIT);
}

int main(int argc, char * argv[]){
  menu();

  return 0;
}