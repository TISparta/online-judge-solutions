#include <bits/stdc++.h>

#define SIZE 1010

using namespace std;

int pib, ct, num, v[SIZE], ans;

int gcd(int a, int b){
   return b == 0 ? a : gcd(b , a % b);
}

int main(){
   while(scanf("%d", &pib), pib){
      ct = 0;
      while(scanf("%d", &num), num) v[ct++] = num;
      for(int it = 0; it < ct; it++) v[it] = abs(v[it] - pib);
      ans = v[0];
      for(int it = 1; it < ct; it++) ans = gcd( ans, v[it]);
      printf("%d\n", ans);
   }
   return(0);
}
