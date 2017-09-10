#include <bits/stdc++.h>

#define SIZE 100

using namespace std;

int N;
char grid[SIZE][SIZE], contour, _max;
int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};
bool vis[SIZE][SIZE];
map < char, int > v;

inline bool is_possible(int R, int C){
   return ( 0 <= R and 0 <= C and R < N and grid[R][C] and not vis[R][C] );
}

void floodfill(int r, int c, char ch){
   if( not is_possible(r, c) ) return;
   if( grid[r][c] == contour ) return;
   grid[r][c] = ch;
   vis[r][c] = true;
   for(int d = 0; d < 4; d++)
      floodfill(r + dr[d], c + dc[d], ch);
}

int count(char ch){
   if( v[ch] != 0 ) return v[ch];
   int ct = 0;
   for(int row = 0; row < N; row++)
      for(int col = 0; grid[row][col]; col++)
         if( grid[row][col] == ch )
            ct++;
   return v[ch] = ct;
}

void findContourCharacter(){
   _max = 0;
   for(int row = 0; row < N; row++)
      for(int col = 0; grid[row][col]; col++)
         if( grid[row][col] != ' ' and grid[row][col] != '_' and count(grid[row][col]) > _max )
            _max = count(grid[row][col]), contour = grid[row][col];
}

void solve(){
   v.clear();
   memset(vis, false, sizeof vis);
   findContourCharacter();
   for(int row = 0; row < N; row++)
      for(int col = 0; grid[row][col]; col++)
         if( not vis[row][col] and grid[row][col] != ' ' and grid[row][col] != '_' and grid[row][col] != contour )
            floodfill(row, col, grid[row][col]);
   for(int row = 0; row <= N; row++)
      printf("%s\n", grid[row]);
   N = 0;
}

int main(){
   while(cin.getline(grid[N], SIZE)){
      if( grid[N][0] == '_' ) solve();
      else N++;
   }
   return(0);
}
