#include <bits/stdc++.h>

using namespace std;

int tc, n;
double a[3010], c[3010];

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%d", &n);
      scanf("%lf %lf", &a[0], &a[n+1]);
      for(int i = 1; i <= n; i++) scanf("%lf", &c[i]);
      double sum = 0;
      for(int i = 1; i <= n; i++) sum += 2 * i * c[n + 1 - i];
      double ans = n * a[0] + a[n + 1] - sum;
      ans /= n + 1;
      printf("%.2lf\n", ans);
      if(tc) putchar('\n');
   }
   return(0);
}
