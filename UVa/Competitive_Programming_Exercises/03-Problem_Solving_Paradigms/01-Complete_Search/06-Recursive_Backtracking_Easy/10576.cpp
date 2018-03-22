#include <bits/stdc++.h>

using namespace std;

int s, d, ans, sum;
bool ok;

int main(){
   while(scanf("%d %d",&s, &d) == 2){
      ans = 0;
      for(int i = 0, j = (1 << 12); i < j; i++){
         ok = true;
         for(int j = 4; j < 12; j++){
            sum = 0;
            for(int k = j - 4; k <= j; k++)
               (i >> k) & 1 ? sum += s : sum -= d;
            if(sum >= 0){
               ok = false;
               break;
            }
         }
         if(ok){
            sum = 0;
            for(int j = 0; j < 12; j++)
               (i >> j) & 1 ? sum += s : sum -= d;
            if(sum > ans)
               ans = sum;
         }
      }
      ans > 0 ? printf("%d\n", ans) : printf("Deficit\n");
   }
   return(0);
}
