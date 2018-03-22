#include <bits/stdc++.h>

#define SIZE 1000010

using namespace std;

int Mobius[SIZE], M[SIZE], N;
bool is_prime[SIZE];

void sieve(){
   memset(is_prime, true, sizeof is_prime);
   fill(Mobius, Mobius + SIZE, 1);
   is_prime[0] = is_prime[1] = false;
   M[1] = 1;
   for(long long it1 = 2; it1 < SIZE; it1++){
      if( is_prime[it1] ){
         for(long long it2 = it1 + it1; it2 < SIZE; it2 += it1){
            is_prime[it2] = false;
            Mobius[it2] *= -1;
            if( it2 % ( it1 * it1 ) == 0 ) Mobius[it2] = 0;
         }
         Mobius[it1] = -1;
      }
      M[it1] = M[it1 - 1] + Mobius[it1];
   }
}

int main(){
   sieve();
   while(scanf("%d", &N), N)
      printf("%8d%8d%8d\n", N, Mobius[N], M[N]);
   return(0);
}
