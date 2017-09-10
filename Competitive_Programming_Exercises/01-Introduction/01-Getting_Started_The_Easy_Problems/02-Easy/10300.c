#include <stdio.h>

int main(){
   int N, n, a, b, c, i;
   float sum;
   scanf("%d", &N);
   while(N--){
      sum = 0;
      scanf("%d", &n);
      for(i = 0; i < n; i++){
         scanf("%d %d %d", &a, &b, &c);
         sum += (float)a / b * c * b;
      }
      printf("%d\n", (int)sum);
   }
   return(0);
}
