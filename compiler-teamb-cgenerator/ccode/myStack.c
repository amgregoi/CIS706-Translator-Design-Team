#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

typedef struct SStackElement StackElement;
typedef struct SStackNode StackNode;
typedef struct SStackClass StackClass;
StackClass* sNewStack();
void* sPush(StackClass* sc, StackElement* newElement);
StackElement* sPop(StackClass* sc);

NEW_STRUCT (SStackElement, int i;);

 NEW_SIMPLECONST(StackElement);
NEW_STRUCT (SStackNode, StackElement* element ;
StackNode* next ;
);

NEW_CONST(StackNode, 2, ptr, &(ptr->element), &(ptr->next));

NEW_STRUCT (SStackClass, StackNode* head ;
StackNode* last ;
int size;);

NEW_CONST(StackClass, 2, ptr, &(ptr->head), &(ptr->last));

int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 2;
   StackClass* sc = New_StackClass();var_push(&sc);
   StackElement* e = New_StackElement();var_push(&e);
   int i;
   sc=sNewStack();

   for(
   i=0; (i < 10); i++){

      e=New_StackElement();

      e->i=(i + 1);
      sPush(sc, e);



      }

      gc_collect();
      while((sc->size > 0)){

      e=sPop(sc);



      }

      gc_collect();
      

   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

StackClass* sNewStack(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 1;
   StackClass* sc = New_StackClass();var_push(&sc);

   sc=New_StackClass();

   sc->head=New_StackNode();

   sc->last=sc->head;

   sc->size=0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return sc;
}

void* sPush(StackClass* sc, StackElement* newElement){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 1;
   StackNode* newNode = New_StackNode();var_push(&newNode);

   newNode=New_StackNode();

   newNode->element=newElement;

   newNode->next=sc->last;

   sc->last=newNode;
   sc->size++;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}

StackElement* sPop(StackClass* sc){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 1;
   StackNode* result = New_StackNode();var_push(&result);

   result=sc->last;

   sc->last=sc->last->next;
   sc->size--;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return result->element;
}
