#include <bits/stdc++.h>

using namespace std;

long long d, S, P;

int main(){
   for(int a = 1; a < 2000 - a; a++)
      for(int b = a; b < 2000 - a - b; b++)
         for(int c= b ; c < 2000 - a - b; c++){
            P = a * b * c, S = a + b + c;
            if(P <= 1000000) continue;
            d = 1000000 * S / (P - 1000000);
            S += d, P *= d;
            if(d < c || S > 2000) continue;
            if(fabs(S / 1e2 - P / 1e8) < 1e-9)
               printf("%.2f %.2f %.2f %.2f\n", a / 100.0, b / 100.0, c / 100.0, d / 100.0);
         }
   return(0);
}
