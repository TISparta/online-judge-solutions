#include <bits/stdc++.h>

#define SIZE 210

using namespace std;

int tc, N;
char grid[SIZE][SIZE];
bool ok;
int dr[] = {-1, -1, 0, 0, 1, 1};
int dc[] = {-1, 0, -1, 1, 0, 1};

inline bool is_possible(int R, int C){
   return ( 0 <= R and 0 <= C and R < N and C < N );
}

void floodfill(int r, int c, char ch1, char ch2){
   if( not is_possible(r, c) ) return;
   if(grid[r][c] == 'w') return;
   if( r == N - 1 ) ok = true;
   grid[r][c] = 'w';
   for(int d = 0; not ok and d < 6; d++)
      floodfill(r + dr[d], c + dc[d], ch1, ch2);
}

int main(){
   while(scanf("%d\n", &N), N){
      for(int row = 0; row < N; row++) scanf("%s", grid[row]);
      ok = false;
      for(int col = 0; col < N; col++)
         floodfill(0, col, 'b', 'w');
      if( ok ) printf("%d B\n", ++tc);
      else printf("%d W\n", ++tc);
   }
   return(0);
}
