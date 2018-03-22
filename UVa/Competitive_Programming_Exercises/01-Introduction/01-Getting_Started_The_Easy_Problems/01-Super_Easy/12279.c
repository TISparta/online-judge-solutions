#include <stdio.h>

int main(){
   int n, a, b, i, x, j = 1;
   while(scanf("%d", &n), n){
      a = b = 0;
      for(i = 0; i < n; i++){
         scanf("%d", &x);
         if(x) a++;
         else b++;
      }
      printf("Case %d: %d\n", j, a - b);
      j++;
   }
   return(0);
}
