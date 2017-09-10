#include <stdio.h>
#include <string.h>

int main(){
   char a[10];
   int i = 1;
   while(scanf("%s",a) != EOF){
      if(strcmp(a, "*") == 0) break;
      else if(strcmp(a, "Hajj") == 0){
         printf("Case %d: Hajj-e-Akbar\n", i);
         i++;
      }
      else{
         printf("Case %d: Hajj-e-Asghar\n", i);
         i++;
      }
   }
   return(0);
}
