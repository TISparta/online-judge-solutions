#include <stdio.h>

int main(){
   int ban[20], N, B, c, b, a, i, ind;
   while(scanf("%d%d", &B, &N),B || N){
      ind = 1;
      for(i = 0; i < B; i++) scanf("%d", &ban[i]);
      for(i = 0; i < N; i++){
         scanf("%d %d %d", &a, &b, &c);
         ban[b - 1] +=c;
         ban[a - 1] -=c;
      }
      for(i = 0; i < B; i++)
         if(ban[i] < 0) ind = 0;
      if(ind) printf("S\n");
      else printf("N\n");
   }
   return(0);
}
