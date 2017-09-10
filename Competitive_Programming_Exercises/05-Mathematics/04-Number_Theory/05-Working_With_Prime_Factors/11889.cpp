#include <bits/stdc++.h>

#define SIZE 3200

using namespace std;

bool is_prime[SIZE];
vector <int> prime;
int tc, A, C, ans;

void sieve(){
   memset(is_prime, true, sizeof is_prime);
   is_prime[0] = is_prime[1] = false;
   for(int it1 = 2; it1 < SIZE; it1++)
      if( is_prime[it1] ){
         for(int it2 = it1 * it1; it2 < SIZE; it2 += it1)
            is_prime[it2] = false;
         prime.push_back(it1);
      }
}

int main(){
   sieve();
   scanf("%d", &tc);
   while(tc--){
      scanf("%d %d", &A, &C);
      if( C % A != 0 ){
         puts("NO SOLUTION");
         continue;
      }
      ans = 1;
      for(int it = 0; it < prime.size() and prime[it] * prime[it] <= C and C != 1; it++)
         if( C % prime[it] == 0 ){
            int ct1 = 0, ct2 = 0, p = 1;
            while( A % prime[it] == 0 ) A /= prime[it], ct1++;
            while( C % prime[it] == 0 ) C /= prime[it], p *= prime[it], ct2++;
            if( ct2 > ct1 ) ans *= p;
         }
      if( C != 1 and A == 1) ans *= C;
      printf("%d\n", ans);
   }
   return(0);
}
