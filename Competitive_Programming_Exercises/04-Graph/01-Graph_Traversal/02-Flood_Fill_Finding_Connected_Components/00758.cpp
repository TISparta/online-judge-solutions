#include <bits/stdc++.h>

#define SIZE 20
#define LIM 80

using namespace std;

int tc, moves, posr[LIM], posc[LIM], balls[LIM], points[LIM], score, remainder_;
char grid[SIZE][SIZE], color[LIM];
bool vis[SIZE][SIZE];
int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};
const int N = 10, M = 15;

inline bool is_possible(int R, int C){
   return ( 0 <= R and 0 <= C and R < N and C < M );
}

int floodfill(int r, int c, char ch1, char ch2){
   grid[r][c] = ch2;
   vis[r][c] = true;
   int ct = 1;
   for(int d = 0; d < 4; d++){
      int nr = r + dr[d], nc = c + dc[d];
      if( is_possible(nr, nc) and grid[nr][nc] == ch1 and not vis[nr][nc])
         ct += floodfill(nr, nc, ch1, ch2);
   }
   return ct;
}

int Count(int r, int c){
   int ct = 1;
   for(int d = 0; d < 4; d++)
      if( is_possible(r + dr[d], c + dc[d]) and grid[r + dr[d]][c + dc[d]] == grid[r][c] )
         ct++;
   return ct;
}

bool solved(){
   remainder_ = 0;
   for(int row = 0; row < N; row++)
      for(int col = 0; col < M; col++)
         if( grid[row][col] == '.' ) continue;
         else if( Count(row, col) != 1 ) return false;
         else remainder_++;
   if( remainder_ == 0 ) score += 1000;
   return true;
}

bool Is_empty(int c){
   for(int row = 0; row < N; row++)
      if( grid[row][c] != '.' ) return false;
   return true;
}

void swap_columns(int c1, int c2){
   for(int row = 0; row < N; row++)
      swap( grid[row][c1], grid[row][c2] );
}

void shiftColumns(){
   for(int row = N - 1; row >= 0; row--)
      for(int col = 0; col < M; col++)
         if( grid[row][col] == '.' ){
            for(int r = row - 1; r >= 0; r--)
               if( grid[r][col] != '.' ) swap(grid[row][col], grid[r][col]), r = 0;
         }
}

void shiftRows(){
   for(int col = 0; col < M; col++)
      if( Is_empty(col) ){
         for(int c = col + 1; c < M; c++)
            if( not Is_empty(c) )
               swap_columns(col, c), c = M;
      }
}

void modifyGrid(){
   shiftColumns();
   shiftRows();
}

void solve(){
   while( not solved() ){
      memset(vis, false, sizeof vis);
      int _balls = 0, _posr, _posc;
      char _color;
      for(int col = 0; col < M; col++)
         for(int row = N - 1; row >= 0; row--)
            if( not vis[row][col] and grid[row][col] != '.' and Count(row, col) >= 2 ){
               int CC = floodfill(row, col, grid[row][col], grid[row][col]);
               if( CC > _balls ) _balls = CC, _posr = row, _posc = col, _color = grid[row][col];
            }
      posr[moves] = _posr, posc[moves] = _posc, balls[moves] = _balls, color[moves] = _color;
      points[moves] = ( _balls - 2 ) * ( _balls - 2 ), score += points[moves++];
      memset(vis, false, sizeof vis);
      floodfill(_posr, _posc, _color, '.');
      modifyGrid();
   }
}

void printSolution(int t){
   if( t != 1 ) putchar('\n');
   printf("Game %d:\n\n", t);
   for(int it = 0; it < moves; it++)
      printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n", it + 1, 10 - posr[it], 1 + posc[it], balls[it], color[it], points[it]);
   printf("Final score: %d, with %d balls remaining.\n", score, remainder_);
}

inline void clear_(){
   moves = score = remainder_ = 0;
}

int main(){
   scanf("%d", &tc);
   for(int t = 1; t <= tc; t++){
      clear_();
      getchar();
      for(int row = 0; row < N; row++) scanf("%s", grid[row]);
      solve();
      printSolution(t);
      clear_();
   }
   return(0);
}
