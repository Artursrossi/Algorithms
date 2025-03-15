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

void clearBuffer();

int menu(){
  unsigned short opt = 0;
  QUEUE_RES res;

  do{
    printf("\n\nChoose an option \n");
    printf("%d - View circular queue list \n", OPT_QUEUE_LIST_ITEMS);
    printf("%d - Add item to circular queue \n", OPT_QUEUE_ADD_ITEM);
    printf("%d - Remove item from circular queue \n", OPT_QUEUE_REMOVE_ITEM);
    printf("%d - Quit \n", OPT_QUIT);

    scanf("%hu", &opt);
    if(opt == OPT_QUIT) return 0;

    switch(opt){
      case OPT_QUEUE_LIST_ITEMS:
        char **p_queue_items = NULL;
        res = queue_dump(&p_queue_items);

        if(res == QUEUE_RES_EMPTY){
          printf("Queue is empty, therefore there is nothing to dump. \n");
          break;
        }
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
        char buffer[QUEUE_STRING_LENGTH];

        printf("Digit string to add: \n");
        clearBuffer();
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        res = queue_add(buffer);

        if(res == QUEUE_RES_FULL) {
          printf("Queue is full \n");
          break;
        }
        if(res != QUEUE_RES_OK) printf("A error has ocurred while adding item to queue. \n");

        break;
      case OPT_QUEUE_REMOVE_ITEM:
        char removed_str[QUEUE_STRING_LENGTH];

        res = queue_remove(removed_str);

        if(res == QUEUE_RES_EMPTY) {
          printf("Queue is empty \n");
          break;
        }
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

void clearBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
  return;
}