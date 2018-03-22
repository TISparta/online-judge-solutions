#include <bits/stdc++.h>

using namespace std;

const int SIZE = 1005;

int n, k;

long long BinomialCoef(int N, int K){
   long long C = 1;
   if( K > N - K ) K = N - K;
   for(int ct = 0; ct < K; ct++)
      C = C * ( N - ct ) / ( 1 + ct );
   return C;
}

int main(){
   while(scanf("%d %d", &n, &k), n | k)
      printf("%lld\n", BinomialCoef(n, k));
   return(0);
}
