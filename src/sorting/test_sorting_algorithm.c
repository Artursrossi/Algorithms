#include <stdio.h>
#include <stdlib.h>

#include "test_sorting_algorithm.h"

static void generate_test_matrix(int32_t matrix[ROWS][COLS]){
  for(int32_t i = 0; i < ROWS; i++){
    for(int32_t j = 0; j < COLS; j++){
      matrix[i][j] = (rand() % (MAX_NUMBER - MIN_NUMBER + 1)) + MIN_NUMBER;
    }
  }
}

static void print_vector(int32_t vector[COLS]) {
  for (int32_t i = 0; i < COLS; i++) {
    printf("%d ", vector[i]);
  }
  printf("\n");
}

void test_sorting_algorithm(void (*sorting_fnc)(int32_t *, int32_t)){
  int32_t matrix[ROWS][COLS];

  generate_test_matrix(matrix);
  
  for(int32_t i = 0; i < ROWS; i++){
    printf("---------------------------------------------- TEST %d ----------------------------------------------\n", i + 1);
    printf("Unsorted vector: ");
    print_vector(matrix[i]);

    sorting_fnc(matrix[i], COLS);

    printf("Sorted vector: ");
    print_vector(matrix[i]);
    printf("-----------------------------------------------------------------------------------------------------\n");
  }

  return;
}