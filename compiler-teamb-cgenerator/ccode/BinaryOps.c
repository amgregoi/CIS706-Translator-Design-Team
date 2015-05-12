#include "../../gc.h"
#include <assert.h>
#include <stdbool.h>

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
int mod(int a, int b);
bool greaterThan(int a, int b);
bool greaterThanOrEqual(int a, int b);
bool equal(int a, int b);
bool lessThan(int a, int b);
bool lessThanOrEqual(int a, int b);
bool notEqual(int a, int b);
bool boolAnd(bool a, bool b);
bool boolOr(bool a, bool b);
int shiftLeft(int i, int j);
int shiftRight(int i, int j);
int unsignedShiftRight(int i, int j);

int main(){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   assert((add(2, 3) == 5));
   assert((add(2, -(3)) == -(1)));
   assert((add(-(2), 3) == 1));
   assert((add(-(2), -(3)) == -(5)));
   assert((subtract(2, 3) == -(1)));
   assert((subtract(2, -(3)) == 5));
   assert((subtract(-(2), 3) == -(5)));
   assert((subtract(-(2), -(3)) == 1));
   assert((multiply(2, 3) == 6));
   assert((multiply(2, -(3)) == -(6)));
   assert((multiply(-(2), 3) == -(6)));
   assert((multiply(-(2), -(3)) == 6));
   assert((divide(2, 3) == 0));
   assert((divide(2, -(3)) == 0));
   assert((divide(-(2), 3) == 0));
   assert((divide(-(2), -(3)) == 0));
   assert((divide(3, 2) == 1));
   assert((divide(3, -(2)) == -(1)));
   assert((divide(-(3), 2) == -(1)));
   assert((divide(-(3), -(2)) == 1));
   assert((mod(2, 3) == 2));
   assert((mod(2, -(3)) == 2));
   assert((mod(-(2), 3) == -(2)));
   assert((mod(-(2), -(3)) == -(2)));
   assert((mod(3, 2) == 1));
   assert((mod(3, -(2)) == 1));
   assert((mod(-(3), 2) == -(1)));
   assert((mod(-(3), -(2)) == -(1)));
   assert(true);
   assert(!(false));
   assert((greaterThan(2, 3) == false));
   assert((greaterThan(3, 2) == true));
   assert((greaterThan(2, 2) == false));
   assert((greaterThanOrEqual(2, 3) == false));
   assert((greaterThanOrEqual(3, 2) == true));
   assert((greaterThanOrEqual(2, 2) == true));
   assert((equal(2, 3) == false));
   assert((equal(3, 2) == false));
   assert((equal(2, 2) == true));
   assert((lessThan(2, 3) == true));
   assert((lessThan(3, 2) == false));
   assert((lessThan(2, 2) == false));
   assert((lessThanOrEqual(2, 3) == true));
   assert((lessThanOrEqual(3, 2) == false));
   assert((lessThanOrEqual(2, 2) == true));
   assert((notEqual(2, 3) == true));
   assert((notEqual(3, 2) == true));
   assert((notEqual(2, 2) == false));
   assert((boolAnd(true, true) == true));
   assert((boolAnd(true, false) == false));
   assert((boolAnd(false, true) == false));
   assert((boolAnd(false, false) == false));
   assert((boolOr(true, true) == true));
   assert((boolOr(true, false) == true));
   assert((boolOr(false, true) == true));
   assert((boolOr(false, false) == false));
   assert((shiftLeft(2, 1) == 4));
   assert((shiftLeft(-(2), 1) == -(4)));
   assert((shiftRight(2, 1) == 1));
   assert((shiftRight(-(2), 1) == -(1)));
   assert((unsignedShiftRight(2, 1) == 1));
   assert((unsignedShiftRight(-(2), 1) == 2147483647));


   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
   	  var_pop();
   }
   gc_dispose();
   return 0;
}

int add(int a, int b){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return (a + b);
}

int subtract(int a, int b){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return (a - b);
}

int multiply(int a, int b){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return (a * b);
}

int divide(int a, int b){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return (a / b);
}

int mod(int a, int b){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return (a % b);
}

bool greaterThan(int a, int b){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return (a > b);
}

bool greaterThanOrEqual(int a, int b){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return (a >= b);
}

bool equal(int a, int b){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return (a == b);
}

bool lessThan(int a, int b){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return (a < b);
}

bool lessThanOrEqual(int a, int b){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return (a <= b);
}

bool notEqual(int a, int b){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return (a != b);
}

bool boolAnd(bool a, bool b){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return (a && b);
}

bool boolOr(bool a, bool b){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return (a || b);
}

int shiftLeft(int i, int j){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return (i << j);
}

int shiftRight(int i, int j){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return (i >> j);
}

int unsignedShiftRight(int i, int j){
   int numOfPush;
   int length;
   int indexX;

   numOfPush = 0;
   for(numOfPush -= 1; numOfPush>= 0; numOfPush--){
      	  var_pop();
      }

      return ((unsigned)i >> j);
}
