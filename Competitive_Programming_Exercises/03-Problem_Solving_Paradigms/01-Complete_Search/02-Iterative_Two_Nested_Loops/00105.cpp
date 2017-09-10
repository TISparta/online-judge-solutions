#include <bits/stdc++.h>

using namespace std;

int x, y, z, X = INT_MAX, Z = 0, h[10010];

int main(){
   while(scanf("%d %d %d", &x, &y, &z) == 3){
      for(int i = x; i < z; i++)
         h[i] = max(h[i], y);
      X = min(x, X);
      Z = max(z, Z);
   }
   for(int i = X; i < Z; i++){
      printf("%d %d ",i, h[i]);
      while(h[i] == h[i + 1]) i++;
   }
   printf("%d 0\n", Z);
   return(0);
}
