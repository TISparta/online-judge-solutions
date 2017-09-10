#include <stdio.h>

int main(){
   int a[10], t = 1, i, max, n;
   char b[10][100];
   scanf("%d", &n);
   while(n--){
      for(i = 0; i < 10; i++){
         scanf("%s", b[i]);
         scanf("%d", &a[i]);
      }
      max = a[0];
      for(i = 1; i < 10; i++)
         if(a[i] > max) max = a[i];
      printf("Case #%d:\n", t);
      t++;
      for(i = 0; i < 10; i++)
         if(a[i] == max)
            printf("%s\n", b[i]);
   }
   return(0);
}
