#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1.0), EPS = 1e-9;

double R, N, theta, alfa, r, A, B, blue, green;

int main(){
   while(~scanf("%lf %lf", &R, &N)){
      theta = PI / N;
      alfa = PI - 2.0 * theta;
      r = R / ( 1.0 + 1.0 / sin(theta) );
      A = r * cos(theta) * ( R - r * ( 1.0 + sin(theta) ) );
      B = r * r * alfa / 2.0 - r * r * sin(2.0 * theta) / 2.0;
      blue = N * ( A - B );
      green = PI * R * R - N * PI * r * r - blue;
      if( fabs(N - 1.0) < EPS ) r = R, blue = green = 0.0;
      printf("%.10lf %.10lf %.10lf\n", r, blue, green);
   }
   return(0);
}
