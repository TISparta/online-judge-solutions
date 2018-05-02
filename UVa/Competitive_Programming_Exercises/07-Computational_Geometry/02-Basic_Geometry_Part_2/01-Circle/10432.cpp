#include <bits/stdc++.h>

const double PI = acos(-1.0);

double r, n;

int main(){
   while(~scanf("%lf %lf", &r, &n))
      printf("%.3lf\n", n * r * r * sin(2.0 * PI / n) / 2.0);
   return(0);
}
