#include <bits/stdc++.h>

#define SIZE 100010

using namespace std;

bool is_prime[SIZE];
vector <int> prime;
int tc, N;
long long ans;

void sieve(){
   memset(is_prime, true, sizeof is_prime);
   is_prime[0] = is_prime[1] = false;
   for(long long it1 = 2; it1 < SIZE; it1++)
      if( is_prime[it1] ){
         for(long long it2 = it1 * it1; it2 < SIZE; it2 += it1)
            is_prime[it2] = false;
         prime.push_back(it1);
      }
}

long long solve(int n){
   if( n == 1 ) return 2;
   ans = 0;
   for(int it = 0; it < prime.size() and prime[it] * prime[it] <= n and n != 1; it++)
      if( n % prime[it] == 0 ){
         int p = 1;
         while( n % prime[it] == 0) p *= prime[it], n /= prime[it];
         ans += p;
      }
   if( n != 1 ) ans += n;
   if( ans == N ) ans++;
   return ans;
}

int main(){
   sieve();
   while(scanf("%d",&N), N)
      printf("Case %d: %lld\n", ++tc, solve(N));
   return(0);
}
