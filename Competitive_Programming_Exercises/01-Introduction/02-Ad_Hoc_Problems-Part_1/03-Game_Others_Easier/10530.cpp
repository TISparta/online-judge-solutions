#include <bits/stdc++.h>

#define SIZE 20

using namespace std;

int x, lo = -1, hi = 11;
char response[SIZE];

int main(){
   while(scanf("%d\n", &x), x){
      scanf("%[^\n]s", response);
      if( response[0] == 'r' ){
         if( lo < x and x < hi ) puts("Stan may be honest");
         else puts("Stan is dishonest");
         lo = -1, hi = 11;
      }
      else if( response[4] == 'h' ) hi = min(hi, x);
      else lo = max(lo, x);
   }
   return(0);
}
