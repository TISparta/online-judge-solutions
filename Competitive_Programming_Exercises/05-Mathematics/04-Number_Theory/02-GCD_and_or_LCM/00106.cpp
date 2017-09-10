#include <bits/stdc++.h>

#define SIZE 1000010

using namespace std;

int N, ans1, ans2, x, y, z;
bool v[SIZE];

int gcd(int a, int b){
   return b == 0 ? a : gcd(b, a % b);
}

int main(){
   while(scanf("%d", &N)==1){
      ans1 = ans2 = 0;
      memset(v, false, sizeof v);
      for(int m = 1; m * m < N; m++)
         for(int n = 1; n < m and n * n + m * m <= N; n++)
            if(gcd(m, n) == 1){
               x = 2 * m * n;
               y = m * m - n * n;
               z = m * m + n * n;
               if( gcd(x, z) == 1 ) ans1++;
               for(int d = 1; d * z <= N; d++){
                  v[d * z] = v[d * y] = v[d * x] = true;
               }
            }
      for(int it = 1; it <= N; it++) if(v[it] == false) ans2++;
      printf("%d %d\n", ans1, ans2);
   }
   return(0);
}
