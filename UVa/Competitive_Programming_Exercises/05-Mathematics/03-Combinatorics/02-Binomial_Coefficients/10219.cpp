#include <bits/stdc++.h>

using namespace std;

int n, k;

inline double s(int it, int ct){
   double sum = 0;
   while(ct--) sum += log10(it--);
   return sum;
}

inline int solve(){
   return floor( s(n, k) - s(k, k) ) + 1;
}

int main(){
   while(~scanf("%d %d", &n, &k))
      printf("%d\n", solve());
   return(0);
}
