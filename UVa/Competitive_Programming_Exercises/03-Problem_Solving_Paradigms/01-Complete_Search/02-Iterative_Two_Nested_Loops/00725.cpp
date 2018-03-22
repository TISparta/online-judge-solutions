#include <bits/stdc++.h>

using namespace std;

int b, tmp, used, N, ct, tc;

int main(){
   while(scanf("%d", &N), N){
      if(tc++)
         putchar('\n');
      ct = 0;
      for(int a = 1234; a <= 98765 / N; a++){
         b = a * N; tmp = b;
         used = (a < 10000);
         while(tmp)
            used |= 1 << (tmp % 10), tmp /= 10;
         tmp = a;
         while(tmp)
            used |= 1<<(tmp % 10), tmp /= 10;
         if(used == (1<<10) - 1)
            printf("%.5d / %.5d = %d\n", b, a, N), ct++;
      }
      if(!ct)
         printf("There are no solutions for %d.\n", N);
   }
   return(0);
}
