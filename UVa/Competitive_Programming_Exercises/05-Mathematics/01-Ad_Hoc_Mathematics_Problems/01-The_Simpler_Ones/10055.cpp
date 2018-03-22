#include <bits/stdc++.h>

using namespace std;

int main(){
   long long a, b;
   while(scanf("%lld %lld", &a, &b) == 2)
      printf("%lld\n", abs(b - a));
   return(0);
}
