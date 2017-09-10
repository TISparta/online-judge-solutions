#include <bits/stdc++.h>

#define SIZE 100

using namespace std;

int tc, N, M, len;
char grid[SIZE][SIZE];
int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};
bool vis[SIZE][SIZE];

inline bool is_possible(int R, int C){
   return ( 0 <= R and 0 <= C and R < N and C < M );
}

void floodfill(int r, int c){
   grid[r][c] = ' ';
   vis[r][c] = true;
   for(int d = 0; d < 4; d++){
      int row = r + dr[d], col = c + dc[d];
      if( is_possible(row, col) and not vis[row][col]){
         if( grid[row][col] == 'X' )
            grid[r][c] = '#';
         else
            floodfill(row, col);
      }
   }
}

void solve(){
   memset(vis, false, sizeof vis);
   M++;
   for(int row = 0; row < N; row++){
      len = strlen(grid[row]);
      while( len != M ) grid[row][len++] = ' ';
      grid[row][len] = '\0';
   }   
   for(int row = 0; row < N; row++)
      for(int col = 0; col < M; col++)
         if( grid[row][col] == '*' )
            floodfill(row, col), row = N, col = M;
   for(int row = 0; row <= N; row++){
      len = strlen(grid[row]) - 1;
      while( grid[row][len] == ' ' ) grid[row][len--] = '\0';
   }
   for(int row = 0; row <= N; row++)
      printf("%s\n", grid[row]);
}

int main(){
   scanf("%d", &tc); getchar();
   while(tc--){
      N = M = 0;
      while(cin.getline(grid[N], SIZE)){
         if( grid[N][0] == '_' ) break;
         M = max(M, (int) strlen(grid[N]));
         N++;
      }
      solve();
   }
   return(0);
}
