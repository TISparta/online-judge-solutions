#include <bits/stdc++.h>

using namespace std;

int main(){
   int c, x, y, z, ans;
   scanf("%d", &c);
   while(c--){
      scanf("%d %d %d", &x, &y, &z);
      x += y;
      ans = 0;
      while(x >= z)
         ans += x / z, x = x / z + x % z;
      printf("%d\n", ans);
   }
   return(0);
}
