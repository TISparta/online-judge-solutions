#include <bits/stdc++.h>

using namespace std;

#define DIGIT 215

int n, tmp;
int fib[1003][DIGIT + 1];

int main(){
   fib[1][DIGIT] = 1;
   for(int i = 2; i <= 1002; i++){
      for(int j = DIGIT; j > 0; j--){
         fib[i][j] += fib[i - 1][j] + fib[i - 2][j];
         if(fib[i][j] > 9)
            fib[i][j - 1] += 1, fib[i][j] %= 10;
      }
   }
   while(scanf("%d",&n) == 1){
      n += 2;
      for(int i = 0; i <= DIGIT; i++){
         if(fib[n][i] != 0){
            while(i <= DIGIT)
               printf("%d", fib[n][i++]);
         }
      }
      putchar('\n');
   }
   return(0);
}
