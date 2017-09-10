#include <bits/stdc++.h>

using namespace std;

int n, m, Q, L, U, l, x, ans;
vector <int> v[500];

int main(){
   for(int i = 0; i <500; i++)
      v[i].resize(500);
   while(scanf("%d %d", &n, &m), n | m){
      for(int i = 0; i < n; i++){
         for(int j = 0; j < m; j++)
            scanf("%d", &v[i][j]);
      }
      scanf("%d", &Q);
      while(Q--){
         scanf("%d %d", &L, &U);
         ans = 0;
         for(int i = 0; i < n; i++){
            l = lower_bound(v[i].begin(), v[i].begin() + m, L) - v[i].begin();
            x = ans;
            while(true){
               if(i + x >= n || l + x >= m || v[i + x][l + x] > U)
                  break;
               ans = max(ans, x + 1);
               x++;
            }
         }
         printf("%d\n", ans);
      }
      putchar('-');
      putchar('\n');
   }
   return(0);
}
