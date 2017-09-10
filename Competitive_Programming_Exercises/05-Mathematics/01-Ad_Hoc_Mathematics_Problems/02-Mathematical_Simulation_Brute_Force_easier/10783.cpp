#include <bits/stdc++.h>

using namespace std;

int main(){
   int c, a, b, t = 0, oddsum;
   scanf("%d", &c);
   while(c--){
      scanf("%d\n%d", &a, &b);
      oddsum = 0;
      for(int i = a; i <= b; i++)
         if(i & 1)
            oddsum += i;
      printf("Case %d: %d\n", ++t, oddsum);
   }
   return(0);
}
