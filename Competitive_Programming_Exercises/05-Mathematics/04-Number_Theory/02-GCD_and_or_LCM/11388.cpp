#include <bits/stdc++.h>

using namespace std;

int tc, G, L;

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%d %d", &G, &L);
      if( L % G != 0 ) puts("-1");
      else printf("%d %d\n", G, L);
   }
   return(0);
}
