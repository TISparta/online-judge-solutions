#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1.0);

int tc;
double D, L;

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%lf %lf", &D, &L);
      printf("%.3lf\n", PI * L * sqrt( L * L - D * D ) / 4.0 );
   }
   return(0);
}
