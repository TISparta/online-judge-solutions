#include <bits/stdc++.h>

using namespace std;

int A, B, xo, yo, d;

void extendedEuclid(int a, int b){
   if( b == 0 ){
      xo = 1, yo = 0, d = a;
      return;
   }
   extendedEuclid(b, a % b);
   int x1 = yo, y1 = xo - ( a / b ) * yo;
   xo = x1, yo = y1;
}

int main(){
   while(~scanf("%d %d", &A, &B)){
      extendedEuclid(A, B);
      printf("%d %d %d\n", xo, yo, d);
   }
   return(0);
}
