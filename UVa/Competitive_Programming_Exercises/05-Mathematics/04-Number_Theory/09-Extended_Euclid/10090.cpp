#include <bits/stdc++.h>

using namespace std;

long long n, n1, n2, c1, c2, xo, yo, d, x, y, value, L, U, X, Y;

void extendedEuclid(long long a, long long b){
   if( b == 0 ){
      xo = 1, yo = 0, d = a;
      return;
   }
   extendedEuclid(b, a % b);
   long long x1 = yo, y1 = xo - (a / b) * yo;
   xo = x1, yo = y1;
}

int main(){
   while(scanf("%lld", &n), n){
      scanf("%lld %lld", &c1, &n1);
      scanf("%lld %lld", &c2, &n2);
      extendedEuclid(n1, n2);
      if( n % d != 0 ) puts("failed");
      else{
         x = xo * n / d, y = yo * n / d;
         n1 /= d, n2 /= d;
         L = ceil( -1.0 * x / n2 ), U = floor( 1.0 * y / n1 );
         if( L > U ) puts("failed");
         else{
            value = c1 * n2 - c2 * n1;
            if( value * L < value * U )
               X = x + n2 * L, Y = y - n1 * L;
            else
               X = x + n2 * U, Y = y - n1 * U;
            printf("%lld %lld\n", X, Y);
         }
      }
   }
   return(0);
}
