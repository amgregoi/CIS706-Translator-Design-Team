#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

typedef struct SListClass ListClass;
ListClass* lNewList();
void* lAddElement(ListClass* lc, int value);
void* lRemoveFirstElement(ListClass* lc, int value);

NEW_STRUCT (SListClass,  Array* list ;
;int size;int capacity;);

NEW_CONST(ListClass, 1, ptr, &(ptr->list));

int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 1;
   ListClass* lc = New_ListClass();var_push(&lc);

   lc=lNewList();
   lAddElement(lc, 10);
   lAddElement(lc, 9);
   lAddElement(lc, 8);
   lAddElement(lc, 7);
   lAddElement(lc, 6);
   lAddElement(lc, 5);
   lAddElement(lc, 4);
   lAddElement(lc, 3);
   lAddElement(lc, 2);
   lAddElement(lc, 1);
   lRemoveFirstElement(lc, 7);
   lRemoveFirstElement(lc, 3);


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

ListClass* lNewList(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 1;
   ListClass* listClass = New_ListClass();var_push(&listClass);

   listClass=New_ListClass();

   listClass->capacity=3;

   listClass->list=New_Array(listClass->capacity); length = listClass->list->elemNum;
   for(indexX=0; indexX<length; indexX++)
   {
   	ARRAYGET(listClass->list, indexX) = New_Integer(0);


   }
   gc_collect();
   ;

   listClass->size=0;

   listClass->capacity=3;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return listClass;
}

void* lAddElement(ListClass* lc, int value){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 2;
   int newCapacity; Array* tempArray = NULL;
   ;var_push(&tempArray);
    Array* lcList = NULL;
   ;var_push(&lcList);
   int i;
   lcList=lc->list;

   if((lc->capacity <= lc->size)){

      newCapacity=(lc->capacity * 2);

      tempArray=lc->list;

      lc->list=New_Array(newCapacity); length = lc->list->elemNum;
      for(indexX=0; indexX<length; indexX++)
      {
      	ARRAYGET(lc->list, indexX) = New_Integer(0);


      }
      gc_collect();
      ;

      for(
      i=0; (i < lc->size); i++){

         ARRAYGET(lc->list, i)=ARRAYGET(tempArray, i);



         }

         gc_collect();
         
      lc->capacity=newCapacity;



   }
   ARRAYGET(lc->list, lc->size)=New_Integer(value);
   lc->size++;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}

void* lRemoveFirstElement(ListClass* lc, int value){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int index;int nextIndex;
   index=0;
   while(((((IntElement*)ARRAYGET(lc->list, index))->value != value) && (index < lc->size))){
      index++;



      }

      gc_collect();
      
   if((((IntElement*)ARRAYGET(lc->list, index))->value != value)){
      return ;


   }
   for(
   nextIndex=(index + 1); (nextIndex < lc->size); nextIndex++, index++){

      ARRAYGET(lc->list, index)=ARRAYGET(lc->list, nextIndex);



      }

      gc_collect();
      lc->size--;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}
