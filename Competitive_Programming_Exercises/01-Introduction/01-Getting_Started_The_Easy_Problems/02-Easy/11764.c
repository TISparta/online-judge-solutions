#include <stdio.h>

int main(){
   int n, a[50], i, t = 1, taller, shorter, N;
   scanf("%d", &N);
   while(N--){
      taller = shorter = 0;
      scanf("%d", &n);
      for(i = 0; i < n; i++) scanf("%d", &a[i]);
      for(i = 0; i < n - 1; i++)
         if(a[i] < a[i+1]) taller++;
         else if (a[i] > a[i+1]) shorter++;
      printf("Case %d: %d %d\n", t, taller, shorter);
      t++;
   }
   return(0);
}
