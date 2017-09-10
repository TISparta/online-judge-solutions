#include <bits/stdc++.h>

using namespace std;

int main(){
   int c, n, m;
   scanf("%d", &c);
   while(c--){
      scanf("%d %d", &n, &m);
      for(int i = 0; i < (1<<n) ; i++)
         if(__builtin_popcount(i^0)==m){
            for(int j= n - 1; j >= 0; j--)
               printf("%d", (i>>j) & 1);
            putchar('\n');
         }
      if(c)
         putchar('\n');
   }
   return(0);
}
