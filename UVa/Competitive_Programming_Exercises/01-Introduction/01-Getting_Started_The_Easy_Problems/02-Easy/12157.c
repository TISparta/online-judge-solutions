#include <stdio.h>
#define min(a,b) ( a <= b ? a : b );

int main(){
   int N, n, a, sum1, sum2, i, sum, t = 1;
   scanf("%d", &N);
   while(N--){
      sum1 = sum2 = sum = 0;
      scanf("%d",&n);
      for(i = 0; i < n; i++){
         scanf("%d", &a);
         sum1 += (a / 30) * 10 + 10;
         sum2 += (a / 60) * 15 + 15;
      }
      sum = min(sum1, sum2);
      if(sum == sum1 && sum == sum2) printf("Case %d: Mike Juice %d\n", t, sum);
      else if(sum == 1 && sum != sum2) printf("Case %d: Mile %d\n", t, sum);
      else printf("Case %d: Juice %d\n", t, sum);
      t++;
   }
   return(0);
}
