#include <bits/stdc++.h>

#define SIZE 110

using namespace std;

int tc, N, ans;
char grid[SIZE][SIZE];
int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};

inline bool is_possible(int R, int C){
   return ( 0 <= R and 0 <= C and R < N and C < N );
}

void floodfill(int r, int c){
   if( not is_possible(r, c) ) return;
   if( grid[r][c] == '.' ) return;
   grid[r][c] = '.';
   for(int d = 0; d < 4; d++)
      floodfill(r + dr[d], c + dc[d]);
}

int solve(){
   ans = 0;
   for(int row = 0; row < N; row++)
      for(int col = 0; col < N; col++)
         if( grid[row][col] == 'x' )
            floodfill(row, col), ans++;
   return ans;
}

int main(){
   scanf("%d", &tc);
   for(int t = 1; t <= tc; t++){
      scanf("%d\n", &N);
      for(int row = 0; row < N; row++) scanf("%s", grid[row]);
      printf("Case %d: %d\n", t, solve());
   }
   return(0);
}
