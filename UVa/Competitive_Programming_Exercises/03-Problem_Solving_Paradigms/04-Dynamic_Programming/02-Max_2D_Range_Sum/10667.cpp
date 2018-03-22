#include <bits/stdc++.h>

using namespace std;

int tc, r1, r2, c1, c2, n, b, ans, area, v[105][105];

int main(){
   scanf("%d", &tc);
   while(tc--){
      memset(v, 0, sizeof v);
      scanf("%d", &n);
      scanf("%d", &b);
      while(b--){
         scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
         for(int i = r1; i <= r2; i++)
            for(int j = c1; j <= c2; j++) v[i][j] = 1;
      }
      for(int i = 1; i <= n; i++)
         for(int j = 1; j <= n; j++)
            v[i][j] += v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
      ans = 0;
      for(int i = 1; i <= n; i++)
         for(int j = 1; j <= n; j++)
            for(int ii = i; ii <= n; ii++)
               for(int jj = j; jj <= n; jj++){
                  if((ii - i + 1) * (jj - j + 1) > ans){
                     area = v[ii][jj] - v[ii][j - 1] - v[i - 1][jj] + v[i - 1][j - 1];
                     if(area == 0) ans = (ii - i + 1) * (jj - j + 1);
                  }
               }
      printf("%d\n", ans);
   }
   return(0);
}
