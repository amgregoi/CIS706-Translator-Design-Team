#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

typedef struct SMergeSort MergeSort;
typedef struct SMergeSortData MergeSortData;
void* msMergeSort(MergeSort* ms, Array* inputArr, int length2);
void* msDoSort(MergeSort* ms, int lowerIndex, int higherIndex);
void* msMerge(MergeSort* ms, int lowerIndex, int middle, int higherIndex);

NEW_STRUCT (SMergeSort,  Array* array ;
;int length2; Array* tempMergArr ;
;);

NEW_CONST(MergeSort, 2, ptr, &(ptr->array), &(ptr->tempMergArr));

NEW_STRUCT (SMergeSortData, int i;);

 NEW_SIMPLECONST(MergeSortData);
int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 3;
   MergeSort* ms = New_MergeSort();var_push(&ms);
    Array* array = NULL;
   ;var_push(&array);
   MergeSortData* data = New_MergeSortData();var_push(&data);
   int i;int size;
   size=1000;

   array=New_Array(size); ;

   ms=New_MergeSort();

   for(
   i=0; (i < size); i++){

      data=New_MergeSortData();

      data->i=(size - i);

      ARRAYGET(array, i)=data;



      }

      gc_collect();
      msMergeSort(ms, array, size);

   for(
   i=0; (i < size); i++){
      assert((((MergeSortData*)ARRAYGET(ms->array, i))->i == (i + 1)));



      }

      gc_collect();
      

   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

void* msMergeSort(MergeSort* ms, Array* inputArr, int length2){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;

   ms->array=inputArr;

   ms->length2=length2;

   ms->tempMergArr=New_Array(ms->length2); ;
   msDoSort(ms, 0, (ms->length2 - 1));
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}

void* msDoSort(MergeSort* ms, int lowerIndex, int higherIndex){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int middle;
   if((lowerIndex < higherIndex)){

      middle=(lowerIndex + ((higherIndex - lowerIndex) / 2));
      msDoSort(ms, lowerIndex, middle);
      msDoSort(ms, (middle + 1), higherIndex);
      msMerge(ms, lowerIndex, middle, higherIndex);



   }for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}

void* msMerge(MergeSort* ms, int lowerIndex, int middle, int higherIndex){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int i;int j;int k;
   for(
   i=lowerIndex; (i <= higherIndex); i++){

      ARRAYGET(ms->tempMergArr, i)=ARRAYGET(ms->array, i);



      }

      gc_collect();
      
   i=lowerIndex;

   j=(middle + 1);

   k=lowerIndex;
   while(((i <= middle) && (j <= higherIndex))){

      if((((MergeSortData*)ARRAYGET(ms->tempMergArr, i))->i <= ((MergeSortData*)ARRAYGET(ms->tempMergArr, j))->i)){

         ARRAYGET(ms->array, k)=ARRAYGET(ms->tempMergArr, i);
         i++;



      }else{

         ARRAYGET(ms->array, k)=ARRAYGET(ms->tempMergArr, j);
         j++;



      }k++;



      }

      gc_collect();
      while((i <= middle)){

      ARRAYGET(ms->array, k)=ARRAYGET(ms->tempMergArr, i);
      k++;
      i++;



      }

      gc_collect();
      for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}
