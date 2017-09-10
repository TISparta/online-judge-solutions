#include <stdio.h>

int main(){
   int i, sum, tam, n, a;
   while(scanf("%d", &n), n){
      if(n / 10 == 0) sum = n;
      else
         while(n / 10 != 0){
         sum = 0;
         a = n;
            while(a != 0){
               sum += a % 10;
               a /= 10;
            }
      n = sum;
      }
      printf("%d\n", sum);
   }
   return(0);
}
