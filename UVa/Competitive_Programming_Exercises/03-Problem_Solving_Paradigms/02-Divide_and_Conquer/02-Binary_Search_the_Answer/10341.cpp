#include <bits/stdc++.h>

using namespace std;

int p, q, r, s, t, u;
double lo, hi, mid;

double solve(double x){
   return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

int main(){
   while(scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u)==6){
      lo = 0.0, hi = 1.0;
      if(solve(0.0) * solve(1.0) > 0){
         printf("No solution\n");
         continue;
      }
      for(int it = 0; it < 40; it++){
         mid = (lo + hi) / 2.0;
         if(solve(lo) * solve(mid) > 0.0) lo = mid;
         else hi = mid;
      }
      printf("%.4f\n", mid);
   }
   return(0);
}
