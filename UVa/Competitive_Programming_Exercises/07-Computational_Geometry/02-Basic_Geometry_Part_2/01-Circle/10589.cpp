#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-12;

int N, M, a;
double X, Y;

bool inCircle(const double&px, const double& py, const int& cx, const int &cy){
   double dx = px - cx, dy = py - cy, d = dx * dx + dy * dy;
   if( d - EPS < a * a ) return true;
   if( fabs(a * a - d) < EPS ) return true;
   return false;
}

bool isInside(const double& x, const double& y){
   return ( inCircle(x, y, 0, 0) and inCircle(x, y, a, 0) and
      inCircle(x, y, a, a) and inCircle(x, y, 0, a) );
}

int main(){
   while(scanf("%d %d", &N, &a), N ){
      M = 0;
      for(int it = 0; it < N; it++){
         scanf("%lf %lf", &X, &Y);
         if( isInside(X, Y) ) M++;
      }
      printf("%.5lf\n", 1.0 * M * a * a / N);
   }
   return(0);
}
