#include <bits/stdc++.h>

using namespace std;

int main(){
   int n, ans;
   while(scanf("%d", &n), n){
      ans = 0;
      while(n >= 3)
         ans += n / 3, n = n / 3 + n % 3;
      if(n == 2)
         ans++;
      printf("%d\n", ans);
   }
   return(0);
}
