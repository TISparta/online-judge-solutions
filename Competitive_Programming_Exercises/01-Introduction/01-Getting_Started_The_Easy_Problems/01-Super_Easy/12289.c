#include <stdio.h>
#include <string.h>

int main(){
   int n, i, cont1, cont2, tam;
   char a[6];
   scanf("%d", &n);
   while(n--){
      scanf("%s", a);
      tam = strlen(a);
      if(tam == 3){
         cont1 = cont2 = 0;
         if(a[0] == 'o') cont1++;
         if(a[1] == 'n') cont1++;
         if(a[2] == 'e') cont1++;
         if(cont1 >= 2) printf("1\n");
         else printf("2\n");
      }
      else if(tam == 5) printf("3\n");
   }
   return(0);
}
