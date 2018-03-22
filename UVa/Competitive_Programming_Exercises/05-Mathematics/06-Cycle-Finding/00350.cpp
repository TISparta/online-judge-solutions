#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> ii;

int tc, Z, I, M, L;

int f(int xo){
   return ( Z * xo + I ) % M;
}

ii FloydCycleFinding(int xo){
   int tortoise = f(xo), hare = f(f(xo));
   while( tortoise != hare ) tortoise = f(tortoise), hare = f(f(hare));
   int mu = 0;
   hare = xo;
   while( tortoise != hare ) tortoise = f(tortoise), hare = f(hare), mu++;
   int lambda = 1;
   hare = f(tortoise);
   while( tortoise != hare ) hare = f(hare), lambda++;
   return ii(mu, lambda);
}

int main(){
   while(scanf("%d %d %d %d", &Z, &I, &M, &L), Z | I | M | L)
      printf("Case %d: %d\n", ++tc, FloydCycleFinding(L).second);
   return(0);
}
