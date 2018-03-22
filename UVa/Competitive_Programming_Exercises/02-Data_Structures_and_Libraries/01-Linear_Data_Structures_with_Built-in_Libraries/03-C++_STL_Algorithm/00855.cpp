#include <bits/stdc++.h>

#define SIZE 50010

using namespace std;

int tc, row, col, f, n, x[SIZE], y[SIZE];

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%d %d %d", &row, &col, &f);
      for(int i = 0; i < f; i++) scanf("%d %d", &x[i], &y[i]);
      n = f / 2;
      if(f&1){
         nth_element(x, x + n, x + f), nth_element(y, y + n, y + f);
         row = x[n], col = y[n];
      }
      else{
         nth_element(x, x + n - 1, x + f), nth_element(y, y + n - 1, y + f);
         row = x[n - 1], col = y[n - 1];
      }
      printf("(Street: %d, Avenue: %d)\n", row, col);
   }
   return(0);
}
