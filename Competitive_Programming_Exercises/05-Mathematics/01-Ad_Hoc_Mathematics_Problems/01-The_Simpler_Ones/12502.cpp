#include <bits/stdc++.h>

using namespace std;

int main(){
   int c, a, b, m;
   scanf("%d", &c);
   while(c--){
      scanf("%d %d %d", &a, &b, &m);
      printf("%d\n", (a + a - b) * m / (a + b));
   }
   return(0);
}
