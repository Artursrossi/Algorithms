/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
* Date: 2025-03-17
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "circular_queue/queue.h"
#include "dynamic_stack/stack.h"

enum{
  OPT_QUIT,
  OPT_QUEUE_VIEW,
  OPT_QUEUE_ADD,
  OPT_QUEUE_REMOVE,
  OPT_STACK_VIEW,
  OPT_STACK_PUSH,
  OPT_STACK_POP,
} MENU_OPT;

void clearBuffer();

int menu(){
  unsigned short opt = 0;
  QUEUE_RES res;

  do{
    printf("\n\nChoose an option \n");
    printf("%d - View circular queue list \n", OPT_QUEUE_VIEW);
    printf("%d - Add item to circular queue \n", OPT_QUEUE_ADD);
    printf("%d - Remove item from circular queue \n", OPT_QUEUE_REMOVE);
    printf("%d - View stack \n", OPT_STACK_VIEW);
    printf("%d - Add item to stack \n", OPT_STACK_PUSH);
    printf("%d - Remove item from stack \n", OPT_STACK_POP);
    printf("%d - Quit \n", OPT_QUIT);

    scanf("%hu", &opt);
    if(opt == OPT_QUIT) return 0;

    switch(opt){
      case OPT_QUEUE_VIEW:
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
      case OPT_QUEUE_ADD:
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
      case OPT_QUEUE_REMOVE:
        char removed_str[QUEUE_STRING_LENGTH];

        res = queue_remove(removed_str);

        if(res == QUEUE_RES_EMPTY) {
          printf("Queue is empty \n");
          break;
        }
        if(res != QUEUE_RES_OK) printf("A error has ocurred while removing queue item. \n");

        printf("Removed item: %s \n", removed_str);

        break;
      case OPT_STACK_VIEW:
        char *stack_clone;

        res = stack_dump(&stack_clone);
        if(res == STACK_NOT_INITIALIZED){
          printf("Stack not initialized. \n");
          break;
        }
        if(res == STACK_RES_EMPTY){
          printf("Stack is empty. \n");
          break;
        }
        if(res == STACK_RES_MEM_ALLOC_ERR){
          printf("A memory allocation error has ocurred. \n");
          break;
        }
        if(res != STACK_RES_OK) printf("A error has ocurred while listing stack items. \n");

        for(int i = 0; i < stack_elements; i++){
          printf("Item: %c \n", stack_clone[i]);
        }

        stack_dump_free(&stack_clone);

        break;
      case OPT_STACK_PUSH:
        char ch;

        printf("Digit a character to add: \n");
        clearBuffer();
        ch = getchar();

        res = stack_push(ch);
        if(res == STACK_NOT_INITIALIZED){
          printf("Stack not initialized. \n");
          break;
        }
        if(res == STACK_RES_MEM_ALLOC_ERR){
          printf("A memory allocation error has ocurred. \n");
          break;
        }
        if(res != STACK_RES_OK) printf("A error has ocurred while adding stack item. \n");

        break;
      case OPT_STACK_POP:
        char removed_ch;

        res = stack_pop(&removed_ch);
        if(res == STACK_NOT_INITIALIZED){
          printf("Stack not initialized. \n");
          break;
        }
        if(res == STACK_RES_EMPTY){
          printf("Stack is empty. \n");
          break;
        }
        if(res != STACK_RES_OK) printf("A error has ocurred while removing stack item. \n");

        printf("Remove item: %c \n", removed_ch);

        break;
    }

  }while(opt != OPT_QUIT);
}

int main(int argc, char * argv[]){
  stack_initialize();

  menu();

  stack_free();

  return 0;
}

void clearBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
  return;
}