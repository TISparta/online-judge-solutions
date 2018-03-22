#include <bits/stdc++.h>

using namespace std;

const int SIZE = 105;

int n, mx, x, ct[SIZE];

int main(){
   while(scanf("%d", &n), n){
      mx = 0;
      for(int it = 0; it < n; it++){
         scanf("%d", &x);
         ct[x]++;
         if( x > mx ) mx = x;
      }
      for(int it = 1; it <= mx; it++){
         for(int j = 0; j < ct[it]; j++)
            printf( it == mx and j == ct[it] - 1 ? "%d\n" : "%d ", it);
         ct[it] = 0;
      }
   }
   return(0);
}
