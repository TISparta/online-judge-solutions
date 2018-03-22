#include <bits/stdc++.h>

using namespace std;

int main(){
   int ct, ans, tmp;
   long x, y, num;
   long long n;
   while(scanf("%ld %ld", &x, &y), x | y){
      ans = -1;
      if(x > y)
         swap(x, y);
      for(long i = x; i <= y; i++){
         ct = 0;
         n = i;
         if(n == 1)
            ct = 3;
         while(n != 1){
            ct++;
            if(n & 1)
               n = 3 * n + 1;
            else
               n /= 2;
         }
         if(ct > ans)
            ans = ct, num = i;
      }
      printf("Between %ld and %ld, %ld generates the longest sequence of %d values.\n", x, y, num, ans);
   }
   return(0);
}
