#include <bits/stdc++.h>

using namespace std;

int main(){
   vector <int> dp(1000000);
   int ct, x, y, ans, tmp, l, r;
   long long n;
   for(int i = 1; i < 1000000; i++){
      ct = 1;
      n = i;
      while(n != 1){
         ct++;
         if(n & 1)
            n = 3 * n + 1;
         else
            n /= 2;
         if( n < i )
            ct += dp[n] - 1, n = 1;
      }
      dp[i] = ct;
   }
   while(scanf("%d %d", &x, &y) == 2){
      ans = 0;
      l = min(x, y);
      r = max(x, y);
      for(int i = l; i <= r; i++)
         if(dp[i] > ans)
            ans = dp[i];
      printf("%d %d %d\n", x, y, ans);
   }
   return(0);
}
