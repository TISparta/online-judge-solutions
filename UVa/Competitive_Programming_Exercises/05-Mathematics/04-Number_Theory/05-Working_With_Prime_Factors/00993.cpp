#include <bits/stdc++.h>

using namespace std;

int tc, N;

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%d", &N);
      if ( N == 0 ){
         puts("0");
         continue;
      }
      if ( N == 1 ){
         puts("1");
         continue;
      }
      vector<int> Factors;
      for(int it = 9; it > 1; it--)
         while( N % it == 0 ) Factors.push_back( it ), N /= it;
      if ( N != 1 ) puts("-1");
      else
         for(int it = Factors.size() - 1; it >= 0; it--)
            printf(it != 0 ? "%d" : "%d\n", Factors[it]);
   }
   return(0);
}
