#include <bits/stdc++.h>

using namespace std;

int tc, n, v[100010], l0, hi, mid, pib;

bool isValid(int strength){
   pib = v[0];
   for(int i = 1; i < n + 1; i++){
      if(strength < pib) return false;
      else if(strength == pib) strength--;
      pib = v[i] - v[i - 1];
   }
   return true;
}

int main(){
   scanf("%d", &tc);
   for(int t = 1; t <= tc; t++){
      scanf("%d", &n);
      for(int i = 0; i < n; i++) scanf("%d", &v[i]);
      l0 = 1, hi = 10000000;
      while(l0 != hi){
         mid = (l0 + hi) >> 1;
         if(isValid(mid)) hi = mid;
         else l0 = mid + 1;
      }
      printf("Case %d: %d\n", t, l0);
   }
   return(0);
}
