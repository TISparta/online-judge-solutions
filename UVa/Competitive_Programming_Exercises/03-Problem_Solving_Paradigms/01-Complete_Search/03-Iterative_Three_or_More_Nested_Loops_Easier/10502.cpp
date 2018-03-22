#include <bits/stdc++.h>

using namespace std;

int m, n, ct, v[100][100];

inline bool isAllOne(int i, int j, int x, int y){
   for(int p = i; p <= x; p++)
      for(int q = j; q <= y; q++)
         if(!v[p][q]) return false;
   return true;
}

int main(){
   while(scanf("%d %d", &m, &n) == 2){
      ct = 0;
      for(int i = 0; i < m; i++)
         for(int j = 0; j < n; j++) scanf("%1d", &v[i][j]);
      for(int i = 0; i < m; i++)
         for(int j = 0; j < n; j++)
            for(int r1 = 0; r1 < n - j; r1++)
               for(int r2 = 0; r2 < m - i; r2++)
                  if(isAllOne(i, j, i + r2, j + r1)) ct++;
      printf("%d\n", ct);
   }
   return(0);
}
