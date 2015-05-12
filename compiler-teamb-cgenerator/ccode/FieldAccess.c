#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

typedef struct SFieldAccessFoo FieldAccessFoo;
typedef struct SFieldAccessBar FieldAccessBar;

struct SFieldAccessFoo{
    int i;
    var_push(&i);

};

struct SFieldAccessBar{
    int i;
    var_push(&i);
    FieldAccessFoo* f;
    var_push(&f);

};

int main(){
    int i;
    var_push(&i);
    FieldAccessFoo* f;
    var_push(&f);
    FieldAccessBar* b;
    var_push(&b);
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

   return 0;
}
