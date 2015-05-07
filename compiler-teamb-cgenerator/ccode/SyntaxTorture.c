#include <stdlib.h>
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
   bool b;
   Empty* e;
   int* i_array;
   bool* b_array;
   Empty** e_array;

};

int aa;

bool bb;

Empty* cc;

int* dd;

bool* ee;

Empty** ff;

int g;

int main(){
   int i;
   int* i_array;
   int j;
   bool b;
   bool* b_array;
   ManyTypes* m;
   ManyTypes** m_array;
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
   m=malloc(sizeof(ManyTypes));
   m->b=false;
   i=4;
   m_array=malloc(sizeof(ManyTypes*)*i);
   m_array[0]=m;
   i_array=(int[4]){0, i, j, 7};
   j=0;
   m->i=0;
   m_array[i_array[m->i]]=m_array[j];

   for(i=2, i=j; ((j < (+(i) << 4)) && (j == i)); j++, i--){
   }
   b=false;
   m=b ? NULL : m;
   b_array=(bool[1]){true};
   m->b_array=b_array;
   b_array=returnBooleanArray(m->b_array);
   m=NULL;
   b_array=(bool[1]){true};
   i_array[returnInt()]=i_array[returnIntArray()[2]];

   return 0;
}

int returnInt(){
   int i;
   i=0;
   return i;
}

bool returnBoolean(bool b){
   bool c;
   int i;
   c=true;
   i=0;
   return !(!(((((!(c) && (false || true)) || ((i > 2) && (i >= -(1)))) || ((3 == i) && (+(4) != i))) || ((3 < 5) && (~(1) <= -(+(~(2))))))));
}

Empty* returnEmpty(int i, Empty* e){
   int j;
   Empty* f;
   f=malloc(sizeof(Empty));
   return f;
}

int* returnIntArray(){
   int* i;
   i=malloc(sizeof(int)*(((unsigned)((1 + (((2 - 3) * 4) / ((5 % 6) << 7))) >> 8) >> 9) + 3));
   return i;
}

bool* returnBooleanArray(bool* b){
   bool* c;
   c=(bool[3]){true, false, false};
   return c;
}

Empty** returnObjectArray(int* i, Empty** e){
   return e;
}

void* returnVoid(){
}
