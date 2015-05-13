#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

typedef struct SA A;
typedef struct SB B;

NEW_STRUCT (SA, int x;);

 NEW_SIMPLECONST(A);
NEW_STRUCT (SB, int x;);

 NEW_SIMPLECONST(B);
int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 2;
   A* a = New_A();var_push(&a);
   B* b = New_B();var_push(&b);
   int z;
   a=New_A();

   b=New_B();

   z=(a->x + b->x);


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}
