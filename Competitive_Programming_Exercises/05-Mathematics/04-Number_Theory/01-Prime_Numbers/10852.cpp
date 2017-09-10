#include <bits/stdc++.h>

#define SIZE 10000

using namespace std;

bool is_prime[SIZE];
int M, N, _max, pib, ans;
vector<int>prime;

void sieve(){
   memset(is_prime, true, sizeof is_prime);
   for(int it1 = 2; it1 < SIZE; it1++){
      if(is_prime[it1]){
         for(int it2 = it1 * it1; it2 < SIZE; it2 += it1)
            is_prime[it2] = false;
         prime.push_back(it1);
      }
   }

}

int main(){
   sieve();
   scanf("%d",&M);
   while(M--){
      _max = -1;
      scanf("%d",&N);
      for(int it = 0; it < prime.size() and prime[it] < N; it++){
         pib = N % prime[it];
         if( pib > _max) _max = pib, ans = prime[it];
      }
      printf("%d\n", ans);
   }
   return(0);
}
