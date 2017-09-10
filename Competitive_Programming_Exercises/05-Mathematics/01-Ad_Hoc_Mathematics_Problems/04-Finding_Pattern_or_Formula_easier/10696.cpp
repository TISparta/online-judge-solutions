#include <bits/stdc++.h>

using namespace std;

int main(){
   int n, ans;
   while(scanf("%d", &n), n){
      if(n <= 101)
         ans = 91;
      else
         ans = n - 10;
      printf("f91(%d) = %d\n", n, ans);
   }
   return(0);
}
