#include <bits/stdc++.h>

using namespace std;

int tc, A, B, C;
long long v[25][25][25], cs[25][25][25], ans, sum;

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%d %d %d", &A, &B, &C);
      for(int i = 1; i <= A; i++)
         for(int j = 1; j <= B; j++)
            for(int k = 1; k <= C; k++)
               scanf("%lld", &v[i][j][k]), cs[i][j][k] = cs[i][j][k - 1] + cs[i][j - 1][k] - cs[i][j - 1][k - 1] + v[i][j][k];
      ans = v[1][1][1];
      for(int i = 1; i <= A; i++)
         for(int j = 1; j <= B; j++)
            for(int k = 1; k <= C; k++)
               for(int rz = 0; rz <= C - k; rz++)
                  for(int ry = 0; ry <= B - j; ry++)
                     for(int rx = 0; rx <= A - i; rx++){
                        sum = 0;
                        for(int x = i; x <= i + rx; x++)
                           sum += cs[x][j + ry][k + rz] - cs[x][j + ry][k - 1] - cs[x][j - 1][k + rz] + cs[x][j - 1][k - 1];
                        ans = max(ans, sum);
                     }
      printf("%lld\n", ans);
      if(tc) putchar('\n');
   }
   return(0);
}
