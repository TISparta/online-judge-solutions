#include <bits/stdc++.h>

using namespace std;

int a[10001][10];

int main(){
   int c, n;
   scanf("%d", &c);
   for(int i = 1; i < 10001; i++){
      n = i;
      while(n)
         a[i][n % 10]++, n /= 10;
      for(int j = 0; j < 10; j++)
         a[i][j] += a[i - 1][j];
   }
   while(c--){
      scanf("%d", &n);
      for(int j = 0; j < 10; j++){
         printf("%d", a[n][j]);
         if(j != 9)
            putchar(' ');
      }
      putchar('\n');
   }
   return(0);
}
