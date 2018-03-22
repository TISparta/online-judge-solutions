#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e6 + 10;

int N;
bool is_prime[MAX_N];

void sieve(){
   memset(is_prime, true, sizeof is_prime);
   is_prime[0] = is_prime[1] = false;
   for(long long i = 2; i < MAX_N; i++)
      if( is_prime[i] )
         for(long long j = i * i; j < MAX_N; j += i)
            is_prime[j] = false;
}

int reversed(int num){
   int ret = 0;
   while(num) ret = 10 * ret + num % 10, num /= 10;
   return ret;
}

int main(){
   sieve();
   while( scanf("%d", &N) == 1 ){
      if( not is_prime[N] ) printf("%d is not prime.\n", N);
      else if( is_prime[reversed(N)] and N != reversed(N) ) printf("%d is emirp.\n", N);
      else printf("%d is prime.\n", N);
   }
   return(0);
}
