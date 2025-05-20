/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
*/

#include "selection_sort.h"

void selection_sort(int32_t *vec, int32_t vec_length){
  int32_t min_index = 0;
  int32_t temp = 0;

  for(int32_t i = 0; i < vec_length - 1; i++){
    min_index = i;

    for(int32_t j = (i+1); j < vec_length; j++){
      if(vec[j] < vec[min_index]) min_index = j;
    }

    temp = vec[i];
    vec[i] = vec[min_index];
    vec[min_index] = temp;
  }

  return;
}