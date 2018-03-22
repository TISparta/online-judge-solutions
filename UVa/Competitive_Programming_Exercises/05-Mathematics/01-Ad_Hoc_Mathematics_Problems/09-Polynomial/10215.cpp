#include <bits/stdc++.h>

using namespace std;

double L, W, A, B, C, D, X1, X2;
const double eps = 1e-7;

int main(){
   while(scanf("%lf %lf",&L, &W) != EOF){
      A = 12, B = -4 * ( L + W ), C = L * W;
      D = sqrt( B * B - 4 * A * C );
      X1 = 2.0 * C / ( -B + D );
      X2 = min( L / 2.0 + eps, W / 2.0 + eps);
      printf("%.3lf %.3lf %.3lf\n", X1, 0.000f, X2);
   }
   return(0);
}
