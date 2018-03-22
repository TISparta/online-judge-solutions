#include <bits/stdc++.h>

using namespace std;

int n, m, v[1010], lo, hi, mid, _max;

bool isValid(int min_c){
   int c = 1, pib = 0;
   for(int i = 0; i < n; i++){
      if(pib + v[i] <= min_c) pib += v[i];
      else c++, pib = v[i];
   }
   return (c <= m);
}

int main(){
   while(scanf("%d %d", &n, &m)==2){
      _max = -1;
      for(int i = 0; i < n; i++) scanf("%d", &v[i]), _max = max(_max, v[i]);
      lo = _max, hi = 1000000000;
      while(lo != hi){
         mid = (lo + hi) >> 1;
         if(isValid(mid)) hi = mid;
         else lo = mid + 1;
      }
      printf("%d\n", lo);
   }
   return(0);
}
