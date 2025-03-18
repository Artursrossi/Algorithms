/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
* Last modification date: 2025-03-17
*/

#include <stdio.h>

void clear_buffer(){
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
  return;
}