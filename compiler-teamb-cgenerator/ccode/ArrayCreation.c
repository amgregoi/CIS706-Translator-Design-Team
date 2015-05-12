#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

typedef struct SAC AC;

NEW_STRUCT (SAC,  Array* temp ;
;int x;);

NEW_CONST(AC, 1, ptr, &(ptr->temp));

int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 1;
    Array* acs = NULL;
   ;var_push(&acs);
   acs=New_Array(0); ARRAYGET(acs, 0) = NULL;
   ARRAYGET(acs, 1) = New_AC();
   ;
   ((AC*)ARRAYGET(acs, 1))->temp=New_Array(0); ARRAYGET(((AC*)ARRAYGET(acs, 1))->temp, 0) = New_Integer(1);
   ARRAYGET(((AC*)ARRAYGET(acs, 1))->temp, 1) = New_Integer(2);
   ARRAYGET(((AC*)ARRAYGET(acs, 1))->temp, 2) = New_Integer(3);
   ;
   ((AC*)ARRAYGET(acs, 1))->x=5;


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}
