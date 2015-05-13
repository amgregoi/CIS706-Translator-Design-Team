#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

typedef struct SSelectionSortData SelectionSortData;
void* ssSort(Array* array, int length2);
void* ssSwap(SelectionSortData* first, SelectionSortData* second);

NEW_STRUCT (SSelectionSortData, int value;);

 NEW_SIMPLECONST(SelectionSortData);
int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 2;
    Array* array = NULL;
   ;var_push(&array);
   SelectionSortData* data = New_SelectionSortData();var_push(&data);
   int i;int size;
   size=100;

   array=New_Array(size); ;

   for(
   i=0; (i < size); i++){

      data=New_SelectionSortData();

      data->value=(size - i);

      ARRAYGET(array, i)=data;



      }

      gc_collect();
      ssSort(array, size);


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

void* ssSort(Array* array, int length2){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int minindex;int i;int j;
   for(
   j=0; (j < length2); j++){

      minindex=j;

      for(
      i=(j + 1); (i < length2); i++){

         if((((SelectionSortData*)ARRAYGET(array, i))->value < ((SelectionSortData*)ARRAYGET(array, minindex))->value)){

            minindex=i;



         }


         }

         gc_collect();
         
      if((minindex != j)){
         ssSwap(((SelectionSortData*)ARRAYGET(array, j)), ((SelectionSortData*)ARRAYGET(array, minindex)));



      }


      }

      gc_collect();
      for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}

void* ssSwap(SelectionSortData* first, SelectionSortData* second){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int temp;
   temp=first->value;

   first->value=second->value;

   second->value=temp;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}
