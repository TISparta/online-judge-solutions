#include <bits/stdc++.h>

using namespace std;

int main(){
   int c;
   long long n;
   scanf("%d", &c);
   while(c--){
      scanf("%lld", &n);
      printf("%lld\n", (long long)(sqrt(1 + 8 * n) - 1) / 2);
   }  
   return(0);
}
