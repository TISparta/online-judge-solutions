#include <bits/stdc++.h>

using namespace std;

int tc;
unsigned long long m, n;

unsigned long long gcd(unsigned long long a, unsigned long long b){
   return b == 0 ? a : gcd(b, a % b);
}


int main(){
   scanf("%d", &tc);
   for(int t = 1; t <= tc; t++){
      scanf("%llu %llu", &m, &n);
      printf("Case %d: %llu\n", t, m / gcd(m, n) + n / gcd(m, n));
   }
   return(0);
}
