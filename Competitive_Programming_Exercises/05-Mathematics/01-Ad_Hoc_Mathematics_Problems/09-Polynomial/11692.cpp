#include <bits/stdc++.h>

using namespace std;

int tc;
double L, K, T1, T2, H, A, B, C, D, r, ans1, ans2;

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%lf %lf %lf %lf %lf", &L, &K, &T1, &T2, &H);
      if( H < L ){
         printf("%.6lf %.6lf\n", H, H);
         continue;
      }
      A = T1, B = - K * ( T1 + T2 ) - H, C = K * L;
      D =  sqrt( B * B - 4 * A * C );
      r = 2.0 * C / ( -B - D );
      ans2 = max(H, T1 * r);
      ans1 = ( H == L ) ? H : ans2;
      printf("%.6lf %.6lf\n", ans1, ans2);
   }
   return(0);
}
