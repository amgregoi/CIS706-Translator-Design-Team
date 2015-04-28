#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


void main(){
   int i;
   int* a;
   int* b;
   i = 0;
   a = (int[3]){1, 2, 3};
   b = malloc(sizeof(int)*3);
   b[i] = a[a[i]];
   b[a[i] * i] = a[b[a[i]]];
}
