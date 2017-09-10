#include <bits/stdc++.h>

using namespace std;

int tc, t, N, r1, c1, r2, c2;

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%d", &t);
      scanf("%d", &N);
      while(t--){
         scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
         if( r1 == r2 and c1 == c2 )
            puts("0");
         else if( abs(r1 - r2) == abs(c1 - c2) )
            puts("1");
         else if( ( abs(r1 - r2) - abs(c1 - c2) ) % 2 == 0 )
            puts("2");
         else
            puts("no move");
      }
   }
   return(0);
}
