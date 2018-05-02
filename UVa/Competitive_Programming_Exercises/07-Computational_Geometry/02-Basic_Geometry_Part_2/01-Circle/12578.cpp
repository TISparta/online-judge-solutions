#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1.0);

int tc;
double L, W, r, red, green;

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%lf", &L);
      W = L * 0.6;
      r = L * 0.2;
      red = PI * r * r;
      green = W * L - red;
      printf("%.2lf %.2lf\n", red, green);
   }
   return(0);
}
