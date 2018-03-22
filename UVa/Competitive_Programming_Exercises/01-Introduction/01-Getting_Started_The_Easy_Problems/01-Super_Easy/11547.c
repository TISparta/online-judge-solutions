#include <stdio.h>

int main(){
   int n, a;
   scanf("%d", &n);
   while(n--){
      scanf("%d", &a);
      a *= 567;
      a /= 9;
      a += 7492;
      a *= 235;
      a /= 47;
      a -= 498;
      a /= 10;
      a  = a % 10;
      a = ( a >= 0 ) ? a : -a;
      printf("%d\n", a);
   }
   return(0);
}
