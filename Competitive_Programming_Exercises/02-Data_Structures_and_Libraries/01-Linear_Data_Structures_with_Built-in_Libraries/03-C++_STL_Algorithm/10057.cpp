#include <bits/stdc++.h>

#define MAX_N 1000010
#define MAX_V 65540

using namespace std;

int n, nn, v[MAX_N], ct[MAX_V];

int main(){
   while(scanf("%d",&n) == 1){
      memset(ct, 0, sizeof ct);
      for(int i = 0; i < n; i++) scanf("%d", &v[i]), ct[v[i]]++;
      nn = n>>1;
      if(n&1){
         nth_element(v, v + nn,v + n);
         printf("%d %d 1\n", v[nn], ct[v[nn]]);
      }
      else{
         nth_element(v,v + nn,v + n);
         nth_element(v,v + nn - 1,v + n);
         if(v[nn] == v[nn - 1]) printf("%d %d 1\n",v[nn], ct[v[nn]]);
         else printf("%d %d %d\n",v[nn - 1],ct[v[nn - 1]]+ct[v[nn]],v[nn] - v[nn - 1] + 1);
      }
   }
   return(0);
}
