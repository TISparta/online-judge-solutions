#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1.0), r = 6440.0;

double s, a, R;
char ch;

int main(){
   while(~scanf("%lf %lf %c%*s", &s, &a, &ch)){
      R = r + s;
      if( ch == 'd' ) a *= PI / 180.0;
      else a *= PI / 10800.0;
      a = min(a, 2.0 * PI - a);
      printf("%.6lf %.6lf\n", a * R, 2.0 * R * sin(a / 2.0));
   }
   return(0);
}
