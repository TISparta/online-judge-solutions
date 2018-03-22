#include <bits/stdc++.h>

using namespace std;

int main(){
   char tmp[100];
   int h, m, s, v = 0, nv, t = 0, l, n;
   double d = 0;
   while (cin.getline(tmp, 100)){
      n = sscanf(tmp, "%d:%d:%d %d", &h, &m, &s, &nv);
      t = h * 3600 + m * 60 + s;
      d += (t - l) * v;
      l = t;
      if (n == 3)
         printf("%.2d:%.2d:%.2d %.2f km\n", h, m, s, d / 3600);
      else if (n == 4)
         v = nv;
   }
   return(0);
}
