#include <stdio.h>
#define abs(x) ( x >= 0 ? x : -x )

int main(){
   int N, n, ind, a, b, i, dist1[1000], dist2;
   scanf("%d",&N);
   while(N--){
      ind = 1;
      scanf("%d", &n);
      for(i = 0; i < n; i++){
         scanf("%d %d", &a, &b);
         dist1[i] = abs(a - b);
      }
      dist2 = dist1[1];
      for(i = 0; i < n; i++)
         if(dist1[i] != dist2) ind = 0;
      if(ind) printf("yes\n");
      else printf("no\n");
      if(N) printf("\n");
   }
   return(0);
}
