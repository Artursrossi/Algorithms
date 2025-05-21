/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
*/

#include "insertion_sort.h"

void insertion_sort(int32_t *vec, int32_t vec_length){
  int32_t temp = 0;
  int32_t index = 0;

  for(int32_t i = 1; i < vec_length; i++){
    temp = vec[i];
    index = i;

    while(index >= 1 && temp < vec[index - 1]){
      vec[index] = vec[index - 1];
      index--;
    }

    vec[index] = temp;
  }

  return;
} 