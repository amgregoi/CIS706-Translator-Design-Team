#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

typedef struct SFieldAccessFoo FieldAccessFoo;
typedef struct SFieldAccessBar FieldAccessBar;

NEW_STRUCT (SFieldAccessFoo, int i;);

 NEW_SIMPLECONST(FieldAccessFoo);
NEW_STRUCT (SFieldAccessBar, int i;FieldAccessFoo* f ;
);

NEW_CONST(FieldAccessBar, 1, ptr, &(ptr->f));

int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 2;
   int i;FieldAccessFoo* f = New_FieldAccessFoo();var_push(&f);
   FieldAccessBar* b = New_FieldAccessBar();var_push(&b);
   f=New_FieldAccessFoo();
   f->i=0;
   i=f->i;
   assert((f->i == 0));
   assert((i == 0));
   b=New_FieldAccessBar();
   b->i=1;
   i=b->i;
   assert((b->i == 1));
   assert((i == 1));
   b->f=f;
   b->f->i=2;
   i=b->f->i;
   assert((b->f->i == 2));
   assert((i == 2));
   b->f->i=3;
   f->i=b->f->i;
   assert((b->f->i == 3));
   assert((f->i == 3));
   b->f->i=4;
   f=b->f;
   assert((f->i == 4));
   f->i=5;
   b->f=f;
   assert((b->f->i == 5));
   b->f->i++;
   assert((b->f->i == 6));


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}
