#include <bits/stdc++.h>

using namespace std;

const int SIZE = 105;

int n, m;
long long C[SIZE][SIZE];

void BinomialCoef(){
   for(int i = 0; i < SIZE; i++) C[i][0] = C[i][i] = 1;
   for(int i = 2; i < SIZE; i++)
      for(int k = 1; k < i; k++)
         C[i][k] = C[i - 1][k] + C[i - 1][k - 1];
}

int main(){
   BinomialCoef();
   while(scanf("%d %d", &n, &m), n | m)
      printf("%d things taken %d at a time is %lld exactly.\n", n, m, C[n][m]);
   return(0);
}
