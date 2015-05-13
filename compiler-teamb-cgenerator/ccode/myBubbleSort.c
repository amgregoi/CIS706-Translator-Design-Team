#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

Array* BubbleSort(Array* inputArray, int arraySize);

int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 1;
    Array* array = NULL;
   ;var_push(&array);
   int size;bool isSorted;
   array=New_Array(16); ARRAYGET(array, 0) = New_Integer(1);
   ARRAYGET(array, 1) = New_Integer(3);
   ARRAYGET(array, 2) = New_Integer(7);
   ARRAYGET(array, 3) = New_Integer(9);
   ARRAYGET(array, 4) = New_Integer(2);
   ARRAYGET(array, 5) = New_Integer(8);
   ARRAYGET(array, 6) = New_Integer(37);
   ARRAYGET(array, 7) = New_Integer(5);
   ARRAYGET(array, 8) = New_Integer(76);
   ARRAYGET(array, 9) = New_Integer(0);
   ARRAYGET(array, 10) = New_Integer(72);
   ARRAYGET(array, 11) = New_Integer(34);
   ARRAYGET(array, 12) = New_Integer(87);
   ARRAYGET(array, 13) = New_Integer(56);
   ARRAYGET(array, 14) = New_Integer(91);
   ARRAYGET(array, 15) = New_Integer(81);
   ;

   size=16;

   array=BubbleSort(array, size);

   isSorted=((((((((((((((((((IntElement*)ARRAYGET(array, 0))->value == 0) && (((IntElement*)ARRAYGET(array, 1))->value == 1)) && (((IntElement*)ARRAYGET(array, 2))->value == 2)) && (((IntElement*)ARRAYGET(array, 3))->value == 3)) && (((IntElement*)ARRAYGET(array, 4))->value == 5)) && (((IntElement*)ARRAYGET(array, 5))->value == 7)) && (((IntElement*)ARRAYGET(array, 6))->value == 8)) && (((IntElement*)ARRAYGET(array, 7))->value == 9)) && (((IntElement*)ARRAYGET(array, 8))->value == 34)) && (((IntElement*)ARRAYGET(array, 9))->value == 37)) && (((IntElement*)ARRAYGET(array, 10))->value == 56)) && (((IntElement*)ARRAYGET(array, 11))->value == 72)) && (((IntElement*)ARRAYGET(array, 12))->value == 76)) && (((IntElement*)ARRAYGET(array, 13))->value == 81)) && (((IntElement*)ARRAYGET(array, 14))->value == 87)) && (((IntElement*)ARRAYGET(array, 15))->value == 91));
   assert(isSorted);


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

Array* BubbleSort(Array* inputArray, int arraySize){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int i;int tempSwap;bool swapMade;
   swapMade=true;
   while(swapMade){

      swapMade=false;

      for(
      i=1; (i < arraySize); i++){

         if((((IntElement*)ARRAYGET(inputArray, i))->value < ((IntElement*)ARRAYGET(inputArray, (i - 1)))->value)){

            swapMade=true;

            tempSwap=ARRAYGET(inputArray, i);

            ARRAYGET(inputArray, i)=ARRAYGET(inputArray, (i - 1));

            ARRAYGET(inputArray, (i - 1))=New_Integer(tempSwap);



         }gc_collect();



         }

         gc_collect();
         


      }

      gc_collect();
      for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return inputArray;
}
