#include <stdio.h>
#include <string.h>

int main(){
   int n, N, i, j;
   char p, a[100][20], aux[20];
   scanf("%d", &N);
   while(N--){
      p = 0;
      scanf("%d",&n);
      for(i = 0; i < n; i++){
         scanf("%s", a[i]);
         if(!strcmp(a[i], "SAME")){
            scanf("%s", aux);
            scanf("%d", &j);
            strcpy(a[i], a[j-1]);
         }
      }
      for(i = 0; i < n; i++)
         if(!strcmp(a[i], "LEFT")) p--;
         else p++;
      printf("%d\n", p);
   }
   return(0);
}
