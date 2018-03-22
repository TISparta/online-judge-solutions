#include <bits/stdc++.h>

using namespace std;

int n, num, u[25], v[25], lis[25], LIS;

int main(){
   scanf("%d", &n);
   for(int i = 0; i < n; i++) scanf("%d", &u[i]);
   while(scanf("%d", &num) == 1){
      v[num - 1] = u[0];
      for(int i = 1; i < n; i++) scanf("%d", &num), v[num - 1] = u[i];
      LIS = 0;
      for(int i = 0; i < n; i++){
         lis[i] = 1;
         for(int j = 0; j < i; j++)
            if(v[i] > v[j] && lis[i] < lis[j] + 1)
               lis[i] = lis[j] + 1;
         if(lis[i] > LIS) LIS = lis[i];
      }
      printf("%d\n", LIS);
   }
   return(0);
}
