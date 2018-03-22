#include <bits/stdc++.h>

using namespace std;

int n;

int main(){
   while(scanf("%d", &n), n){
      if(n <= 2){
         printf("%d\n", n);
         continue;
      }
      for(int p = 0; ; p++)
         if( (1 << p) >= n){
            printf("%d\n", 2 * (n - ( 1<<(p - 1) )));
            goto jump;
         }
      jump: ;
   }
   return(0);
}
