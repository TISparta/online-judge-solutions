#include <bits/stdc++.h>

#define MAX_N 110

using namespace std;

int duration, numberOfDepreciation, month, ans;
double payment, amount, depreciation[MAX_N], rate, percentage, current;

int main(){
   while(scanf("%d %lf %lf %d", &duration, &payment, &amount, &numberOfDepreciation), duration > 0){
      ans = 0;
      fill(depreciation, depreciation + MAX_N, -1.0);
      for(int i = 0; i < numberOfDepreciation; i++)
         scanf("%d %lf", &month, &percentage), depreciation[month] = percentage;
      for(int i = 1; i < MAX_N; i++)
         if(depreciation[i] < 0.0) depreciation[i] = depreciation[i - 1];
      rate = amount / duration;
      current = ( payment + amount ) * ( 1.0 - depreciation[0] );
      while(current < amount){
         current *= ( 1.0 - depreciation[++ans] );
         amount -= rate;
      }
      printf(ans == 1 ? "%d month\n" : "%d months\n", ans);
   }
   return(0);
}
