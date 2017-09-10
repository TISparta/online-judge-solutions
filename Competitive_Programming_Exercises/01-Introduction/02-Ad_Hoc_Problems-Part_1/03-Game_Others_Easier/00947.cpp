#include <bits/stdc++.h>

#define SIZE 10

using namespace std;

int tc, cp, wp, len, lim, ans;
char guess[SIZE], v[SIZE];
bool vis[SIZE];

bool check(int num){
   memset(vis, false, sizeof vis);
   for(int it = len - 1; it >= 0; it--){
      v[it] = num % 10 + '0', num /= 10;
      if( v[it] == '0' ) return false;
   }
   int a = 0, b = 0;
   for(int it = 0; it < len; it++)
      if( v[it] == guess[it] ) a++, vis[it] = true;
   if( a != cp ) return false;
   for(int it = 0; it < len; it++)
      if( guess[it] != v[it] ){
         for(int i = 0; i < len; i++)
            if( not vis[i] and v[i] == guess[it] )
               b++, vis[i] = true, i = len;
      }
   return ( b == wp );
}

int main(){
   scanf("%d\n", &tc);
   while(tc--){
      scanf("%s %d %d\n", guess, &cp, &wp);
      len = strlen(guess);
      lim = exp10(len);
      ans = 0;
      for(int it = (lim - 1) / 9; it < lim; it++)
         ans += check(it);
      printf("%d\n", ans);
   }
   return(0);
}
