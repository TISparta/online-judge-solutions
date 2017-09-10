#include <bits/stdc++.h>

using namespace std;

int T, v[15];
double lo, hi, mid;

double solve(double IRR){
   double ans = v[0];
   for(int i = 1; i <= T; i++) ans += v[i] / pow(1 + IRR, i);
   return ans;
}

int main(){
   while(scanf("%d", &T), T){
      for(int i = 0; i <= T; i++) scanf("%d", &v[i]);
      lo = -0.99, hi = 10000.00;
      for(int it = 0; it < 80; it++){
         mid = (lo + hi) / 2.0;
         if(solve(mid) * solve(lo) > 0) lo = mid;
         else hi = mid;
      }
      printf("%.2lf\n", (lo + hi) / 2.0);
   }
   return(0);
}
