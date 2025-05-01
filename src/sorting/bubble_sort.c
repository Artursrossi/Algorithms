/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
* Last modification date: 2025-03-17
*/

#include <stdint.h>

void bubble_sort(int32_t *vec, int32_t elements){
  int32_t temp = 0;

  for(int32_t i = 0; i < (elements - 1); i++){
    for(int32_t j = (i + 1); j < elements; j++){
      if(vec[i] > vec[j]){
        temp = vec[i];
        vec[i] = vec[j];
        vec[j] = temp;
      }
    }
  }

  return;
}