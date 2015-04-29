#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct SAC AC;

typedef struct SAC{
   int* temp;
   int x;
}AC;

void main(){
   AC** acs;acs=malloc(sizeof(AC*));
   acs=(AC*[2]){NULL, malloc(sizeof(AC))};
   acs[1]->temp=(int[3]){1, 2, 3};
   acs[1]->x=5;

}
