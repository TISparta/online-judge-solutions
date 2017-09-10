#include <bits/stdc++.h>

using namespace std;

int tc;
long double A, B, C, a0, a1, a2, Q, R, theta;
long long x, y, z;

bool isValid(long long x, long long y, long long z){
   return ( x < y and y < z and x + y + z == A and x * y * z == B and x * x + y * y + z * z == C );
}

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%Lf %Lf %Lf", &A, &B, &C);
      a0 = -B, a1 = (A * A - C) / 2.0L, a2 = -A;
      Q = ( a2 * a2 - 3.0 * a1 ) / 9.0L;
      R = ( 9.0L * a1 * a2 - 27.0L * a0 - 2.0L * a2 * a2 * a2 ) / 54.0L;
      theta = acosl(R / sqrtl(Q * Q * Q));
      vector <long long> Z;
      for(int k = 0; k < 3; k++)
         Z.push_back( (long long)round( 2.0L * sqrtl(Q) * cosl( ( theta + 2.0L *  M_PI * k ) / 3.0L) - a2 / 3.0L ) );
      sort(Z.begin(), Z.end());
      x = Z[0], y = Z[1], z = Z[2];
      if( isValid(x, y, z) )
         printf("%lld %lld %lld\n", x, y, z);
      else
         puts("No solution.");
   }
   return(0);
}
