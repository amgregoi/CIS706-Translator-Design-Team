#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

typedef struct SParallelArray ParallelArray;
ParallelArray* paNewArray(int size);
void* paPut(ParallelArray* array, int index, int integer, bool bool2);
int paGetInt(ParallelArray* array, int index);
bool paGetBool(ParallelArray* array, int index);

NEW_STRUCT (SParallelArray,  Array* integers ;
; Array* bools ;
;int size;);

NEW_CONST(ParallelArray, 2, ptr, &(ptr->integers), &(ptr->bools));

int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 1;
   ParallelArray* array = New_ParallelArray();var_push(&array);
   int i;int result;bool value;
   array=paNewArray(20);

   value=true;

   for(
   i=0; (i < 20); i++){
      paPut(array, i, (i * 2), value);

      value=!(value);



      }

      gc_collect();
      
   for(
   i=0; (i < 20); i++){

      result=paGetInt(array, i);

      value=paGetBool(array, i);



      }

      gc_collect();
      

   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

ParallelArray* paNewArray(int size){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 1;
   ParallelArray* newArray = New_ParallelArray();var_push(&newArray);

   newArray=New_ParallelArray();

   newArray->size=size;

   newArray->integers=New_Array(size); length = newArray->integers->elemNum;
   for(indexX=0; indexX<length; indexX++)
   {
   	ARRAYGET(newArray->integers, indexX) = New_Integer(0);


   }
   gc_collect();
   ;

   newArray->bools=New_Array(size); length = newArray->bools->elemNum;
   for(indexX=0; indexX<length; indexX++)
   {
   	ARRAYGET(newArray->bools, indexX) = New_Boolean(false);


   }
   gc_collect();
   ;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return newArray;
}

void* paPut(ParallelArray* array, int index, int integer, bool bool2){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 2;
    Array* x = NULL;
   ;var_push(&x);
    Array* y = NULL;
   ;var_push(&y);
   assert((index < array->size));

   x=array->integers;

   y=array->bools;

   ARRAYGET(x, index)=New_Integer(integer);

   ARRAYGET(y, index)=New_Boolean(bool2);
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}

int paGetInt(ParallelArray* array, int index){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   assert((index < array->size));
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return ((IntElement*)ARRAYGET(array->integers, index))->value;
}

bool paGetBool(ParallelArray* array, int index){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   assert((index < array->size));
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return ((BoolElement*)ARRAYGET(array->bools, index))->value;
}
