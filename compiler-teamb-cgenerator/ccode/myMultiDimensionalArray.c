#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

typedef struct SArrayData ArrayData;
typedef struct SMultiArray MultiArray;
MultiArray* ma2DArray(int rows, int columns);
void* maPut(MultiArray* array, int x, int y, ArrayData* data);
ArrayData* maGet(MultiArray* array, int x, int y);

NEW_STRUCT (SArrayData, int value;);

 NEW_SIMPLECONST(ArrayData);
NEW_STRUCT (SMultiArray,  Array* array ;
;int columns;);

NEW_CONST(MultiArray, 1, ptr, &(ptr->array));

int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 2;
   MultiArray* array = New_MultiArray();var_push(&array);
   ArrayData* data = New_ArrayData();var_push(&data);
   int i;int j;
   array=ma2DArray(10, 10);

   for(
   i=0; (i < 10); i++){

      for(
      j=0; (j < 10); j++){

         data=New_ArrayData();

         data->value=(i * j);
         maPut(array, i, j, data);



         }

         gc_collect();
         


      }

      gc_collect();
      
   for(
   i=9; (i >= 0); i--){

      for(
      j=9; (j >= 0); j--){
         maGet(array, i, j);



         }

         gc_collect();
         


      }

      gc_collect();
      

   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

MultiArray* ma2DArray(int rows, int columns){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 1;
   MultiArray* newArray = New_MultiArray();var_push(&newArray);

   newArray=New_MultiArray();

   newArray->columns=columns;

   newArray->array=New_Array((rows * columns)); ;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return newArray;
}

void* maPut(MultiArray* array, int x, int y, ArrayData* data){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int index;
   index=((y * array->columns) + x);

   ARRAYGET(array->array, index)=data;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}

ArrayData* maGet(MultiArray* array, int x, int y){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int index;
   index=((y * array->columns) + x);
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return ((ArrayData*)ARRAYGET(array->array, index));
}
