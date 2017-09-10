#include <stdio.h>

int main(){
   int n, a, b, c, i = 1;
   scanf("%d", &n);
   while(n--){
      scanf("%d %d %d", &a, &b, &c);
      if(a > 20 || b > 20 || c > 20){
         printf("Case %d: bad\n", i);
         i++;
      }
      else{
         printf("Case %d: good\n", i);
         i++;
      }
   }
   return(0);
}
