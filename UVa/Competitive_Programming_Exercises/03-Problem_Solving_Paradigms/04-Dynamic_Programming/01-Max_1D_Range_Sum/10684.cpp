#include <bits/stdc++.h>

using namespace std;

int n, ans, sum, v;

int main(){
   while(scanf("%d",&n), n){
      ans = sum = 0;
      for(int i = 0; i < n; i++){
         scanf("%d", &v);
         sum += v;
         if(sum > ans) ans = sum;
         if(sum < 0) sum = 0;
      }
      if(sum == 0) puts("Losing streak.");
      else printf("The maximum winning streak is %d.\n", ans);
   }
   return(0);
}
