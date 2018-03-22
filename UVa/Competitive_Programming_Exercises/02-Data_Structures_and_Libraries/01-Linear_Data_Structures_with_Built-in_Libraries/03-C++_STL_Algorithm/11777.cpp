#include <bits/stdc++.h>

using namespace std;

int tc, t1, t2, f, a, c[5], total;

int main(){
   scanf("%d", &tc);
   for(int t = 1; t <= tc; t++){
      scanf("%d %d %d %d %d %d %d", &t1, &t2, &f, &a, &c[0], &c[1], &c[2]);
      sort(c, c + 3);
      total = t1 + t2 + f + a + (c[1] + c[2]) / 2;
      printf("Case %d: ", t);
      if(total >= 90) puts("A");
      else if(total >= 80) puts("B");
      else if(total >= 70) puts("C");
      else if(total >= 60) puts("D");
      else puts("F");
   }
   return(0);
}
