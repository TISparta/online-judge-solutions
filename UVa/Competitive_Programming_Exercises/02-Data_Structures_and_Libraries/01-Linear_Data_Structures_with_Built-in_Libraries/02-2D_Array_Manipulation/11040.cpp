#include <bits/stdc++.h>

#define SIZE 15

using namespace std;

int tc, v[SIZE][SIZE];

void solve(int i,int j){
   if(v[i][j] != -1) return;
   if(v[i + 1][j] != -1 && v[i + 1][j + 1] == -1){
      v[i + 1][j + 1] = (v[i - 1][j] - v[i + 1][j] - v[i + 1][j + 2]) / 2;
      v[i][j] = v[i + 1][j] + v[i + 1][j + 1];
      v[i][j + 1] = v[i + 1][j + 1] + v[i + 1][j + 2];
      return;
   }
}

int main(){
   scanf("%d", &tc);
   while(tc--){
      memset(v, -1, sizeof v);
      for(int i = 1; i <= 5; i++)
         for(int j = 1; j <= i; j++)
            scanf("%d", &v[2 * i - 1][2 * j - 1]);
      for(int i = 2; i <= 8; i++)
         for(int j = 1; j <= i; j++)
            solve(i, j);
      for(int i = 1; i <= 9; i++)
         for(int j = 1; j <= i; j++)
            printf( j != i ? "%d " : "%d\n", v[i][j]);
   }
   return(0);
}
