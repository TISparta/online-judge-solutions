#include <bits/stdc++.h>

using namespace std;

const int SIZE = 55;

int tc, n, m, r, v, ct[SIZE];
long long memo[SIZE][SIZE];

long long dp(int i, int j){
   if( j == 0 ) return 1;
   if( i == n + 1 ) return 0;
   if(~memo[i][j]) return memo[i][j];
   long long ans = 0;
   for(int k = 0; k <= min(j, ct[i]); k++)
      ans += dp(i + 1, j - k);
   return memo[i][j] = ans;
}

int main(){
   while(scanf("%d %d", &n, &m), n | m){
      memset(memo, -1, sizeof memo);
      memset(ct, 0, sizeof ct);
      for(int it = 0; it < n; it++){
         scanf("%d", &v);
         ct[v]++;
      }
      printf("Case %d:\n", ++tc);
      while(m--){
         scanf("%d", &r);
         printf("%lld\n", dp(0, r));
      }
   }
   return(0);
}
