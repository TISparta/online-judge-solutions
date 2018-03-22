#include <bits/stdc++.h>

using namespace std;

int tc, m, n;
char ch;

int main(){
   scanf("%d\n", &tc);
   while(tc--){
      scanf("%c %d %d\n", &ch, &m, &n);
      if( ch == 'r' or ch == 'Q') printf("%d\n", min(m, n));
      else if( ch == 'k' ) printf("%d\n", ( m * n + 1 ) / 2);
      else printf("%d\n", ( ( n + 1 ) / 2 ) * ((  m + 1 ) / 2 ) );
   }
   return(0);
}
