#include <bits/stdc++.h>

#define SIZE 100010

using namespace std;

int n;
bool is_prime[SIZE];
vector<int> prime, Factors;

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

void primeFactors(int N){
   Factors.clear();
   if( N < 0 ) Factors.push_back( -1 ), N *= -1;
   for(int it = 0; it < prime.size() and prime[it] * prime[it]  <= N and N != 1; it++)
      while( N % prime[it] == 0) N /= prime[it], Factors.push_back( prime[it] );
   if( N != 1 ) Factors.push_back( N );
}

int main(){
   sieve();
   while(scanf("%d", &n), n){
      primeFactors( n );
      printf("%d = ", n );
      for(int it = 0; it < Factors.size(); it++)
         printf( it != Factors.size() - 1 ? "%d x " : "%d\n", Factors[it]);
   }
   return(0);
}
