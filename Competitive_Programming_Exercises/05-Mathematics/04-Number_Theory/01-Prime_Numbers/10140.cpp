#include <bits/stdc++.h>

#define SIZE 100010

using namespace std;

bool is_prime[SIZE];
vector<int>prime;
unsigned int L, U;

void sieve(){
   memset(is_prime, true, sizeof is_prime);
   is_prime[1] = false;
   for(long long it1 = 2; it1 < SIZE; it1++)
      if(is_prime[it1]){
         for(long long it2 = it1 * it1; it2 < SIZE; it2 += it1)
            is_prime[it2] = false;
         prime.push_back(it1);
      }
}

bool isPrime(unsigned int num){
   if(num < SIZE) return is_prime[num];
   for(int it = 0; it < prime.size(); it++)
      if( num % prime[it] == 0) return false;
   return true;
}

int main(){
   sieve();
   while(~scanf("%u %u",&L, &U)){
      bool comp[SIZE * 10];
      memset(comp, false, sizeof comp);
      if(L==1) L++;
      for(int it1 = 0; it1 < prime.size() and (long long) prime[it1] * prime[it1] <= U; it1++){
         long long it = L % prime[it1] == 0 ? L : L + ( prime[it1] - L % prime[it1] );
         if(isPrime(it)) it <<= 1;
         for(long long it2 = it; it2 <= U; it2 += prime[it1])
            comp[it2-L] = true;
      }
      bool foundA = false, foundB = false;
      unsigned int a, b, A, B, pib, _min = INT_MAX, _max = 0;
      for(unsigned int it = L; it <= U; it++){
         if(comp[it-L]==false){
            if(foundA==false){
               foundA = true;
            }
            else{
               foundB = true;
               if(it - pib < _min){
                  _min = it - pib;
                  a = pib, b = it;
               }
               if(it - pib > _max){
                  _max = it - pib;
                  A = pib, B = it;
               }
            }
            pib = it;
         }
      }
      if(foundA and foundB)
         printf("%u,%u are closest, %u,%u are most distant.\n",a, b, A, B);
      else
         puts("There are no adjacent primes.");
   }
   return(0);
}
