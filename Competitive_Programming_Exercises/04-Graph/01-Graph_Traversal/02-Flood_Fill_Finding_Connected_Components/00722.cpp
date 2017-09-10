#include <bits/stdc++.h>

#define SIZE 110

using namespace std;

int tc, N, M, row, col;
char line[SIZE], grid[SIZE][SIZE];
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

inline bool is_possible(int R, int C){
   return ( 0 <= R and 0 <= C and R < N and C < M );
}

int floodfill(int r, int c){
   if( not is_possible(r, c) ) return 0;
   if( grid[r][c] == '1' ) return 0;
   grid[r][c] = '1';
   int ans = 1;
   for(int d = 0; d < 4; d++)
      ans += floodfill(r + dr[d], c + dc[d]);
   return ans;
}

int main(){
   scanf("%d\n", &tc);
   while(tc--){
      cin.getline(line, SIZE);
      sscanf(line, "%d %d", &row, &col);
      N = 0;
      while(cin.getline(line, SIZE)){
         if( sscanf(line, "%s", grid[N]) == -1 ) break;
         N++;
      }
      M = strlen(grid[0]);
      printf("%d\n", floodfill(row - 1, col - 1));
      if( tc ) putchar('\n');
   }
   return(0);
}
