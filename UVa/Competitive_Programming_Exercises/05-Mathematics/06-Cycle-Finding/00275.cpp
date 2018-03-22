#include <bits/stdc++.h>

using namespace std;

const int SIZE = 1000;

int ct, num, den, pos, mu, lambda, vis[SIZE], f[SIZE];

int main(){
   while(scanf("%d %d", &num, &den), num | den){
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
      putchar('.');
      ct = 1;
      for(int it = 0; it < mu; ct++, it++){
         if( ct == 50 ) putchar('\n'), ct = 0;
         printf("%d", f[it]);
      }
      if( not ( f[mu] == 0 and lambda == 1 ) )
         for(int it = mu; it < mu + lambda; ct++, it++){
            if( ct == 50 ) putchar('\n'), ct = 0;
            printf("%d", f[it]);
         }
      putchar('\n');
      if( f[mu] == 0 and lambda == 1 )
         puts("This expansion terminates.");
      else
         printf("The last %d digits repeat forever.\n", lambda);
      putchar('\n');
   }
   return(0);
}
