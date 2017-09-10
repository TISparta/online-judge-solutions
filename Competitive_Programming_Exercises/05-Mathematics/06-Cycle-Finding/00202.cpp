#include <bits/stdc++.h>

using namespace std;

const int SIZE = 3000;

int num, den, pos, mu, lambda, vis[SIZE], f[SIZE];

int main(){
   while(~scanf("%d %d", &num, &den)){
      printf("%d/%d = %d.", num, den, num / den);
      num %= den;
      pos = 0;
      fill(vis, vis + den, 0);
      while( vis[num] == 0 ){
         f[pos] = 10 * num / den;
         vis[num] = pos;
         num = ( num * 10 ) % den;
         pos++;
      }
      lambda = pos - vis[num];
      mu = pos - lambda;
      if( mu == 1 and f[0] == f[lambda] ) mu = 0;
      for(int it = 0; it < mu; it++) printf("%d", f[it]);
      putchar('(');
      for(int it = mu, ct = mu; it < mu + lambda; ct++, it++){
         if( ct == 50 ) printf("..."), it = pos;
         else printf("%d", f[it]);
      }
      puts(")");
      printf("   %d = number of digits in repeating cycle\n", lambda);
      putchar('\n');
   }
   return(0);
}
