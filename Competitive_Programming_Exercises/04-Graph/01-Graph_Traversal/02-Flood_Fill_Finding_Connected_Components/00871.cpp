#include <bits/stdc++.h>

#define SIZE 30

using namespace std;

int tc, N, M, ans;
char line[SIZE], grid[SIZE][SIZE];
int dr[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dc[] = {1, 1, 0, -1, -1, -1, 0, 1};

inline bool is_possible(int R, int C){
   return ( 0 <= R and 0 <= C and R < N and C < M );
}

int floodfill(int r, int c){
   if( not is_possible(r, c) ) return 0;
   if( grid[r][c] != '1' ) return 0;
   grid[r][c] = '.';
   int ct = 1;
   for(int d = 0; d < 8; d++)
      ct += floodfill(r + dr[d], c + dc[d]);
   return ct;
}

void solve(){
   ans = 0;
   for(int row = 0; row < N; row++)
      for(int col = 0; col < M; col++)
         if( grid[row][col] == '1' )
            ans = max(ans, floodfill(row, col));
   printf("%d\n", ans);
}

int main(){
   scanf("%d\n", &tc);
   while(tc--){
      N = 0;
      while(cin.getline(line, SIZE)){
         if( sscanf(line, "%s", grid[N]) == -1 ) break;
         N++;
      }
      M = strlen(grid[0]);
      solve();
      if(tc) putchar('\n');
   }
   return(0);
}
