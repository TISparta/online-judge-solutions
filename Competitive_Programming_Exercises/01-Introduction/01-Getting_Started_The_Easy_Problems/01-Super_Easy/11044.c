#include <stdio.h>

int main(){
   int n, a, b, ans;
   scanf("%d", &n);
   while(n--){
      scanf("%d %d", &a, &b);
      ans = ( a / 3 ) * ( b / 3 );
      printf("%d\n", ans);
   }
   return(0);
}
