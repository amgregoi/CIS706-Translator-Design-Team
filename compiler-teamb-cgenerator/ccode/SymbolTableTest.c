#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct SA A;
typedef struct SB B;

typedef struct SA{
   int x;
}A;

typedef struct SB{
   int x;
}B;

void main(){
   A* a;B* b;int z;a=malloc(sizeof(A));
   b=malloc(sizeof(B));
   z=(a->x + b->x);

}
