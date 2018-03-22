#include <bits/stdc++.h>

using namespace std;

int N, a, b;

inline int f(int xo){
   xo %= N;
   return ( ( ( 1LL * a * xo ) % N ) * xo % N + b ) % N;
}

int Brent_Cycle_Finding(int xo){
   int p = 1, lambda = 1, tortoise = xo, hare = f(xo);
   while( tortoise != hare ){
      if( p == lambda ) tortoise = hare, p <<= 1, lambda = 0;
      hare = f(hare);
      lambda++;
   }
   return lambda;
}

int main(){
   while(scanf("%d %d %d", &N, &a, &b) == 3){
      a %= N, b %= N;
      printf("%d\n", N - Brent_Cycle_Finding(0));
   }
   return(0);
}
