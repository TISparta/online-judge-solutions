#include <bits/stdc++.h>

using namespace std;

long long N, S2, R2, S3, R3, S4, R4;

int main(){
   while(~scanf("%lld", &N)){
      S2 = N * ( N + 1 ) * ( 2 * N + 1 ) / 6;
      R2 = N * ( N - 1 ) * ( N + 1 ) * ( 3 * N + 2 ) / 12;
      S3 = ( N * ( N + 1 ) / 2 ) * ( N * ( N + 1 ) / 2 );
      R3 = ( ( N - 1 ) * N / 2 ) * ( N * ( N + 1 ) / 2 ) * ( ( N + 1 ) * ( N + 2 ) / 2 );
      S4 = N * ( N + 1 ) * ( 2 * N + 1 ) * ( 3 * N * N + 3 * N - 1 ) / 30;
      R4 = S3 * S3 - S4;
      printf("%lld %lld %lld %lld %lld %lld\n", S2, R2, S3, R3, S4, R4);
   }
   return(0);
}
