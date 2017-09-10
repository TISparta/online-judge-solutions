#include <bits/stdc++.h>

#define SIZE 30

using namespace std;

int tc, N, CC;
char grid[SIZE][SIZE];
int dr[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dc[] = {1, 1, 0, -1, -1, -1, 0, 1};

inline bool is_possible(int R, int C){
   return ( 0 <= R and 0 <= C and R < N and C < N );
}

void floodfill(int r, int c){
   if( not is_possible(r, c) ) return;
   if( grid[r][c] == '0' ) return;
   grid[r][c] = '0';
   for(int d = 0; d < 8; d++)
      floodfill(r + dr[d], c + dc[d]);
}

int main(){
   while(~scanf("%d\n", &N)){
      CC = 0;
      for(int row = 0; row < N; row++) scanf("%s", grid[row]);
      for(int row = 0; row < N; row++)
         for(int col = 0; col < N; col++)
            if( grid[row][col] == '1' )
               floodfill(row, col), CC++;
      printf("Image number %d contains %d war eagles.\n", ++tc, CC);
   }
   return(0);
}
