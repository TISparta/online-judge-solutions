#include <bits/stdc++.h>

#define SIZE 2000010

using namespace std;

int EulerPhi[SIZE], depthPhi[SIZE], dp[SIZE], tc, m, n;

void sieve(){
   for(int it = 2; it < SIZE; it++) EulerPhi[it] = it;
   for(int it1 = 2; it1 < SIZE; it1++)
      if( EulerPhi[it1] == it1 )
         for(int it2 = it1; it2 < SIZE; it2 += it1)
            EulerPhi[it2] -= EulerPhi[it2] / it1;
}

void fillDepth(){
   for(int it = 2; it < SIZE; it++){
      int ct = 1, num = it;
      while( EulerPhi[num] != 1 ){
         num = EulerPhi[num];
         if( num < it ){
            ct += depthPhi[num];
            break;
         }
         ct++;
      }
      depthPhi[it] = ct;
      dp[it] = dp[it - 1] + depthPhi[it];
   }
}

int main(){
   sieve();
   fillDepth();
   scanf("%d", &tc);
   while(tc--){
      scanf("%d %d", &m, &n);
      printf("%d\n", dp[n] - dp[m - 1]);
   }
   return(0);
}
