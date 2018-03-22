#include <bits/stdc++.h>

using namespace std;

int main(){
   int c, t = 0;
   float t1, t2, d, v, u;
   bool ok;
   scanf("%d", &c);
   while(c--){
      scanf("%f %f %f", &d, &v, &u);
      ok = true;
      if(v >= u)
         ok = false;
      else{
         t1 = d / u;
         t2 = d / sqrt(u * u - v * v);
         if(fabs(t1 - t2) < 1e-12)
            ok = false;
      }
      if(ok)
         printf("Case %d: %.3f\n", ++t, abs(t1 - t2));
      else
         printf("Case %d: can't determine\n", ++t);
   }
   return(0);
}
