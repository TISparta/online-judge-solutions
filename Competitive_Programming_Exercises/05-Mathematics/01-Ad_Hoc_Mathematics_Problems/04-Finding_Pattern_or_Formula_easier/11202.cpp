#include <bits/stdc++.h>

using namespace std;

int tc, n, m, v1, v2;

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%d %d", &n, &m);
      v1 = (n + 1) / 2;
      v2 = (m + 1) / 2;
      if(n == m)
         printf("%d\n", v1 * (v1 + 1) / 2);
      else
         printf("%d\n",v1 * v2);
   }
   return(0);
}
