#include <bits/stdc++.h>

using namespace std;

int tc, n, MOD;
long long k, mx;

long long maximum(){
   mx = k;
   set <int> vis;
   while( vis.find(k) == vis.end() ){
      vis.insert(k);
      k = k * k;
      while( k >= MOD ) k /= 10;
      mx = max(mx, k);
   }
   return mx;
}

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%d %lld", &n, &k);
      MOD = exp10(n);
      printf("%lld\n", maximum());
   }
   return(0);
}
