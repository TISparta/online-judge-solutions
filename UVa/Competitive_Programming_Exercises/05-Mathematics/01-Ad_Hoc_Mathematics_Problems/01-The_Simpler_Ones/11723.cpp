#include <bits/stdc++.h>

using namespace std;

int main(){
   int a, b, ans, t = 0;
   while(scanf("%d %d", &a, &b), a | b){
      if(a / b > 26)  
         printf("Case %d: impossible\n", ++t);
      else{
         ans = a / b;
         if(!(a % b))
            ans--;
         printf("Case %d: %d\n", ++t, ans);
      }
   }
   return(0);
}
