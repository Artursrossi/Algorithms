/**
* Author: Artur Schincariol Rossi <schincariolartur@gmail.com>
*/

#include <stdio.h>

void clear_buffer(){
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}