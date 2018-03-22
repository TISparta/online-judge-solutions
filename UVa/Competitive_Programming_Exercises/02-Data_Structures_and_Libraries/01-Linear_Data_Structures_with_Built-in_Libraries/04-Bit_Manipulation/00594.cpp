#include <bits/stdc++.h>

using namespace std;

long long N, tmp;

long long convert(long long n){
   bitset <32> bs1(n), bs2;
   for(int i = 0; i < 8; i++) bs2[24 + i] = bs1[i];
   for(int i = 8; i < 16; i++) bs2[8 + i] = bs1[i];
   for(int i = 16; i < 24; i++) bs2[ -8 + i] = bs1[i];
   for(int i = 24; i < 32; i++) bs2[ -24 + i] = bs1[i];
   tmp = 0;
   for(int i = 0; i < 32; i++) tmp += bs2[i] * (1<<i);
   return tmp;
}

int main(){
   while(scanf("%lld", &N) == 1)
      printf("%lld converts to %lld\n", N, convert(N));
   return(0);
}
