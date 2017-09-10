#include <bits/stdc++.h>

#define SIZE 25

using namespace std;

int N, M, rpos, cpos, ans;
char grid[SIZE][SIZE], ch1, ch2;
int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};

int floodfill(int r, int c){
   if( grid[r][c] == ch2 ) return 0;
   grid[r][c] = ch2;
   int ct = 1;
   for(int d = 0; d < 4; d++)
      if( 0 <= r + dr[d] and r + dr[d] < N )
         ct += floodfill( r + dr[d], ( c + dc[d] + M ) % M);
   return ct;
}

char WaterRepresentation(){
   for(int row = 0; row < N; row++)
      for(int col = 0; col < M; col++)
         if( grid[row][col] != ch1 ) return grid[row][col];
   return '*';
}

int main(){
   while(~scanf("%d %d\n", &N, &M)){
      ans = 0;
      for(int row = 0; row < N; row++) scanf("%s", grid[row]);
      scanf("%d %d", &rpos, &cpos);
      ch1 = grid[rpos][cpos];
      ch2 = WaterRepresentation();
      floodfill(rpos, cpos);
      for(int row = 0; row < N; row++)
         for(int col = 0; col < M; col++)
            if( grid[row][col] == ch1 )
               ans = max(ans, floodfill(row, col));
      printf("%d\n", ans);
   }
   return(0);
}
