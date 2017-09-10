#include <bits/stdc++.h>

using namespace std;

int M, N, ans;

int main(){
   while(scanf("%d %d", &M, &N), M | N){
      if( M == 1 or N == 1 ) ans = M * N;
      else if( N == 2 or M == 2 ){
         ans = 4 * ( ( N * M ) / 8 );
         if( ( N * M ) % 8 == 2 ) ans += 2;
         else if( ( N * M ) % 8 != 0 ) ans += 4;
      }
      else
         ans = ( M * N + 1 ) / 2 + ( M == 2 or N == 2 );
      printf("%d knights may be placed on a %d row %d column board.\n", ans, M, N);
   }
   return(0);
}
