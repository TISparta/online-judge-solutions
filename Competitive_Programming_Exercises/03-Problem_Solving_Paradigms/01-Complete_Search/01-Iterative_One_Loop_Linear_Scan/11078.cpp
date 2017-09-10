#include <bits/stdc++.h>

using namespace std;

int main(){
   int c, n, ans, tmp;
   vector <int> x(100000);
   scanf("%d", &c);
   while(c--){
      scanf("%d", &n);
      for(int i = 0; i < n; i++)
         scanf("%d", &x[i]);
      tmp = x[0];
      ans = -1600000;
      for(int i = 0; i < n - 1; i++)
         tmp = max(tmp, x[i]), ans = max(ans, tmp - x[i + 1]);
      printf("%d\n", ans);
   }
   return(0);
}
