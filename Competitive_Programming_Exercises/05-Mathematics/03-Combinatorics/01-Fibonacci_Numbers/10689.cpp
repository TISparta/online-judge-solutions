#include <bits/stdc++.h>

#define MOD 10000

using namespace std;

int ans, tc, a, b, n, m, mod, M[2][2] = {{ 1, 1}, {1, 0}}, FIB[2][2], w, x, y , z;

void multiply_FIB_FIB(){
   w = FIB[0][0] * FIB[0][0] + FIB[0][1] * FIB[1][0];
   x = FIB[0][0] * FIB[0][1] + FIB[0][1] * FIB[1][1];
   y = FIB[1][0] * FIB[0][0] + FIB[1][1] * FIB[1][0];
   z = FIB[1][0] * FIB[0][1] + FIB[1][1] * FIB[1][1];
   FIB[0][0] = w % MOD;
   FIB[0][1] = x % MOD;
   FIB[1][0] = y % MOD;
   FIB[1][1] = z % MOD;
}

void multiply_FIB_M(){
   w = FIB[0][0] * M[0][0] + FIB[0][1] * M[1][0];
   x = FIB[0][0] * M[0][1] + FIB[0][1] * M[1][1];
   y = FIB[1][0] * M[0][0] + FIB[1][1] * M[1][0];
   z = FIB[1][0] * M[0][1] + FIB[1][1] * M[1][1];
   FIB[0][0] = w % MOD;
   FIB[0][1] = x % MOD;
   FIB[1][0] = y % MOD;
   FIB[1][1] = z % MOD;
}

void power(int n){
   if(n == 0 || n == 1)
      return;
   power(n / 2);
   multiply_FIB_FIB();
   if(n & 1)
      multiply_FIB_M();
}

void quick_fib(int n){
   FIB[0][0] = 1 , FIB[0][1] = 1;
   FIB[1][0] = 1 , FIB[1][1] = 0;
   power(n - 1);
}

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%d %d %d %d", &a, &b, &n, &m);
      quick_fib(n);
      mod = pow(10, m);
      if(n > 1)
         ans = (FIB[0][0] * b + FIB[0][1] * a) % mod;
      else if(n ==1)
         ans = b % mod;
      else
         ans = a % mod;
      printf("%d\n", ans);
   }
   return(0);
}
