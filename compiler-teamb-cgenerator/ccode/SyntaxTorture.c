#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

typedef struct SEmpty Empty;
typedef struct SManyTypes ManyTypes;
int returnInt();
bool returnBoolean(bool b);
Empty* returnEmpty(int i, Empty* e);
int* returnIntArray();
bool* returnBooleanArray(bool* b);
Empty** returnObjectArray(int* i, Empty** e);
void* returnVoid();

struct SEmpty{
};

struct SManyTypes{
    int i;
    var_push(&i);
    bool b;
    var_push(&b);
    Empty* e;
    var_push(&e);
    int* i_array;
    var_push(&i_array);
    bool* b_array;
    var_push(&b_array);
    Empty** e_array;
    var_push(&e_array);

};

 int aa;
 var_push(&aa);

 bool bb;
 var_push(&bb);

 Empty* cc;
 var_push(&cc);

 int* dd;
 var_push(&dd);

 bool* ee;
 var_push(&ee);

 Empty** ff;
 var_push(&ff);

 int g;
 var_push(&g);

int main(){
    int i;
    var_push(&i);
   Array* i_array;
    int j;
    var_push(&j);
    bool b;
    var_push(&b);
   Array* b_array;
    ManyTypes* m;
    var_push(&m);
   Array* m_array;
   i=0;
   j=i;
   b=true;

   if((i <= 0)){
      while(((~(9) <= i) && (i == -(1)))){
         i=(i + i);
      }
      b=false;
      while((true && b)){
         i++;
      }
      i--;

      for(i=0; !((i != 0)); i--, i++, i--){
         i=((unsigned)i >> +(-(1)));
         returnInt();
         returnVoid();
      }

   }
   do{
      i++;
   }while(((+(7) << ~(-(5))) == j));
   m=New_ManyTypes();
   m->b=false;
   i=4;
   m_array=New_Array(i); ;
   m_array[0]=m;
   i_array=New_Array(0); ARRAYSET(i_array, 0) = 0;
   ARRAYSET(i_array, 1) = i;
   ARRAYSET(i_array, 2) = j;
   ARRAYSET(i_array, 3) = 7;
   ;
   j=0;
   m->i=0;
   m_array[i_array[m->i]]=m_array[j];

   for(i=2, i=j; ((j < (+(i) << 4)) && (j == i)); j++, i--){
   }
   b=false;
   m=b ? NULL : m;
   b_array=New_Array(0); ARRAYSET(b_array, 0) = true;
   ;
   m->b_array=b_array;
   b_array=returnBooleanArray(m->b_array);
   m=NULL;
   b_array=New_Array(0); ARRAYSET(b_array, 0) = true;
   ;
   i_array[returnInt()]=i_array[returnIntArray()[2]];

   return 0;
}

int returnInt(){
    int i;
    var_push(&i);
   i=0;
   return i;
}

bool returnBoolean(bool b){
    bool c;
    var_push(&c);
    int i;
    var_push(&i);
   c=true;
   i=0;
   return !(!(((((!(c) && (false || true)) || ((i > 2) && (i >= -(1)))) || ((3 == i) && (+(4) != i))) || ((3 < 5) && (~(1) <= -(+(~(2))))))));
}

Empty* returnEmpty(int i, Empty* e){
    int j;
    var_push(&j);
    Empty* f;
    var_push(&f);
   f=New_Empty();
   return f;
}

int* returnIntArray(){
   Array* i;
   i=New_Array((((unsigned)((1 + (((2 - 3) * 4) / ((5 % 6) << 7))) >> 8) >> 9) + 3)); ;
   return i;
}

bool* returnBooleanArray(bool* b){
   Array* c;
   c=New_Array(0); ARRAYSET(c, 0) = true;
   ARRAYSET(c, 1) = false;
   ARRAYSET(c, 2) = false;
   ;
   return c;
}

Empty** returnObjectArray(int* i, Empty** e){
   return e;
}

void* returnVoid(){
}
