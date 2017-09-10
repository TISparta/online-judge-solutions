#include <bits/stdc++.h>

using namespace std;

int main(){
   int c, n, k, p, ans, t = 0;
   scanf("%d", &c);
   while(c--){
      scanf("%d %d %d", &n, &k, &p);
      ans = k + p % n;
      if(ans > n)
         ans %= n;
      printf("Case %d: %d\n", ++t, ans);
   }
   return(0);
}
