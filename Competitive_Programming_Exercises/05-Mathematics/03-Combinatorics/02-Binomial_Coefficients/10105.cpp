#include <bits/stdc++.h>

using namespace std;

const int SIZE = 15;

int N, K, ni;
long long ans, F[SIZE];

void Factorial(){
   F[0] = 1;
   for(int i = 1; i < SIZE; i++) F[i] = i * F[i - 1];
}

int main(){
   Factorial();
   while(~scanf("%d %d", &N, &K)){
      ans = F[N];
      for(int i = 0; i < K; i++){
         scanf("%d", &ni);
         ans /= F[ni];
      }
      printf("%lld\n", ans);
   }
   return(0);
}
