#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

typedef struct SEmpty Empty;
typedef struct SManyTypes ManyTypes;
int returnInt();
bool returnBoolean(bool b);
Empty* returnEmpty(int i, Empty* e);
Array* returnIntArray();
Array* returnBooleanArray(Array* b);
Array* returnObjectArray(Array* i, Array* e);
void* returnVoid();

NEW_STRUCT (SEmpty, );

 NEW_SIMPLECONST(Empty);
NEW_STRUCT (SManyTypes, int i;bool b;Empty* e ;
 Array* i_array ;
; Array* b_array ;
; Array* e_array ;
;);

NEW_CONST(ManyTypes, 4, ptr, &(ptr->e), &(ptr->i_array), &(ptr->b_array), &(ptr->e_array));

int aa;
bool bb;
Empty* cc = NULL;

 Array* dd = NULL;
;
 Array* ee = NULL;
;
 Array* ff = NULL;
;
int g;
int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 4;
   int i; Array* i_array = NULL;
   ;var_push(&i_array);
   int j;bool b; Array* b_array = NULL;
   ;var_push(&b_array);
   ManyTypes* m = New_ManyTypes();var_push(&m);
    Array* m_array = NULL;
   ;var_push(&m_array);
   i=0;
   j=i;
   b=true;

   if((i <= 0)){
      while(((~(9) <= i) && (i == -(1)))){
         i=(i + i);

         gc_mark();
         gc_sweep();
         }

         print_gc();gc_collect();
         b=false;
      while((true && b)){
         i++;

         gc_mark();
         gc_sweep();
         }

         print_gc();gc_collect();
         i--;

      for(i=0; !((i != 0)); i--, i++, i--){
         i=((unsigned)i >> +(-(1)));
         returnInt();
         returnVoid();

         gc_mark();
         gc_sweep();
         }

         print_gc();gc_collect();
         
      gc_mark();
      gc_sweep();
   }print_gc();gc_collect();

   do{
      i++;

      gc_mark();
      gc_sweep();}while(((+(7) << ~(-(5))) == j));

      print_gc();gc_collect();
      m=New_ManyTypes();
   m->b=false;
   i=4;
   m_array=New_Array(i); ;
   ARRAYGET(m_array, 0)=m;
   i_array=New_Array(0); ARRAYGET(i_array, 0) = New_Integer(0);
   ARRAYGET(i_array, 1) = New_Integer(i);
   ARRAYGET(i_array, 2) = New_Integer(j);
   ARRAYGET(i_array, 3) = New_Integer(7);
   ;
   j=0;
   m->i=0;
   ARRAYGET(m_array, ((IntElement*)ARRAYGET(i_array, m->i))->value)=ARRAYGET(m_array, j);

   for(i=2, i=j; ((j < (+(i) << 4)) && (j == i)); j++, i--){
      gc_mark();
      gc_sweep();
      }

      print_gc();gc_collect();
      b=false;
   m=b ? NULL : m;
   b_array=New_Array(0); ARRAYGET(b_array, 0) = New_Boolean(true);
   ;
   m->b_array=b_array;
   b_array=returnBooleanArray(m->b_array);
   m=NULL;
   b_array=New_Array(0); ARRAYGET(b_array, 0) = New_Boolean(true);
   ;
   ARRAYGET(i_array, returnInt())=ARRAYGET(i_array, ((IntElement*)ARRAYGET(returnIntArray(), 2))->value);


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

int returnInt(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   int i;i=0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return i;
}

bool returnBoolean(bool b){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   bool c;int i;c=true;
   i=0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return !(!(((((!(c) && (false || true)) || ((i > 2) && (i >= -(1)))) || ((3 == i) && (+(4) != i))) || ((3 < 5) && (~(1) <= -(+(~(2))))))));
}

Empty* returnEmpty(int i, Empty* e){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 1;
   int j;Empty* f = New_Empty();var_push(&f);
   f=New_Empty();
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return f;
}

Array* returnIntArray(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 1;
    Array* i = NULL;
   ;var_push(&i);
   i=New_Array((((unsigned)((1 + (((2 - 3) * 4) / ((5 % 6) << 7))) >> 8) >> 9) + 3)); length = i->elemNum;
   for(indexX=0; indexX<length; indexX++)
   {
   	ARRAYGET(i, indexX) = New_Integer(0);
   	gc_mark();
   	gc_sweep();
   }
   print_gc();gc_collect();
   ;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return i;
}

Array* returnBooleanArray(Array* b){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 1;
    Array* c = NULL;
   ;var_push(&c);
   c=New_Array(0); ARRAYGET(c, 0) = New_Boolean(true);
   ARRAYGET(c, 1) = New_Boolean(false);
   ARRAYGET(c, 2) = New_Boolean(false);
   ;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return c;
}

Array* returnObjectArray(Array* i, Array* e){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return e;
}

void* returnVoid(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      
}
