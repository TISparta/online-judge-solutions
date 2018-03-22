#include <bits/stdc++.h>

using namespace std;

int tc, N, S, s, z;

int main(){
   scanf("%d", &tc);
   while(tc--){
      S = INT_MAX;
      scanf("%d", &N);
      for(int x = 1; x <= N; x++)
         for(int y = 1; y <= sqrt(N); y++)
            if(N % (x * y) == 0){
               z = N / (x * y);
               s = 2 * (x * y + y * z + x * z);
               if(s < S) S = s;
            }
      printf("%d\n", S);
   }
   return(0);
}
