#include <bits/stdc++.h>

using namespace std;

double S, D, V, ans;

int main(){
   while(scanf("%lf %lf", &S, &D) == 2){
      V = D + (S - 1) * S / 2;
      ans = ceil( (sqrt(8 * V + 1) + 1) / 2.0 );
      printf("%.0lf\n", ans - 1);
   }  
   return(0);
}
