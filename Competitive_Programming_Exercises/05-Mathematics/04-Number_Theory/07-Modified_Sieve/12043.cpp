#include <bits/stdc++.h>

#define SIZE 100010

using namespace std;

int numDiv[SIZE], sumDiv[SIZE], tc, a, b, k, ans1;
long long ans2;

void sieve(){
   for(int it1 = 1; it1 < SIZE; it1++)
      for(int it2 = it1; it2 < SIZE; it2 += it1)
         numDiv[it2]++, sumDiv[it2] += it1;
}

void solve(){
   ans1 = 0, ans2 = 0;
   int ac = ( a % k == 0 ) ? 0 : (k - a % k);
   for(int it = a + ac; it <= b; it += k)
      ans1 += numDiv[it], ans2 += sumDiv[it];
}

int main(){
   sieve();
   scanf("%d", &tc);
   while(tc--){
      scanf("%d %d %d", &a, &b, &k);
      solve();
      printf("%d %lld\n", ans1, ans2);
   }
   return(0);
}
