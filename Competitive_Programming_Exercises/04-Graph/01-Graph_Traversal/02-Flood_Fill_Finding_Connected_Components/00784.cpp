#include <bits/stdc++.h>

#define SIZE 100

using namespace std;

int tc, N, M;
char grid[SIZE][SIZE];
int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};

inline bool is_possible(int R, int C){
   return ( 0 <= R and 0 <= C and R < N and C < M );
}

void floodfill(int r, int c){
   if( not is_possible(r, c) ) return;
   if( grid[r][c] != ' ' ) return;
   grid[r][c] = '#';
   for(int d = 0; d < 4; d++)
      floodfill(r + dr[d], c + dc[d]);
}

void solve(){
   for(int row = 0; row < N; row++)
      for(int col = 0; col < M; col++)
         if( grid[row][col] == '*' )
            grid[row][col] = ' ', floodfill(row, col), row = N, col = M;
   for(int row = 0; row <= N; row++)
      printf("%s\n", grid[row]);
}

int main(){
   scanf("%d\n", &tc);
   while(tc--){
      N = M = 0;
      while(cin.getline(grid[N], SIZE)){
         if( grid[N][0] == '_' ) break;
         else N++;
      }
      M = strlen(grid[0]);
      solve();
   }
   return(0);
}
