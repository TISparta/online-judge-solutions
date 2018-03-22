#include <stdio.h>
#include <string.h>

int main(){
   int n, ans = 0, monto;
   char aviso[10];
   scanf("%d", &n);
   while(n){
      scanf("%s", aviso);
      if(strcmp(aviso,"donate") == 0){
         scanf("%d", &monto);
         ans += monto;
         n--;
      }
      if(strcmp(aviso,"report") == 0){
         printf("%d\n",ans);
         n--;
      }
   }
   return(0);
}
