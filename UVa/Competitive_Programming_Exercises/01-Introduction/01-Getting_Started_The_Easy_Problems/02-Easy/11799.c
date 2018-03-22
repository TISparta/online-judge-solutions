#include <stdio.h>

int main(){
   int N, i, a[10000], n, max, t = 1;
   scanf("%d", &N);
   while(N--){
      scanf("%d", &n);
      for(i = 0; i < n; i++) scanf("%d",&a[i]);
      max = a[0];
      for(i = 1; i < n; i++)
         if(a[i] > max) max = a[i];
      printf("Case %d: %d\n", t, max);
      t++;
   }
   return(0);
}
