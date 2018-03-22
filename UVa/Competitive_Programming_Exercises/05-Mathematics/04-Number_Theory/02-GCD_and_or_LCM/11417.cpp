#include <bits/stdc++.h>

using namespace std;

int N, G;

int gcd(int a, int b){
   return b == 0 ? a : gcd(b, a % b);
}

int main(){
   while(scanf("%d", &N), N){
      G = 0;
      for(int it1 = 1; it1 < N; it1++)
         for(int it2 = it1 + 1; it2 <= N; it2++)
            G += gcd(it1, it2);
      printf("%d\n", G);
   }
   return(0);
}
