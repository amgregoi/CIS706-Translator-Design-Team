#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

typedef struct SDLList DLList;
typedef struct SDLNode DLNode;
typedef struct SDLElement DLElement;
DLList* dlNewList();
void* dlAddElement(DLList* dlList, DLElement* element);
void* dlInsertAt(DLList* dlList, int Index, DLElement* newElement);
DLElement* dlGetAt(DLList* dlList, int Index);
DLElement* dlRemoveAt(DLList* dlList, int Index);

NEW_STRUCT (SDLList, DLNode* head ;
DLNode* tail ;
int size;);

NEW_CONST(DLList, 2, ptr, &(ptr->head), &(ptr->tail));

NEW_STRUCT (SDLNode, DLNode* next ;
DLNode* previous ;
DLElement* element ;
);

NEW_CONST(DLNode, 3, ptr, &(ptr->next), &(ptr->previous), &(ptr->element));

NEW_STRUCT (SDLElement, int value;);

 NEW_SIMPLECONST(DLElement);
int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 2;
   DLList* dlList = New_DLList();var_push(&dlList);
   DLElement* element = New_DLElement();var_push(&element);
   int i;
   dlList=dlNewList();

   for(
   i=0; (i < 10); i++){

      element=New_DLElement();

      element->value=(i + 1);
      dlAddElement(dlList, element);



      }

      gc_collect();
      
   for(
   i=0; (i < 5); i++){

      element=New_DLElement();

      element->value=(dlGetAt(dlList, 5)->value * 2);
      dlInsertAt(dlList, 5, element);



      }

      gc_collect();
      
   i=dlList->size;
   while((dlList->size > 0)){

      element=dlRemoveAt(dlList, 0);



      }

      gc_collect();
      

   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

DLList* dlNewList(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 1;
   DLList* newList = New_DLList();var_push(&newList);

   newList=New_DLList();

   newList->head=New_DLNode();

   newList->tail=New_DLNode();

   newList->head->next=newList->tail;

   newList->head->previous=NULL;

   newList->tail->next=NULL;

   newList->tail->previous=newList->head;

   newList->size=0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return newList;
}

void* dlAddElement(DLList* dlList, DLElement* element){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 1;
   DLNode* newNode = New_DLNode();var_push(&newNode);

   newNode=New_DLNode();

   newNode->element=element;

   newNode->previous=dlList->tail->previous;

   newNode->next=dlList->tail;

   dlList->tail->previous->next=newNode;

   dlList->tail->previous=newNode;
   dlList->size++;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}

void* dlInsertAt(DLList* dlList, int Index, DLElement* newElement){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 2;
   DLNode* indexedNode = New_DLNode();var_push(&indexedNode);
   DLNode* newNode = New_DLNode();var_push(&newNode);
   int i;assert((Index < dlList->size));

   for(
   i=0, 
   indexedNode=dlList->head->next; (i < Index); i++){

      indexedNode=indexedNode->next;



      }

      gc_collect();
      
   newNode=New_DLNode();

   newNode->element=newElement;

   newNode->previous=indexedNode->previous;

   newNode->next=indexedNode;

   indexedNode->previous->next=newNode;

   indexedNode->previous=newNode;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}

DLElement* dlGetAt(DLList* dlList, int Index){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 1;
   DLNode* indexedNode = New_DLNode();var_push(&indexedNode);
   int i;assert((Index < dlList->size));

   for(
   i=0, 
   indexedNode=dlList->head->next; (i < Index); i++){

      indexedNode=indexedNode->next;



      }

      gc_collect();
      for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return indexedNode->element;
}

DLElement* dlRemoveAt(DLList* dlList, int Index){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 2;
   DLNode* indexedNode = New_DLNode();var_push(&indexedNode);
   DLElement* element = New_DLElement();var_push(&element);
   int i;assert((Index < dlList->size));

   for(
   i=0, 
   indexedNode=dlList->head->next; (i < Index); i++){

      indexedNode=indexedNode->next;



      }

      gc_collect();
      
   element=indexedNode->element;

   indexedNode->previous->next=indexedNode->next;

   if((indexedNode->next != NULL)){

      indexedNode->next->previous=indexedNode->previous;



   }dlList->size--;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return element;
}
