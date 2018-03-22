#include <bits/stdc++.h>

using namespace std;

int main(){
   long long m, x, v, V;
   while(scanf("%lld %lld", &m, &x), m | x){
      if(x == 100 || x == 0 )
         printf("Not found\n");
      else{
         V = 0;
         v = (m - 1) * 100 / (100 - x);
         if(v - 1 >= m && (v - 1) * (100 - x) / 100 < 100 * m - 100)
            V = v - 1;
         if(v >= m && v * (100 - x) < 100 * m - 100)
            V = v;
         if(V)
            printf("%lld\n", V);
         else
            printf("Not found\n");
      }
   }
   return(0);
}
