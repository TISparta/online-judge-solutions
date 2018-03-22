#include <bits/stdc++.h>

#define SIZE 110
#define LIM 1000

using namespace std;

int n, r, c, ct, grid[SIZE][SIZE], CC;
char line[LIM], *p;
bool ok;
int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};

inline bool is_possible(int R, int C){
   return ( 0 <= R and 0 <= C and R < n and C < n );
}

void floodfill(int r, int c, int p){
   if( not is_possible(r, c) ) return;
   if( grid[r][c] != p ) return;
   grid[r][c] = -1;
   for(int d = 0; d < 4; d++)
      floodfill(r + dr[d], c + dc[d], p);
}
int main(){
   while(scanf("%d\n", &n), n){
      CC = 0, ok = true;
      memset(grid, 0, sizeof grid);
      for(int it1 = 1; it1 < n; it1++){
         ct = 0;
         cin.getline(line, LIM);
         p = strtok(line, " ");
         while(p){
            r = atoi(p);
            p = strtok(NULL, " ");
            c = atoi(p);
            p = strtok(NULL, " ");
            if( grid[r - 1][c - 1] == 0 ) ct++;
            grid[r - 1][c - 1] = it1;
         }
         if( ct != n ) ok = false;
      }
      for(int row = 0; ok and row < n; row++)
         for(int col = 0; col < n; col++)
            if( grid[row][col] != -1 )
               floodfill(row, col, grid[row][col]), CC++;
      puts( ok and CC == n ? "good" : "wrong" );
   }
   return(0);
}
