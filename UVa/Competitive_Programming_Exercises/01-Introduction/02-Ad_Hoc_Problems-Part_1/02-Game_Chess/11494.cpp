#include <bits/stdc++.h>

using namespace std;

int X1, Y1, X2, Y2;

int main(){
   while(scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2), X1 | Y1 | X2 | Y2 ){
      if( X1 == X2 and Y1 == Y2 )
         puts("0");
      else if( X1 == X2 or Y1 == Y2 or abs(X1 - X2) == abs(Y1 - Y2) )
         puts("1");
      else
         puts("2");
   }
   return(0);
}
