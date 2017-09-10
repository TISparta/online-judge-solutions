#include <bits/stdc++.h>

using namespace std;

int tc,n;
const double r2 = 2 * sin(acos(-1) / 4);

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%d", &n);
      if(n == 1) puts("0.000");
      else printf("%.3lf\n",(n - 1) * 4 + (n - 2) * (n - 2) * r2);  
      if(tc) putchar('\n');
   }
   return(0);
}
