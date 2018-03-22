#include <bits/stdc++.h>

#define INF 1L<<60

using namespace std;

int tc, n, m, k, t;
long long cum_sum[100][100], max_area, min_price, current_price, sum;
vector <int> v[100];

long long sub_matrix_complete(int pi, int pj, int x, int y){
   sum = 0;
   if(pj == 0)
      for(int i = pi; i < pi + y; i++){
         sum += cum_sum[i][pj + x - 1];
         if(sum > k)
            return INF;
      }
   else
      for(int i = pi; i < pi + y; i++){
         sum += cum_sum[i][pj + x - 1] - cum_sum[i][pj - 1];
         if(sum > k)
            return INF;
      }
   return sum;
}


long long sub_matrix(int pi, int pj, int x, int y){
   sum = 0;
   if(pj == 0)
      for(int i = pi; i < pi + y; i++){
         sum += cum_sum[i][pj + x - 1];
         if(sum > min_price || sum > k)
            return INF;
      }
   else
      for(int i = pi; i < pi + y; i++){
         sum += cum_sum[i][pj + x - 1] - cum_sum[i][pj - 1];
         if(sum > min_price || sum > k)
            return INF;
      }
   return sum;
}

int main(){
   for(int i = 0; i < 100; i++)
      v[i].resize(100);
   scanf("%d", &tc);
   while(tc--){
      scanf("%d %d %d", &n, &m, &k);
      for(int i = 0; i < n; i++)
         for(int j = 0; j < m; j++)
            scanf("%d", &v[i][j]);
      memset(cum_sum, 0, sizeof cum_sum);
      for(int i = 0; i < n; i++){
         cum_sum[i][0] = v[i][0];
         for(int j = 1; j < m; j++)
            cum_sum[i][j] = cum_sum[i][j - 1] + v[i][j];
      }
      min_price = max_area = 0;
      for(int i = 0; i < n; i++)
         for(int j = 0; j < m; j++)
            for(int x = 1; x <= m - j; x++)
               for(int y = 1; y <= n - i; y++)
                  if(x * y > max_area){
                     current_price = sub_matrix_complete(i, j, x, y);
                     if(current_price <= k)
                        min_price = current_price, max_area = x * y;
                  }
                  else if(x * y == max_area){
                     current_price = sub_matrix(i, j, x, y);
                     if(current_price < min_price)
                        min_price = current_price, max_area = x * y;
                  }
      printf("Case #%d: %lld %lld\n", ++t, max_area, min_price);
   }
   return(0);
}
