#include <stdio.h>
#include <stdbool.h>

int main(){
   int c;
   bool ind = true;
   while((c = getchar()) != EOF){
      if(c == '"' && ind)
         printf("``"), ind = false;
      else if(c == '"' && !ind)
         printf("''"), ind = true;
      else
         putchar(c);
   }
   return(0);
}
