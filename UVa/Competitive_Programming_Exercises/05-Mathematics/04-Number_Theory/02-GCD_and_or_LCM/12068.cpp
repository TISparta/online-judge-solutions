#include <bits/stdc++.h>

#define SIZE 20

using namespace std;

int tc, n;
long long v[SIZE], num, den;

long long gcd(long long a, long long b){
   return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b){
   return a * ( b / gcd(a, b));
}

int main(){
   scanf("%d", &tc);
   for(int t = 1; t <= tc; t++){
      scanf("%d", &n);
      for(int it = 0; it < n; it++) scanf("%lld", &v[it]);
      num = v[0];
      for(int it = 1; it < n; it++) num = lcm(num, v[it]);
      den = 0;
      for(int it = 0; it < n; it++) den += num / v[it];
      num *= n;
      printf("Case %d: %lld/%lld\n", t, num / gcd(num, den), den / gcd(num, den));
   }
   return(0);
}
