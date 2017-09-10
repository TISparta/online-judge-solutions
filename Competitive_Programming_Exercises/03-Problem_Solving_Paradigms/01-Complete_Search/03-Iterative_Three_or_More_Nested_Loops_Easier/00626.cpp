#include <bits/stdc++.h>

using namespace std;

int n, m[100][100], ct;

int main(){
   while(scanf("%d", &n) == 1){
      ct = 0;
      for(int i = 0; i < n; i++)
         for(int j = 0; j < n; j++)
            scanf("%d", &m[i][j]);
      for(int a = 0; a < n; a++)
         for(int b = 0; b < n; b++)
            for(int c = 0; c < n; c++)
               if( ( ( a < b && b < c ) ||
                   ( a > b && b > c ) ) &&
                   ( m[a][b] && m[b][c] && m[c][a] ) )
                  printf("%d %d %d\n", a + 1, b + 1, c + 1), ct++;
      printf("total:%d\n\n", ct);
   }
   return(0);
}
