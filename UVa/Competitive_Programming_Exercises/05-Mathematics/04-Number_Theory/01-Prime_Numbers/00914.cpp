#include <bits/stdc++.h>

#define SIZE 1000000

using namespace std;

bool is_prime[SIZE];
vector<int>prime;
int tc, L, U;

void sieve(){
   memset(is_prime, true, sizeof is_prime);
   is_prime[0] = is_prime[1] = false;
   for(long long it1 = 2; it1 < SIZE; it1 ++){
      if(is_prime[it1]){
         for(long long it2 = it1 * it1; it2 < SIZE; it2 += it1)
            is_prime[it2] = false;
         prime.push_back(it1);
      }
   }
}

int main(){
   sieve();
   scanf("%d",&tc);
   while(tc--){
      scanf("%d %d",&L, &U);
      int pos = lower_bound(prime.begin(), prime.end(), L) - prime.begin();
      map<int, int> v;
      int idx, _max = -1, ans = -1;
      for(int it = pos + 1; it < prime.size() and prime[it] <= U; it++){
         idx = prime[it] - prime[it - 1];
         v[idx] += 1;
         if(v[idx] == _max) ans = -1;
         if(v[idx] > _max ) _max = v[idx], ans = idx;
      }
      if( ans != -1)
         printf("The jumping champion is %d\n", ans);
      else puts("No jumping champion");
   }
   return(0);
}
