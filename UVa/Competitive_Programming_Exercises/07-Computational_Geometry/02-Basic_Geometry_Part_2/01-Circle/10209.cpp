#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1.0);

double L, A, B, C, D, K1, K2, theta, h, ans1, ans2, ans3;

int main(){
   theta = PI / 6.0;
   while(~scanf("%lf", &L)){
      h = sqrt(3) * L / 2.0;
      D = L * L * theta / 2.0 - h * L / 4.0;
      C = L * ( L - h ) - 2.0 * D;
      K1 = PI * L * L / 2.0 - L * L;
      K2 = PI * L * L / 4.0 - 2.0 * C;
      B = K2 - K1;
      A = K1 - 2.0 * B;
      ans1 = A, ans2 = 4.0 * B, ans3 = 4.0 * C;
      printf("%.3lf %.3lf %.3lf\n", ans1, ans2, ans3);
   }
   return(0);
}
