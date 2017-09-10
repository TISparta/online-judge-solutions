#include <bits/stdc++.h>

using namespace std;

int n, ans, v[105][105];

int main(){
   while(scanf("%d", &n) == 1){
      for(int i = 1; i <= n; i++)
         for(int j = 1; j <= n; j++)
            scanf("%d", &v[i][j]), v[i][j] = v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1] + v[i][j];
      ans = v[1][1];
      for(int i = 1; i <= n; i++)
         for(int j = 1; j <= n; j++)
            for(int ii = i; ii <= n; ii++)
               for(int jj = j; jj <= n; jj++)
                  ans = max(ans, v[ii][jj] - v[ii][j - 1] - v[i - 1][jj] + v[i - 1][j - 1]);
      printf("%d\n", ans);
   }
   return(0);
}
