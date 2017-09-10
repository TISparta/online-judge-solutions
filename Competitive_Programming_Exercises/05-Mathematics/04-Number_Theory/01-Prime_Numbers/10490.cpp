#include <bits/stdc++.h>

#define SIZE 100010

using namespace std;

int n;
long long sd, num;
bool is_prime[SIZE];
vector<int>prime;

void sieve(){
   memset(is_prime, true, sizeof is_prime);
   for(long long it1 = 2; it1 < SIZE; it1++){
      if(is_prime[it1]){
         for(long long it2 = it1 * it1; it2 < SIZE; it2 += it1)
            is_prime[it2] = false;
         prime.push_back(it1);
      }
   }
}

int main(){
   sieve();
   while(scanf("%d",&n), n){
      sd = (1LL<<n) - 1;
      num = (1LL<<n) - 1;
      for(int it = 0; it < prime.size(); it++){
         if( prime[it] > num) break;
         if( num % prime[it] == 0){
            long long p = prime[it];
            while( num % prime[it] == 0) p *= prime[it], num /= prime[it];
            sd *= ( p - 1 ) / ( prime[it] - 1 );
         }
      }
      if( num != 1 ) sd *= ( num * num - 1 ) / ( num - 1 );
      num =  ( 1LL<<(n - 1) )* ( (1LL<<n) - 1 );
      sd -= num;
      if(num==sd) printf("Perfect: %lld!\n", num);
      else if(is_prime[n]) puts("Given number is prime. But, NO perfect number is available.");
      else puts("Given number is NOT prime! NO perfect number is available.");
   }
   return(0);
}
