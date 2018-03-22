#include <bits/stdc++.h>

#define SIZE 15

using namespace std;

int tc, black, white;
char grid[SIZE][SIZE];
bool vis1[SIZE][SIZE], vis2[SIZE][SIZE];
int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};
const int N = 9;

inline bool is_possible(int R, int C){
   return ( 0 <= R and 0 <= C and R < N and C < N );
}

int floodfill1(int r, int c){
   if( not is_possible(r, c) or vis1[r][c] ) return 0;
   if( grid[r][c] == 'O' ) return 0;
   vis1[r][c] = true;
   int ct = 1;
   for(int d = 0; d < 4; d++)
      ct += floodfill1(r + dr[d], c + dc[d]);
   return ct;
}

int floodfill2(int r, int c){
   if( not is_possible(r, c) or vis2[r][c] ) return 0;
   if( grid[r][c] == 'X' ) return 0;
   vis2[r][c] = true;
   int ct = 1;
   for(int d = 0; d < 4; d++)
      ct += floodfill2(r + dr[d], c + dc[d]);
   return ct;
}

int main(){
   scanf("%d\n", &tc);
   while(tc--){
      memset(vis1, false, sizeof vis1);
      memset(vis2, false, sizeof vis2);
      black = white = 0;
      for(int row = 0; row < N; row++) scanf("%s", grid[row]);
      for(int row = 0; row < N; row++)
         for(int col = 0; col < N; col++)
            if( grid[row][col] == 'X' )
               black += floodfill1(row, col);
            else if( grid[row][col] == 'O' )
               white += floodfill2(row, col);
      for(int row = 0; row < N; row++)
         for(int col = 0; col < N; col++)
            if( vis1[row][col] and vis2[row][col] )
               black--, white--;
      printf("Black %d White %d\n", black, white);
   }
   return(0);
}
