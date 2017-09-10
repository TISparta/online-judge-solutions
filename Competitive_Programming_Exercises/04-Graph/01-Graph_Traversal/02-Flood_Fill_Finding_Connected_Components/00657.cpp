#include <bits/stdc++.h>

#define SIZE 55

using namespace std;

int tc, N, M, CC;
char grid[SIZE][SIZE];
bool vis[SIZE][SIZE];
vector <int> ans;
vector < pair <int, int> > pos;
int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};

inline bool is_possible(int R, int C){
   return ( 0 <= R and 0 <= C and R < N and C < M and grid[R][C] != '.' );
}

void floodfill(int r, int c, char ch1, char ch2){
   vis[r][c] = true;
   grid[r][c] = ch2;
   if( grid[r][c] == 'w' ) pos.push_back( make_pair(r, c) );
   for(int d = 0; d < 4; d++){
      int nr = r + dr[d], nc = c + dc[d];
      if( is_possible(nr, nc) and not vis[nr][nc]){
         if( grid[nr][nc] == 'X' ) floodfill(nr, nc, 'X', 'w');
         else floodfill(nr, nc, grid[nr][nc], '.');
      }
   }
}

int main(){
   while(scanf("%d %d\n", &M, &N), N | M){
      memset(vis, false, sizeof vis);
      ans.clear();
      for(int row = 0; row < N; row++) scanf("%s", grid[row]);
      for(int row = 0; row < N; row++)
         for(int col = 0; col < M; col++)
            if( grid[row][col] == 'X' ){
               CC = 0;
               pos.clear();
               floodfill(row, col, 'X', 'w');
               for(int it = 0; it < pos.size(); it++) vis[pos[it].first][pos[it].second] = false;
               for(int it = 0; it < pos.size(); it++)
                  if( grid[pos[it].first][pos[it].second] == 'w' )
                     floodfill(pos[it].first, pos[it].second, 'w', '.'), CC++;
               ans.push_back(CC);
            }
      sort(ans.begin(), ans.end());
      printf("Throw %d\n", ++tc);
      for(int it = 0; it < ans.size(); it++)
         printf( it != ans.size() - 1 ? "%d " : "%d\n\n", ans[it]);
   }
   return(0);
}
