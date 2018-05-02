#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1.0);

int tc, N;
double A, R, theta, ans1, ans2;

int main(){
   while(~scanf("%d %lf", &N, &A), N >= 3){
      theta = 2.0 * PI / N;
      R = sqrt( 2.0 * A / ( 1.0 * N * sin(theta) ) );
      ans1 = PI * R * R - A;
      ans2 = A - PI * R * R * cos(theta / 2.0) * cos(theta / 2.0);
      printf("Case %d: %.5lf %.5lf\n", ++tc, ans1, ans2);
   }
   return(0);
}
