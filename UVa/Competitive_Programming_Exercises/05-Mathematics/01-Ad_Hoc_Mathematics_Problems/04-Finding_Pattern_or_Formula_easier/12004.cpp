#include <bits/stdc++.h>

using namespace std;

int tc, n;

int main(){
   scanf("%d", &tc);
   for(int t = 1; t <= tc; t++){
      scanf("%d", &n);
      long long p = (long long)n * (n - 1) / 2;
      if(p % 2 == 0) printf("Case %d: %lld\n", t, p / 2);
      else printf("Case %d: %lld/2\n", t, p);
   }
   return(0);
}
