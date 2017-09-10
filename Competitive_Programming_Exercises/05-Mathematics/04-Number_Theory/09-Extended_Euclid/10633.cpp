#include <bits/stdc++.h>

using namespace std;

long long N_M;

int main(){
   while(scanf("%llu", &N_M), N_M)
      for(long long L = ( N_M + 8 )/ 9 - 1, U = N_M / 9; L <= U; L++)
         printf( L != U ? "%lld " : "%lld\n",  L + N_M);
   return(0);
}
