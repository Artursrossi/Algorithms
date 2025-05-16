/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
*/

#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

/* Variables */
static node_t *head = NULL;
static int32_t length = 0;

/* Free up memory space for each Node of linked list, using recursively function for preventing memory leak */
static void recursive_free(node_t *node){
  if (node->next != NULL) recursive_free(node->next);
  
  free(node);
}

void linked_list_destroy(){
  if(head == NULL) return;

  recursive_free(head);
  head = NULL;
}

static node_t * create_node(int32_t data){
  /* Allocate memory space (in BYTES) for a Node of linked list */
  node_t *node = (node_t *) malloc(sizeof(node_t));
  if(node == NULL){
    perror("A memory allocation error has occurred. (linked_list.c) \n");
    exit(EXIT_FAILURE);
  }

  node->data = data;
  node->next = NULL;

  return node;
}

void linked_list_insert(int32_t data){
  node_t *new_node = create_node(data);
  length++;

  /* First element of linked list */
  if(head == NULL){
    head = new_node;
    return;
  }

  /* If new node is lower than first element, then put it on the first position */
  if(new_node->data < head->data){
    new_node->next = head;
    head = new_node;
    return;
  }

  /* Temp iteration variables */
  node_t *aux = head;
  node_t *aux_prev = NULL;

  /* Move iteration pointers */
  while(new_node->data >= aux->data && aux->next != NULL){
    aux_prev = aux;
    aux = aux->next;
  }

  /* Insert on the end */
  if(new_node->data >= aux->data){
    printf("Here\n");
    aux->next = new_node;
    return;
  }
  
  /* Inset in the middle */
  new_node->next = aux;
  aux_prev->next = new_node;

  return;
}

bool linked_list_remove(int32_t data){ 
  if(head == NULL) return false;
  
  /* Temp iteration variables */
  node_t *aux = head;
  node_t *aux_prev = NULL;

  /* Delete first element */
  if(head->data == data){
    head = aux->next; 
    free(aux);
    length--;
    return true;
  }

  /* Move iteration pointers */
  while(aux->next != NULL){
    aux_prev = aux;
    aux = aux->next;

    if(aux->data == data){
      /* Element on the end */
      if(aux->next == NULL) aux_prev->next = NULL;

      /* Element in the middle */
      if(aux->next != NULL) aux_prev->next = aux->next;

      free(aux);
      length--;
      return true;
    }
  }

  return false;
}

void linked_list_iteration(void (*iteration_fnc)(int32_t)){
  if(head == NULL) return;

  node_t *aux = head;

  /* Execute generic received function for each element of linked list */
  while(aux != NULL){
    iteration_fnc(aux->data);
    aux = aux->next;
  }

  return;
}

int32_t linked_list_length(){
  return length;
}

void linked_list_reverse(){
  node_t *aux_prev = NULL, *aux = head, *aux_next = NULL;

  while(aux != NULL){
    aux_next = aux->next;
    
    /* Update next pointer with previous element */
    aux->next = aux_prev;

    /* Move pointers */
    aux_prev = aux;
    aux = aux_next;
  }

  head = aux_prev;

  return;
}