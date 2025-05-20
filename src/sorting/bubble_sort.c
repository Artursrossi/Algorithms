/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
*/

#include "bubble_sort.h"

void bubble_sort(int32_t *vec, int32_t vec_length){
  int32_t temp = 0;

  for(int32_t i = 0; i < (vec_length - 1); i++){
    for(int32_t j = (i + 1); j < vec_length; j++){
      if(vec[i] > vec[j]){
        temp = vec[i];
        vec[i] = vec[j];
        vec[j] = temp;
      }
    }
  }

  return;
}