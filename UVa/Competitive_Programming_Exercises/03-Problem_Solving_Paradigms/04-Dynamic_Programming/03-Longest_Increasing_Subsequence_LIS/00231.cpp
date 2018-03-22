#include <bits/stdc++.h>

using namespace std;

int tc, n, ans, v[1010], lds[1010];

int main(){
   while(scanf("%d", &v[0]), v[0] != -1){
      if(tc) puts("");
      lds[0] = 1, n = ans = 1;
      while(scanf("%d", &v[n]), v[n] != -1) lds[n++] = 1;
      for(int i = 1; i < n; i++){
         for(int j = 0; j < i; j++)
            if(v[i] < v[j] && lds[i] < lds[j] + 1)
               lds[i] = lds[j] + 1;
         if(lds[i] > ans) ans = lds[i];
      }
      printf("Test #%d:\n", ++tc);
      printf("  maximum possible interceptions: %d\n", ans);
   }
   return(0);
}
