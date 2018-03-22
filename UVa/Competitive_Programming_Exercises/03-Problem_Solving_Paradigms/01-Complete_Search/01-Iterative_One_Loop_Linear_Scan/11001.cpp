#include <bits/stdc++.h>

using namespace std;

int main(){
   int v, vo, ans;
   double tmp;
   vector <double> x;
   const double k = 0.3;
   bool ind;
   while(scanf("%d%d", &v, &vo),v || vo){
      ans = 0;
      for(int i = 1; i <= v; i++){
         if((double)v / i <= vo)
            break;
         tmp = i * k * sqrt((double)v / i - vo);
         x.push_back(tmp);
      }
      tmp = 0;
      for(int i = 0; i < x.size(); i++)
         if(tmp <= x[i])
            tmp = x[i], ans = i + 1;
      for(int i = 0; i < x.size(); i++)
         if(ans != i + 1 && fabs(x[i] - tmp) < 1e-12)
            ans = 0;
      printf("%d\n", ans);
      x.clear();
   }
   return(0);
}
