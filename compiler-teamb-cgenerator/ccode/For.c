#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

void* emptyFor();
void* initOnlyFor();
void* condOnlyFor();
void* incOrDecOnlyFor();
void* missingIncOrDecFor();
void* missingCondFor();
void* missingInitFor();
void* forFor();
void* multipleInitOnlyFor();
void* multipleIncOrDecOnlyFor();
void* multipleFor();

int main(){
   missingInitFor();
   forFor();
   multipleFor();

   return 0;
}

void* emptyFor(){

   for(; ; ){
   }

}

void* initOnlyFor(){
    int i;
    var_push(&i);

   for(i=0; ; ){
   }

}

void* condOnlyFor(){
    int i;
    var_push(&i);
   i=0;

   for(; (i < 10); ){
   }

}

void* incOrDecOnlyFor(){
    int i;
    var_push(&i);
   i=0;

   for(; ; i++){
   }

}

void* missingIncOrDecFor(){
    int i;
    var_push(&i);

   for(i=0; (i < 10); ){
   }

}

void* missingCondFor(){
    int i;
    var_push(&i);

   for(i=0; ; i++){
   }

}

void* missingInitFor(){
    int i;
    var_push(&i);
   i=0;

   for(; (i < 10); i++){
   }
   assert((i == 10));

}

void* forFor(){
    int i;
    var_push(&i);

   for(i=0; (i < 10); i++){
   }
   assert((i == 10));

}

void* multipleInitOnlyFor(){
    int i;
    var_push(&i);
    int j;
    var_push(&j);
    int k;
    var_push(&k);

   for(i=0, j=0, k=0; ; ){
   }

}

void* multipleIncOrDecOnlyFor(){
    int i;
    var_push(&i);
    int j;
    var_push(&j);
    int k;
    var_push(&k);
   i=0;
   j=0;
   k=0;

   for(; ; i++, j++, k++){
   }

}

void* multipleFor(){
    int i;
    var_push(&i);
    int j;
    var_push(&j);
    int k;
    var_push(&k);

   for(i=0, j=0, k=0; (i < 10); i++, j++, k++){
   }
   assert((i == 10));
   assert((j == 10));
   assert((k == 10));

}
