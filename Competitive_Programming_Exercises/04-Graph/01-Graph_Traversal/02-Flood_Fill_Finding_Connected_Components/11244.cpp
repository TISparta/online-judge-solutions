#include <bits/stdc++.h>

#define SIZE 110

using namespace std;

int n, m, ans;
char grid[SIZE][SIZE];
int dr[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dc[] = {1, 1, 0, -1, -1, -1, 0, 1};

inline bool is_possible(int R, int C){
   return ( 0 <= R and 0 <= C and R < n and C < m );
}

int floodfill(int r, int c){
   if( not is_possible(r, c) ) return 0;
   if( grid[r][c] == '.' ) return 0;
   grid[r][c] = '.';
   int ct = 1;
   for(int d = 0; d < 8; d++)
      ct += floodfill(r + dr[d], c + dc[d]);
   return ct;
}

int main(){
   while(scanf("%d %d\n", &n, &m), n | m ){
      ans = 0;
      for(int row = 0; row < n; row++) scanf("%s", grid[row]);
      for(int row = 0; row < n; row++)
         for(int col = 0; col < m; col++)
            if( grid[row][col] == '*' and floodfill(row, col) == 1 )
               ans++;
      printf("%d\n", ans);
   }
   return(0);
}
