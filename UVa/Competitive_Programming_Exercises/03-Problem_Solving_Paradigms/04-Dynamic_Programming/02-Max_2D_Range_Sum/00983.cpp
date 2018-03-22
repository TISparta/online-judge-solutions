#include <bits/stdc++.h>

using namespace std;

int tc, n, m, sum, v[1010][1010];
long long total_sum;

int main(){
   while(scanf("%d %d", &n, &m) == 2){
      total_sum = 0;
      if(tc++) putchar('\n');
      for(int i = 1; i <= n; i++)
         for(int j = 1; j <= n; j++) scanf("%d", &v[i][j]), v[i][j] += v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
      for(int i = 1; i <= n - m + 1; i++)
         for(int j = 1; j <= n - m + 1; j++){
            sum = v[i + m - 1][j + m - 1] - v[i + m - 1][j - 1] - v[i - 1][j + m - 1] + v[i - 1][j - 1];
            total_sum += (long long)sum;
            printf("%d\n", sum);
         }
      printf("%lld\n", total_sum);
   }
   return(0);
}
