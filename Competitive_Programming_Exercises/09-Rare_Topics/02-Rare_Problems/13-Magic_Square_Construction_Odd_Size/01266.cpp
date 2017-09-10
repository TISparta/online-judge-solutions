#include <bits/stdc++.h>

using namespace std;

const int SIZE = 18;

int tc, N, r, c, it, grid[SIZE][SIZE], len;
int dr[] = {-1, 1};
int dc[] = {1, 0};

int main(){
   while(~scanf("%d", &N)){
      if(tc++) putchar('\n');
      memset(grid, 0, sizeof grid);
      r = 0, c = N / 2, it = 0;
      grid[r][c] = ++it;
      while( it < N * N ){
         int nr = ( r + dr[0] + N ) % N, nc = ( c + dc[0] ) % N; 
         if( grid[nr][nc] )
            nr = ( r + dr[1] ) % N, nc = ( c + dc[1] ) % N;
         grid[nr][nc] = ++it;
         r = nr, c = nc;
      }
      len = ceil( log10(N * N) );
      printf("n=%d, sum=%d\n", N, N * ( N * N + 1 ) / 2  );
      for(int row = 0; row < N; row++){
         for(int col = 0; col < N; col++)
            printf(" %*d", len, grid[row][col]);
         putchar('\n');
      }
   }
   return(0);
}
