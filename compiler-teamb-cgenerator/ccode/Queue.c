#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

typedef struct SData Data;
typedef struct SLinkedNode LinkedNode;
typedef struct SLinkedList LinkedList;
LinkedList* llNewLinkedList();
bool llIsEmpty(LinkedList* ll);
void* llAddLast(LinkedList* ll, Data* data);
Data* llRemoveFirst(LinkedList* ll);

NEW_STRUCT (SData, int i;);

 NEW_SIMPLECONST(Data);
NEW_STRUCT (SLinkedNode, Data* data ;
LinkedNode* next ;
);

NEW_CONST(LinkedNode, 2, ptr, &(ptr->data), &(ptr->next));

NEW_STRUCT (SLinkedList, LinkedNode* head ;
LinkedNode* last ;
int size;);

NEW_CONST(LinkedList, 2, ptr, &(ptr->head), &(ptr->last));

int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 2;
   LinkedList* ll = New_LinkedList();var_push(&ll);
   Data* d = New_Data();var_push(&d);
   int i;
   ll=llNewLinkedList();

   for(
   i=0; (i < 10); i++){

      d=New_Data();

      d->i=(i + 1);
      llAddLast(ll, d);



      }

      gc_collect();
      while(!(llIsEmpty(ll))){

      d=llRemoveFirst(ll);



      }

      gc_collect();
      

   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

LinkedList* llNewLinkedList(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 1;
   LinkedList* result = New_LinkedList();var_push(&result);

   result=New_LinkedList();

   result->head=New_LinkedNode();

   result->last=result->head;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return result;
}

bool llIsEmpty(LinkedList* ll){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   assert((ll != NULL));
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return (ll->size == 0);
}

void* llAddLast(LinkedList* ll, Data* data){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   assert(((ll != NULL) && (data != NULL)));

   ll->last->next=New_LinkedNode();

   ll->last=ll->last->next;

   ll->last->data=data;
   ll->size++;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}

Data* llRemoveFirst(LinkedList* ll){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 1;
   Data* result = New_Data();var_push(&result);
   int i;
   i=0;
   assert((ll->size > 0));

   result=ll->head->next->data;

   ll->head=ll->head->next;
   ll->size--;

   do{
      i++;
      i++;
      i--;


        }while((i < 10));

      gc_collect();
      for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return result;
}
