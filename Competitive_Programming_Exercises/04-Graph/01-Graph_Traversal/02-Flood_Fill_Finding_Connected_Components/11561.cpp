#include <bits/stdc++.h>

#define SIZE 60

using namespace std;

int n, m;
char grid[SIZE][SIZE];
bool vis[SIZE][SIZE];
pair <int, int> P;
int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};

inline bool is_possible(int R, int C){
   return ( 1 <= R and 1 <= C and R < n and C < m and grid[R][C] != '#' and grid[R][C] != 'T' );
}

bool is_safe(int R, int C){
   for(int d = 0; d < 4; d++)
      if( grid[R + dr[d]][C + dc[d]] == 'T' ) return false;
   return true;
}

int floodfill(int r, int c){
   grid[r][c] = '.';
   vis[r][c] = true;
   if( not is_safe(r, c) ) return 0;
   int ct = 0;
   for(int d = 0; d < 4; d++){
      int row = r + dr[d], col = c + dc[d];
      if( is_possible(row, col) and not vis[row][col] ){
         if( grid[row][col] == 'G' ) ct++;
         ct += floodfill(row, col);
      }
   }
   return ct;
}

pair <int, int> findInitialPosition(){
   for(int row = 1; row < n; row++)
      for(int col = 1; col < m; col++)
         if( grid[row][col] == 'P' )
            return make_pair(row, col);
}

int main(){
   while(~scanf("%d %d\n", &m, &n)){
      memset(vis, false, sizeof vis);
      for(int row = 0; row < n; row++) scanf("%s", grid[row]);
      n--, m--;
      P = findInitialPosition();
      printf("%d\n", floodfill(P.first, P.second));
   }
   return(0);
}
