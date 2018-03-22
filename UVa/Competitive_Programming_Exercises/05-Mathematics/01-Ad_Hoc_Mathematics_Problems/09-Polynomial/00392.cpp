#include <bits/stdc++.h>

using namespace std;

const int SIZE = 10;

int coef[SIZE], r;

int main(){
   while(scanf("%d", coef) == 1){
      for(int it = 1; it < 9; it++) scanf("%d", coef + it);
      r = 0;
      for(int it = 0; it < 9; it++){
         if( coef[it] == 0 ) continue;
         if( coef[it] < 0 ){
            if( r ) putchar(' ');
            putchar('-');
         }
         if( r and coef[it] > 0 ){
            putchar(' ');
            putchar('+');
         }
         if( coef[it] != 0 ){
            if( r++ ) putchar(' ');
            if( it == 8 ) printf("%d", abs(coef[it]));
            else if( it == 7 ){
               if( abs(coef[it]) != 1 )
                  printf("%dx", abs(coef[it]));
               else
                  putchar('x');
            }
            else{
               if( abs(coef[it]) != 1 )
                  printf("%dx^%d", abs(coef[it]), 8 - it);
               else
                  printf("x^%d", 8 - it);
            }
         }
      }
      if( r == 0 ) putchar('0');
      putchar('\n');
   }
   return(0);
}
