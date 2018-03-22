#include <bits/stdc++.h>

#define SIZE 1010

using namespace std;

int N, M, ct, ans[SIZE][SIZE], sep[SIZE];
char grid[SIZE][SIZE];
int dr[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dc[] = {1, 1, 0, -1, -1, -1, 0, 1};

inline bool is_possible(int R, int C){
   return ( 0 <= R and 0 <= C and R < N and C < M );
}

void floodfill(int r, int c, char ch){
   if( not is_possible(r, c) ) return;
   if( grid[r][c] != ch ) return;
   grid[r][c] = '.';
   ans[r][c] = ct;
   for(int d = 0; d < 8; d++)
      floodfill(r + dr[d], c + 2 * dc[d], ch);
}

void solve(){
   M = strlen(grid[0]);
   ct = 1;
   for(int row = 0; row < N; row++)
      for(int col = 0; col < M; col += 2)
         if( grid[row][col] != '.' )
            floodfill(row, col, grid[row][col]), ct++;
   memset(sep, 0, sizeof sep);
   for(int row = 0; row < N; row++)
      for(int col = 0; col < M; col += 2)
         if( ans[row][col] < 10 ) sep[col] = max(sep[col], 1);
         else if( ans[row][col] < 100 ) sep[col] = max(sep[col], 2);
         else if( ans[row][col] < 1000 ) sep[col] = max(sep[col], 3);
         else sep[col] = 4;
   for(int row = 0; row < N; row++)
      for(int col = 0; col < M; col += 2)
         printf( col != M - 1 ? "%*d " : "%*d\n", sep[col], ans[row][col]);
   puts("%");
   N = 0;
}

int main(){
   while(cin.getline(grid[N], SIZE)){
      if( grid[N][0] == '%' ) solve();
      else N++;
   }
   solve();
   return(0);
}
