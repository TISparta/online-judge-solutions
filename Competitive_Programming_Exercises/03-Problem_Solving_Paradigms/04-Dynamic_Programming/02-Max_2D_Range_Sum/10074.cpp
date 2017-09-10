#include <bits/stdc++.h>

using namespace std;

int n, m, ans, area, v[105][105];

int main(){
   while(scanf("%d %d", &n, &m), n | m){
      for(int i = 1; i <= n; i++)
         for(int j = 1; j <= m; j++)
            scanf("%d", &v[i][j]), v[i][j] += v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
      ans = 0;
      for(int i = 1; i <= n; i++)
         for(int j = 1; j <= m; j++)
            for(int ii = i; ii <= n; ii++)
               for(int jj = j; jj <= m; jj++){
                  if((ii - i + 1) * (jj - j + 1) > ans){
                     area = v[ii][jj] - v[ii][j - 1] - v[i - 1][jj] + v[i - 1][j - 1];
                     if(area == 0) ans = (ii - i + 1) * (jj - j + 1);
                  }
               }
      printf("%d\n", ans);
   }
   return(0);
}
