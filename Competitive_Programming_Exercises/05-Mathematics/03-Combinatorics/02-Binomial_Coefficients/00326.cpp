#include <bits/stdc++.h>

using namespace std;

const int SIZE = 12;

int n, k;
long long num, den, C, Tk, dif[SIZE][SIZE];

int main(){
   while(scanf("%d", &n), n){
      for(int j = 0; j < n; j++) scanf("%lld", &dif[0][j]);
      for(int i = 1; i < n; i++)
         for(int j = 0; j < n - i; j++)
            dif[i][j] = dif[i - 1][j + 1] - dif[i - 1][j];
      scanf("%d", &k);
      k += n;
      C = 1, num = k - 1, den = 1;
      Tk = 0;
      for(int i = 0; i < n; i++)
         Tk += C * dif[i][0], C = C * num-- / den++;
      printf("Term %d of the sequence is %lld\n", k, Tk);
   }
   return(0);
}
