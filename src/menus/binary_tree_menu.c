/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "binary_tree_menu.h"
#include "data_structures/binary_tree/binary_tree.h"
#include "utils.h"

static void display_binary_tree_menu(uint16_t *opt){
  printf("\n\nChoose an option \n");
  printf("%d - View binary tree (rotated 90 degrees) \n", OPT_BINARY_TREE_VIEW);
  printf("%d - Get length (number of nodes) \n", OPT_BINARY_TREE_GET_LENGTH);
  printf("%d - Get height (max depth) \n", OPT_BINARY_TREE_GET_HEIGHT);
  printf("%d - Insert element \n", OPT_BINARY_TREE_INSERT);
  printf("%d - Search element \n", OPT_BINARY_TREE_SEARCH);
  printf("%d - Remove element \n", OPT_BINARY_TREE_REMOVE);
  printf("%d - Return to main menu \n", OPT_BINARY_TREE_RETURN_MAIN_MENU);

  scanf("%hu", opt);
}

/* Pretty print binary tree, rotating 90 degrees (easiest way) */
void bt_pretty_print_node(int32_t data, int32_t level){
  const int32_t SPACE = 5;

  printf("\n");
  for (int32_t i = 0; i < level * SPACE; i++) printf(" ");
  printf("%d", data);

  return;
}

void handle_binary_tree_menu(){
  uint16_t opt = 0;

  do{
    display_binary_tree_menu(&opt);

    switch(opt){
      case OPT_BINARY_TREE_VIEW:
        binary_tree_reverse_inorder_iteration(bt_pretty_print_node);

        break;

      case OPT_BINARY_TREE_GET_LENGTH:
        printf("Binary tree length: %d", binary_tree_length());

        break;

      case OPT_BINARY_TREE_GET_HEIGHT:
        printf("Binary tree height (max depth): %d", binary_tree_height());

        break;

      case OPT_BINARY_TREE_INSERT:
        int32_t data_to_insert = 0;

        /* Get user input */
        printf("Digit a number to insert: \n");
        scanf("%d", &data_to_insert);

        bool successful_inserted = binary_tree_insert(data_to_insert);

        if(!successful_inserted) printf("Value already exist on binary tree (duplicate)\n");

        break;

      case OPT_BINARY_TREE_SEARCH:
        int32_t data_to_search = 0;

        /* Get user input */
        printf("Digit a number to remove: \n");
        scanf("%d", &data_to_search);

        bool is_founded = binary_tree_search(data_to_search);

        if(is_founded) printf("Value %d exists on binary tree\n", data_to_search);
        if(!is_founded) printf("Value not found\n");

        break;

      case OPT_BINARY_TREE_REMOVE:
        int32_t data_to_remove = 0;

        /* Get user input */
        printf("Digit a number to remove: \n");
        scanf("%d", &data_to_remove);

        bool is_deleted = binary_tree_remove(data_to_remove);

        if(!is_deleted) printf("Value not found\n");

        break;
    }

  }while(opt != OPT_BINARY_TREE_RETURN_MAIN_MENU);
}