#include <bits/stdc++.h>

#define SIZE 15

using namespace std;

int tc, G, guess[SIZE][5], a[SIZE], b[SIZE], pos, aux, s[SIZE], ct, ans;
bool vis[SIZE];

bool is_correct(int num){
   memset(s, 0, sizeof s);
   pos = 3;
   while(num) s[pos--] = num % 10, num /= 10;
   for(int it = 0; it < G; it++){
      int x = 0, y = 0;
      memset(vis, false, sizeof vis);
      for(int i = 0; i < 4; i++)
         if( s[i] == guess[it][i] ) x++, vis[i] = true;
      if( x != a[it] ) return false;
      for(int i = 0; i < 4; i++)
         if( guess[it][i] != s[i] )
            for(int j = 0; j < 4; j++)
               if( not vis[j] and guess[it][i] == s[j] )
                  vis[j] = true, y++, j = 4;
      if( y != b[it] ) return false;
   }
   return true;
}

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%d", &G);
      memset(guess, 0, sizeof guess);
      for(int it = 0; it < G; it++){
         scanf("%d %d/%d", &aux, &a[it], &b[it]);
         pos = 3;
         while(aux) guess[it][pos--] = aux % 10, aux /= 10;
      }
      ct = ans = 0;
      for(int it = 0; it < 10000; it++)
         if( is_correct(it) ) ans = it, ct++;
      if( ct == 0 ) puts("impossible");
      else if( ct == 1 ) printf("%.4d\n", ans);
      else puts("indeterminate");
   }
   return(0);
}
