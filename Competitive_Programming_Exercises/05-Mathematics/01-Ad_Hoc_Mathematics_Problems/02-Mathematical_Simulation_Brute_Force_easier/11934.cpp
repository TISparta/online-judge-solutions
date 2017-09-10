#include <bits/stdc++.h>

using namespace std;

int main(){
   int a, b, c, L, d, ans, i;
   while(scanf("%d %d %d %d %d", &a, &b, &c, &d, &L), a || b || c || L || d){
      ans=0;
      for(i = 0; i <= L; i++)
         if(!(((a * i * i) % d + (b * i) % d + c % d) % d))
            ans++;
      printf("%d\n", ans);
   }
   return(0);
}
