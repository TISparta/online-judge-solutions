#include <stdio.h>

int main(){
   int cond = 1, n, x, y, a, b;
   while(cond){
   scanf("%d", &n);
   if(n == 0) break;
   scanf("%d %d", &x, &y);
      while(n--){
      scanf("%d %d", &a, &b);
      if(a > x && b > y) printf("NE\n");
      else if(a < x && b > y) printf("NO\n");
      else if(a < x && b < y) printf("SO\n");
      else if(a > x && b < y) printf("SE\n");
      else printf("divisa\n");
      }
   }
   return(0);
}
