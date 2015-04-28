#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


void main(){
   int* i;
   int* j;
   bool* b;
   bool* c;
   i = malloc(sizeof(int)*4);
   j = (int[3]){1, 2, 3};
   b = malloc(sizeof(bool)*4);
   c = malloc(sizeof(bool));
   c = (bool[2]){true, false};
}
