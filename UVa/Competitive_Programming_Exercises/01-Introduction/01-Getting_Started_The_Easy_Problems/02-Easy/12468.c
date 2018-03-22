#include <stdio.h>
#define swap(a, b, temp) ( temp = a, a = b, b = temp )

int main(){
   int a, b, ans1, ans2, temp;
   while(scanf("%d %d", &a, &b), a != -1, b != -1){
      if(a > b) swap(a,b,temp);
      ans1 = b - a;
      ans2 = 100 - b + a;
      if(ans1 < ans2) printf("%d\n", ans1);
      else printf("%d\n", ans2);
   }
   return(0);
}
