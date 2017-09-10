#include <bits/stdc++.h>

using namespace std;

const int LIM = 100010;

int num, ct, L, H, dp[LIM];
bool first = true;

int ssd(int n){
   int sum = 0;
   while(n) sum += ( n % 10 ) * ( n % 10 ), n /= 10;
   return sum;
}

int main(){
   dp[1] = 1;
   for(int it = 2; it < LIM; it++){
      num = it, ct = 0;
      set <int> vis;
      while(true){
         if( dp[num] ){
            dp[it] = ct + dp[num];
            break;
         }
         if( vis.find( num ) != vis.end() ){
            break;
         }
         vis.insert(num);
         num = ssd(num);
         ct++;
      }
   }
   while(~scanf("%d %d", &L, &H)){
      if( not first ) putchar('\n');
      first = false;
      for(int it = L; it <= H; it++)
         if( dp[it] ) printf("%d %d\n", it, dp[it]);
   }
   return(0);
}
