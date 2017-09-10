#include <bits/stdc++.h>

#define SIZE 1000010

using namespace std;

long long n;
bool is_prime[SIZE];
vector<int> prime;
vector<long long> Factors;

void sieve(){
   memset(is_prime, true, sizeof is_prime);
   is_prime[0] = is_prime[1] = false;
   for(long long it1 = 2; it1 < SIZE; it1++)
      if(is_prime[it1]){
         for(long long it2 = it1 * it1; it2 < SIZE; it2 += it1)
            is_prime[it2] = false;
         prime.push_back(it1);
      }
}

void primeFactors(long long N){
   Factors.clear();
   for(int it = 0; it < prime.size() and prime[it] * prime[it]  <= N and N != 1; it++)
      while( N % prime[it] == 0) N /= prime[it], Factors.push_back( prime[it] );
   if( N != 1 ) Factors.push_back( N );
}

int main(){
   sieve();
   while(scanf("%lld", &n), n > 0){
      primeFactors( n );
      for(int it = 0; it < Factors.size(); it++)
         printf( "    %lld\n", Factors[it]);
      puts("");
   }
   return(0);
}
