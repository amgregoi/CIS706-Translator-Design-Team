#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

typedef struct SAC AC;

struct SAC{
    int* temp;
    var_push(&temp);
    int x;
    var_push(&x);

};

int main(){
   Array* acs;
   acs=New_Array(0); ARRAYSET(acs, 0) = NULL;
   ARRAYSET(acs, 1) = New_AC();
   ;
   acs[1]->temp=New_Array(0); ARRAYSET(acs[1]->temp, 0) = 1;
   ARRAYSET(acs[1]->temp, 1) = 2;
   ARRAYSET(acs[1]->temp, 2) = 3;
   ;
   acs[1]->x=5;

   return 0;
}
