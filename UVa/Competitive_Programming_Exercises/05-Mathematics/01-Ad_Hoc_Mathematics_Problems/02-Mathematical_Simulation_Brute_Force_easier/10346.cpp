#include <bits/stdc++.h>

using namespace std;

int main(){
   int n, k, ans;
   while(scanf("%d %d", &n, &k) == 2){
      ans = n;
      while(n / k)
         ans += n / k, n = n / k + n % k;
      printf("%d\n", ans);
   }
   return(0);
}
