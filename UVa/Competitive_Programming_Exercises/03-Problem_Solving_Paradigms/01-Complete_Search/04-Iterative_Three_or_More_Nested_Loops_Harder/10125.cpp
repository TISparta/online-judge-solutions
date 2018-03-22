#include <bits/stdc++.h>

using namespace std;

long long n, v[1010], ans, d;
bool ok;

int main(){
   while(scanf("%lld",&n), n){
      ok = false, ans = -1;
      for(int i = 0; i < n; i++) scanf("%lld", &v[i]);
      sort(v, v + n);
      for(int i = 0; i < n; i++)
         for(int j = i + 1; j < n; j++)
            for(int k = j + 1; k < n; k++){
               d = v[i] + v[j] + v[k];
               if(d > ans && d != v[i] && d != v[j] && d != v[k] && binary_search(v, v + n, d))
                  ans = d, ok = true;
            }
      if(ok) printf("%lld\n", ans);
      else printf("no solution\n");
   }
   return(0);
}
