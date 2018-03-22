#include <bits/stdc++.h>

#define SIZE 60

using namespace std;

struct Point{
   char ch;
   int ct;
   Point(char _ch, int _ct):
      ch(_ch), ct(_ct) {}
   bool operator < ( const Point& other) const{
      if( ct != other.ct ) return ( ct > other.ct );
      return ( ch < other.ch );
   }
};

int tc, N, M;
char grid[SIZE][SIZE], ch;
vector < Point > ans;
int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};

inline bool is_possible(int R, int C){
   return ( 0 <= R and 0 <= C and R < N and C < M );
}

int floodfill(int r, int c){
   if( not is_possible(r, c) ) return 0;
   if( grid[r][c] != ch ) return 0;
   grid[r][c] = '.';
   int ct = 1;
   for(int d = 0; d < 4; d++)
      ct += floodfill(r + dr[d], c + dc[d]);
   return ct;
}

int main(){
   while(scanf("%d %d\n", &N, &M), N | M){
      ans.clear();
      for(int row = 0; row < N; row++) scanf("%s", grid[row]);
      for(int row = 0; row < N; row++)
         for(int col = 0; col < M; col++)
            if( grid[row][col] != '.' ){
               ch = grid[row][col];
               ans.push_back( Point( ch, floodfill(row, col)) );
            }
      sort(ans.begin(), ans.end());
      printf("Problem %d:\n", ++tc);
      for(int it = 0; it < ans.size(); it++)
         printf("%c %d\n", ans[it].ch, ans[it].ct);
   }
   return(0);
}
