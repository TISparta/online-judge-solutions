#include <bits/stdc++.h>

#define SIZE 100010

using namespace std;

bool is_prime[SIZE], ok;
vector <int> prime, Factor;
int ans;
long long N;

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

void GetFactors(){
   Factor.clear();
   for(int it = 0; it < prime.size() and prime[it] * prime[it] <= N and N != 1; it++)
      if( N % prime[it] == 0 ){
         int ct = 0;
         while( N % prime[it] == 0 ) N /= prime[it], ct++;
         Factor.push_back(ct);
      }
   if( N != 1 ) Factor.push_back( 1 );
}

int gcd(int a, int b){
   return b == 0 ? a : gcd(b, a % b);
}

int main(){
   sieve();
   while(scanf("%lld", &N), N){
      ok = false;
      if( N < 0 ) N *= -1, ok = true;
      GetFactors();
      ans = Factor[0];
      for(int it = 1; it < Factor.size(); it++)
         ans = gcd(ans, Factor[it]);
      if( ok ) while( ans % 2 == 0 ) ans /= 2;
      printf("%d\n", ans);
   }
   return(0);
}
