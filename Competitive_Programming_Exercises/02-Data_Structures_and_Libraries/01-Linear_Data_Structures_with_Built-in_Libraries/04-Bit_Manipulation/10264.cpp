#include <bits/stdc++.h>

#define SIZE 1<<16

using namespace std;

int n, v[SIZE], u[SIZE], lim, sum, nd, ans;

int main(){
   while(scanf("%d", &n) != EOF){
      lim = (1<<n), nd = __builtin_ctz(lim), ans = -1;
      for(int i = 0; i < lim; i++) scanf("%d", &v[i]);
      for(int i = 0; i < lim; i++){
         sum = 0;
         for(int j = 0; j < nd; j++) sum += v[i ^ (1<<j)];
         u[i] = sum;
      }
      for(int i = 0; i < lim; i++)
         for(int j = 0; j < nd; j++) ans = max(ans, u[i] + u[i ^ (1<<j)]);
      printf("%d\n", ans);
   }
   return(0);
}
