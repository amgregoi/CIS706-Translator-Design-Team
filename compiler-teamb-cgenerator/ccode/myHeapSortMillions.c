#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

typedef struct SHeapSort HeapSort;
typedef struct SHeapSortData HeapSortData;
void* sort(HeapSort* hs, Array* arr, int length2);
void* heapify(HeapSort* hs, Array* arr, int length2);
void* maxheap(HeapSort* hs, Array* arr, int i);
void* swap(Array* arr, int i, int j);

NEW_STRUCT (SHeapSort, int length2;);

 NEW_SIMPLECONST(HeapSort);
NEW_STRUCT (SHeapSortData, int i;);

 NEW_SIMPLECONST(HeapSortData);
int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 3;
   HeapSort* hs = New_HeapSort();var_push(&hs);
    Array* array = NULL;
   ;var_push(&array);
   HeapSortData* data = New_HeapSortData();var_push(&data);
   int size;int i;
   size=1000000;

   array=New_Array(size); ;

   hs=New_HeapSort();

   for(
   i=0; (i < size); i++){

      data=New_HeapSortData();

      data->i=(size - i);

      ARRAYGET(array, i)=data;



      }

      gc_collect();
      sort(hs, array, size);

   for(
   i=0; (i < size); i++){
      assert((((HeapSortData*)ARRAYGET(array, i))->i == (i + 1)));



      }

      gc_collect();
      

   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

void* sort(HeapSort* hs, Array* arr, int length2){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int i;heapify(hs, arr, length2);

   for(
   i=hs->length2; (i > 0); i--){
      swap(arr, 0, i);

      hs->length2=(hs->length2 - 1);
      maxheap(hs, arr, 0);



      }

      gc_collect();
      for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}

void* heapify(HeapSort* hs, Array* arr, int length2){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int i;
   hs->length2=(length2 - 1);

   for(
   i=(hs->length2 / 2); (i >= 0); i--){
      maxheap(hs, arr, i);



      }

      gc_collect();
      for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}

void* maxheap(HeapSort* hs, Array* arr, int i){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int left;int right;int max;
   left=(2 * i);

   right=((2 * i) + 1);

   max=i;

   if(((left <= hs->length2) && (((HeapSortData*)ARRAYGET(arr, left))->i > ((HeapSortData*)ARRAYGET(arr, i))->i))){

      max=left;



   }
   if(((right <= hs->length2) && (((HeapSortData*)ARRAYGET(arr, right))->i > ((HeapSortData*)ARRAYGET(arr, max))->i))){

      max=right;



   }
   if((max != i)){
      swap(arr, i, max);
      maxheap(hs, arr, max);



   }for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}

void* swap(Array* arr, int i, int j){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int tmp;
   tmp=((HeapSortData*)ARRAYGET(arr, i))->i;

   ((HeapSortData*)ARRAYGET(arr, i))->i=((HeapSortData*)ARRAYGET(arr, j))->i;

   ((HeapSortData*)ARRAYGET(arr, j))->i=tmp;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}
