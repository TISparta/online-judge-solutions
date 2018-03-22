#include <bits/stdc++.h>

#define SIZE 10000010

using namespace std;

long long n, ans;
int ct;
bool is_prime[SIZE];
vector<int> prime;

void sieve(){
   memset(is_prime, true, sizeof is_prime);
   is_prime[0] = is_prime[1] = false;
   for(long long it1 = 2; it1 < SIZE; it1++)
      if( is_prime[it1]){
         for(long long it2 = it1 * it1; it2 < SIZE; it2 += it1)
            is_prime[it2] = false;
         prime.push_back(it1);
      }
}

long long LargestPrimeFactor(long long N){
   N = abs( N );
   ct = ans = 0;
   for(int it = 0; it < prime.size() and prime[it] * prime[it] <= N and N != 1; it++)
      if( N % prime[it] == 0 ){
         ans = prime[it];
         ct++;
         while ( N % prime[it] == 0 ) N /= prime[it];
      }
   if( N != 1) ans = N, ct += 1;
   if( ans == 0 or ct == 1) return -1;
   return ans;
}

int main(){
   sieve();
   while(scanf("%lld", &n), n)
      printf("%lld\n", LargestPrimeFactor(n));
   return(0);
}
