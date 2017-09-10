#include <stdio.h>
#include <math.h>

int main(){
   int n, a, tam, a1, b, c;
   scanf("%d", &n);
   while(n--){
      scanf("%d", &a);
      a1 = a;
      tam = 0;
      while( a1 != 0 ) a1 /= 10, tam++;
      b = pow( 10, tam - 1);
      c = pow( 10, tam - 3);
      if( a == 1 || a == 4 || a == 78 ) printf("+\n");
      else if( a % 100 == 35 ) printf("-\n");
      else if (a % 10 == 4 && a / b == 9 ) printf("*\n");
      else if( tam > 3 && a / c == 190 ) printf("?\n");
      else printf("+\n");
   }
   return(0);
}
