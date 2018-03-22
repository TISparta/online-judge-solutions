#include <bits/stdc++.h>

using namespace std;

long long N;

int main(){
   while(scanf("%lld", &N), N)
      printf("%lld\n", N - int( sqrt(N) ) - int( sqrt(N / 2)));
   return(0);
}
