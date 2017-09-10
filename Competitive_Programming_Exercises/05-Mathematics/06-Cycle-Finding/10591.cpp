#include <bits/stdc++.h>

using namespace std;

int tc, n;

int sumDigits(int N){
   int sum = 0;
   while(N) sum += ( N % 10 ) * ( N % 10 ), N /= 10;
   return sum;
}

bool Happy_Number(int N){
   set <int> vis;
   vis.insert(N);
   while( N != 1 ){
      N = sumDigits(N);
      if( vis.find(N) != vis.end() ) return false;
      vis.insert(N);
   }
   return true;
}

int main(){
   scanf("%d", &tc);
   for(int t = 1; t <= tc; t++){
      scanf("%d", &n);
      if( Happy_Number(n) ) printf("Case #%d: %d is a Happy number.\n", t, n);
      else printf("Case #%d: %d is an Unhappy number.\n", t, n);
   }
   return(0);
}
