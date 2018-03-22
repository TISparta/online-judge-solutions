#include <bits/stdc++.h>

#define SIZE 110

using namespace std;

int n, m, CC;
char grid[SIZE][SIZE];
int dr[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dc[] = {1, 1, 0, -1, -1, -1, 0, 1};

inline bool is_possible(int R, int C){
   return ( 0 <= R and 0 <= C and R < n and C < m );
}

void floodfill(int r, int c){
   if( not is_possible(r, c) ) return;
   if( grid[r][c] == '*' ) return;
   grid[r][c] = '*';
   for(int d = 0; d < 8; d++)
      floodfill(r + dr[d], c + dc[d]);
}

int main(){
   while(scanf("%d %d\n", &n, &m), n | m){
      CC = 0;
      for(int row = 0; row < n; row++) scanf("%s", grid[row]);
      for(int row = 0; row < n; row++)
         for(int col = 0; col < m; col++)
            if( grid[row][col] == '@' )
               floodfill(row, col), CC++;
      printf("%d\n", CC);
   }
   return(0);
}
