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
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   missingInitFor();
   forFor();
   multipleFor();


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

void* emptyFor(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;

   for(; ; ){


      }

      gc_collect();
      for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}

void* initOnlyFor(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int i;
   for(
   i=0; ; ){


      }

      gc_collect();
      for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}

void* condOnlyFor(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int i;
   i=0;

   for(; (i < 10); ){


      }

      gc_collect();
      for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}

void* incOrDecOnlyFor(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int i;
   i=0;

   for(; ; i++){


      }

      gc_collect();
      for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}

void* missingIncOrDecFor(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int i;
   for(
   i=0; (i < 10); ){


      }

      gc_collect();
      for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}

void* missingCondFor(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int i;
   for(
   i=0; ; i++){


      }

      gc_collect();
      for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}

void* missingInitFor(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int i;
   i=0;

   for(; (i < 10); i++){


      }

      gc_collect();
      assert((i == 10));
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}

void* forFor(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int i;
   for(
   i=0; (i < 10); i++){


      }

      gc_collect();
      assert((i == 10));
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}

void* multipleInitOnlyFor(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int i;int j;int k;
   for(
   i=0, 
   j=0, 
   k=0; ; ){


      }

      gc_collect();
      for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}

void* multipleIncOrDecOnlyFor(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int i;int j;int k;
   i=0;

   j=0;

   k=0;

   for(; ; i++, j++, k++){


      }

      gc_collect();
      for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}

void* multipleFor(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int i;int j;int k;
   for(
   i=0, 
   j=0, 
   k=0; (i < 10); i++, j++, k++){


      }

      gc_collect();
      assert((i == 10));
   assert((j == 10));
   assert((k == 10));
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}
