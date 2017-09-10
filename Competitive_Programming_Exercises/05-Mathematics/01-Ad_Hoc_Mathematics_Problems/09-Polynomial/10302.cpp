#include <bits/stdc++.h>

using namespace std;

int n;

inline long long pow2(long long p){
   return p * p;
}

int main(){
   while(~scanf("%d", &n)){
      printf("%lld\n", pow2( 1LL * n * ( n + 1 ) / 2 ));
   }
   return(0);
}
