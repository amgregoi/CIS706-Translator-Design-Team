#include <stdlib.h>
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

void main(){
   missingInitFor();
   forFor();
   multipleFor();

}

void* emptyFor(){

   for(; ; ){
   }

}

void* initOnlyFor(){
   int i;
   for(i=0; ; ){
   }

}

void* condOnlyFor(){
   int i;i=0;

   for(; (i < 10); ){
   }

}

void* incOrDecOnlyFor(){
   int i;i=0;

   for(; ; i++){
   }

}

void* missingIncOrDecFor(){
   int i;
   for(i=0; (i < 10); ){
   }

}

void* missingCondFor(){
   int i;
   for(i=0; ; i++){
   }

}

void* missingInitFor(){
   int i;i=0;

   for(; (i < 10); i++){
   }
   assert((i == 10));

}

void* forFor(){
   int i;
   for(i=0; (i < 10); i++){
   }
   assert((i == 10));

}

void* multipleInitOnlyFor(){
   int i;int j;int k;
   for(i=0, j=0, k=0; ; ){
   }

}

void* multipleIncOrDecOnlyFor(){
   int i;int j;int k;i=0;
   j=0;
   k=0;

   for(; ; i++, j++, k++){
   }

}

void* multipleFor(){
   int i;int j;int k;
   for(i=0, j=0, k=0; (i < 10); i++, j++, k++){
   }
   assert((i == 10));
   assert((j == 10));
   assert((k == 10));

}
