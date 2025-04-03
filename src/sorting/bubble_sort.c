/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
* Last modification date: 2025-03-17
*/

void bubble_sort(int *vec, int elements){
  int temp = 0;

  for(int i = 0; i < (elements - 1); i++){
    for(int j = (i + 1); j < elements; j++){
      if(vec[i] > vec[j]){
        temp = vec[i];
        vec[i] = vec[j];
        vec[j] = temp;
      }
    }
  }

  return;
}