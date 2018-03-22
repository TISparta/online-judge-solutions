#include <bits/stdc++.h>

using namespace std;

int tc, x, k, xo, yo, d;

void extendedEuclid(int a,int b){
   if( b == 0 ){
      xo = 1, yo = 0, d = a;
      return;
   }
   extendedEuclid(b, a % b);
   int x1 = yo, y1 = xo - (a / b) * yo;
   xo = x1, yo = y1;
}

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%d %d", &x, &k);
      extendedEuclid(x / k, (x + k - 1) / k);
      printf("%lld %lld\n", 1LL * xo * ( x / d ), 1LL * yo * ( x / d ));
   }
   return(0);
}
