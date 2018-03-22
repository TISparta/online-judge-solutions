#include <bits/stdc++.h>

using namespace std;

int tc, n, cum_sum[25][25], max_sum;
string s[25];

bool check(int pi, int pj, int x, int y){
   for(int i = pi; i < pi + y; i++)
      if(pj == 0){
         if(cum_sum[i][pj + x - 1] != x)
            return false;
      }
      else{
         if(cum_sum[i][pj + x - 1] - cum_sum[i][pj - 1] != x)
            return false;
      }
   return true;
}

int main(){
   scanf("%d", &tc);
   while(tc--){
      getchar();
      cin >> s[0];
      n = s[0].size();
      for(int i = 1; i < n; i++)
         cin >> s[i];
      memset(cum_sum, 0, sizeof cum_sum);
      for(int i = 0; i < n; i++){
         cum_sum[i][0] = s[i][0] - '0';
         for(int j = 1; j < n; j++)
            cum_sum[i][j] = cum_sum[i][j - 1] + s[i][j] - '0';
      }
      max_sum = 0;
      for(int i = 0; i < n; i++)
         for(int j = 0; j < n; j++)
            for(int x = 1; x <= n - j; x++)
               for(int y = 1; y <= n - i; y++)
                  if(x * y > max_sum && check(i, j, x, y))
                     max_sum = x * y;
      printf("%d\n", max_sum);
      if(tc)
         putchar('\n');
   }
   return(0);
}
