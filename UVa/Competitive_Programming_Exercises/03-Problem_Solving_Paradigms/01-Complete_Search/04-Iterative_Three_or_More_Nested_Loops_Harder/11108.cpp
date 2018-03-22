#include <bits/stdc++.h>

#define SIZE 110

using namespace std;

int p, q, r, s, t, idx;
char wff[SIZE];
bool ans;

bool is_tautology(int mask){
   char ch = wff[idx++];
   if( 'p' <= ch and ch <= 't' ) return ( mask >> ( ch - 'p' ) ) & 1 ;
   if( ch == 'N' ) return not is_tautology(mask);
   bool a = is_tautology(mask);
   bool b = is_tautology(mask);
   if( ch == 'K' ) return ( a and b );
   if( ch == 'A' ) return ( a or b );
   if( ch == 'C' ) return ( (not a) or b );
   if( ch == 'E' ) return ( a == b );
}

int main(){
   while(scanf("%s", wff), wff[0] != '0'){
      ans = true;
      for(int mask = 0; ans and mask < 32; mask++)
         idx = 0, ans &= is_tautology(mask);
      if( ans ) puts("tautology");
      else puts("not");
   }
   return(0);
}
