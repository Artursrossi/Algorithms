/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
*/

#ifndef TEST_SORTING_ALGORITHM_H
#define TEST_SORTING_ALGORITHM_H

#include <stdint.h>

#define ROWS 20
#define COLS 20
#define MAX_NUMBER 256
#define MIN_NUMBER -64

/* Functions prototypes */

/**
 * @brief This function will generate n vectors (ROWS) with n random numbers (COLS) [MIN_NUMBER <= number <= MAX_NUMBER].
 *  And then, run tests on the received vector (sorting_fnc)
 * 
 * @param sorting_fnc Pointer to a sorting function that will receive a vector w/ length, and sort the vector in ascending order
*/
void test_sorting_algorithm(void (*sorting_fnc)(int32_t *, int32_t));

#endif // TEST_SORTING_ALGORITHM_H
