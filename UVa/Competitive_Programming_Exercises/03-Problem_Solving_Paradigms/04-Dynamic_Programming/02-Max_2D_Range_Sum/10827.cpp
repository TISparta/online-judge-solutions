#include <bits/stdc++.h>

using namespace std;

int tc, n, ans, v[230][230];

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%d", &n);
      for(int i = n + 1; i <= (n << 1); i++)
         for(int j = n + 1; j <= (n << 1); j++) scanf("%d", &v[i][j]);
      for(int i = (n << 1) + 1; i < 3 * n; i++)
         for(int j = n + 1; j <= (n << 1); j++) v[i][j] = v[i - n][j];
      for(int i = n + 1; i <= (n << 1); i++)
         for(int j = (n << 1) + 1; j < 3 * n; j++) v[i][j] = v[i][j - n];
      for(int i = 1; i <= n; i++)
         for(int j = n + 1; j <= (n << 1); j++) v[i][j] = v[i + n][j];
      for(int i = n + 1; i <= (n << 1); i++)
         for(int j = 1; j <= n; j++) v[i][j] = v[i][j + n];
      for(int i = 1; i <= n; i++)
         for(int j = 1; j <= n; j++) v[i][j] = v[i + n][j + n];
      for(int i = 1; i <= n; i++)
         for(int j = (n << 1) + 1; j < 3 * n; j++) v[i][j] = v[i + n][j - n];
      for(int i = (n << 1) + 1; i < 3 * n; i++)
         for(int j = 1; j <= n; j++) v[i][j] = v[i - n][j + n];
      for(int i = (n << 1) + 1; i < 3 * n; i++)
         for(int j = (n << 1) + 1; j < 3 * n; j++) v[i][j] = v[i - n][j - n];
      for(int i = 1 ; i < 3 * n; i++)
         for(int j = 1; j < 3 * n; j++)
            v[i][j] += v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
      ans = v[1][1];
      for(int i = 1; i < 3 * n; i++)
         for(int j = 1; j < 3 * n; j++)
            for(int ii = i; ii < min(i + n, 3 * n); ii++)
               for(int jj = j; jj < min(j + n, 3 * n); jj++)
                  ans = max(ans, v[ii][jj] - v[ii][j - 1] - v[i - 1][jj] + v[i - 1][j - 1]);
      printf("%d\n", ans);
   }
   return(0);
}
