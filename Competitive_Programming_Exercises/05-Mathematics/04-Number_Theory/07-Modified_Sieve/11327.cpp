#include <bits/stdc++.h>

#define SIZE 200010

using namespace std;

int EulerPhi[SIZE], num, den;
long long dp[SIZE], k, ct;

void sieve(){
   for(int it = 2; it < SIZE; it++) EulerPhi[it] = it;
   dp[1] = 2;
   for(int it1 = 2; it1 < SIZE; it1++){
      if( EulerPhi[it1] == it1 )
         for(int it2 = it1; it2 < SIZE; it2 += it1)
            EulerPhi[it2] -= EulerPhi[it2] / it1;
      dp[it1] = dp[it1 - 1] + EulerPhi[it1];
   }
}

int gcd(int a, int b){
   return b == 0 ? a : gcd(b, a % b);
}

int main(){
   sieve();
   while(scanf("%lld", &k), k){
      den = lower_bound(dp, dp + SIZE, k) - dp;
      ct = dp[den -1];
      for(num = 0; num <= den and ct != k; num++)
         if( gcd(num, den) == 1 ) ct++;
      printf("%d/%d\n", num - 1, den);
   }
   return(0);
}
