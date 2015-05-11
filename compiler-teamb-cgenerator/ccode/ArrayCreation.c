#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

typedef struct SAC AC;

struct SAC{
   int* temp;
   int x;

};

int main(){
   AC** acs;
   acs=malloc(sizeof(AC*));
   acs=(AC*[2]){NULL, malloc(sizeof(AC))};
   acs[1]->temp=(int[3]){1, 2, 3};
   acs[1]->x=5;

   return 0;
}
