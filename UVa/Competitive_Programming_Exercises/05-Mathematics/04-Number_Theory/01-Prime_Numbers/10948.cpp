#include <bits/stdc++.h>

#define SIZE 1000000

using namespace std;

bool is_prime[SIZE], found;
vector<int>prime;
int N, a, b;

void sieve(){
   memset(is_prime, true, sizeof is_prime);
   is_prime[0] = is_prime[1] = false;
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
   while(scanf("%d",&N), N){
      found = false;
      for(int it = 0; it < prime.size() and prime[it] < N; it++)
         if( is_prime[ N - prime[it] ] ){
            found = true;
            a = prime[it], b = N - prime[it];
            break;
         }
      if(not found) printf("%d:\nNO WAY!\n",N);
      else printf("%d:\n%d+%d\n",N,a,b);
   }
   return(0);
}
