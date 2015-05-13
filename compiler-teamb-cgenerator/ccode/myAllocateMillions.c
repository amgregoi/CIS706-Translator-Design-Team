#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

typedef struct SAllocationArray AllocationArray;
typedef struct SAllocationData AllocationData;
AllocationArray* aaNewArray(int size);
void* aaAddElement(AllocationArray* array, AllocationData* data);
AllocationData* aaRemoveElement(AllocationArray* array);

NEW_STRUCT (SAllocationArray,  Array* array ;
;int size;int lastIndex;);

NEW_CONST(AllocationArray, 1, ptr, &(ptr->array));

NEW_STRUCT (SAllocationData, int value;);

 NEW_SIMPLECONST(AllocationData);
int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 2;
   AllocationArray* array = New_AllocationArray();var_push(&array);
   AllocationData* data = New_AllocationData();var_push(&data);
   int size;int i;
   size=1000000;

   array=aaNewArray(size);

   for(
   i=0; (i < size); i++){

      data=New_AllocationData();

      data->value=i;
      aaAddElement(array, data);



      }

      gc_collect();
      
   for(
   i=0; (i < size); i++){

      data=aaRemoveElement(array);



      }

      gc_collect();
      

   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

AllocationArray* aaNewArray(int size){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 1;
   AllocationArray* aArray = New_AllocationArray();var_push(&aArray);

   aArray=New_AllocationArray();

   aArray->array=New_Array(size); ;

   aArray->size=size;

   aArray->lastIndex=0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return aArray;
}

void* aaAddElement(AllocationArray* array, AllocationData* data){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   assert((array->lastIndex < array->size));

   ARRAYGET(array->array, array->lastIndex)=data;
   array->lastIndex++;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}

AllocationData* aaRemoveElement(AllocationArray* array){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 1;
   AllocationData* data = New_AllocationData();var_push(&data);
   assert((array->lastIndex >= 0));
   array->lastIndex--;

   data=ARRAYGET(array->array, array->lastIndex);

   ARRAYGET(array->array, array->lastIndex)=NULL;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return data;
}
