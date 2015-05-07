#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct SA A;
typedef struct SB B;

struct SA{
   int x;

};

struct SB{
   int x;

};

int main(){
   A* a;
   B* b;
   int z;
   a=malloc(sizeof(A));
   b=malloc(sizeof(B));
   z=(a->x + b->x);

   return 0;
}
