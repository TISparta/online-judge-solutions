#include <bits/stdc++.h>

#define SIZE 1000
#define LIM 30

using namespace std;

struct State{
   int ct;
   char name;
   State(int _ct, char _name):
      ct(_ct), name(_name) {};
   bool operator < ( const State& other) const{
      if( name != other.name ) return ( ct > other.ct );
      return ( name < other.name );
   }
};

int tc, n, m, v[LIM];
char grid[SIZE][SIZE];
int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};

inline bool is_possible(int R, int C){
   return ( 0 <= R and 0 <= C and R < n and C < m );
}

void floodfill(int r, int c, char ch){
   if( not is_possible(r, c) ) return;
   if( grid[r][c] != ch ) return;
   grid[r][c] = '.';
   for(int d = 0; d < 4; d++)
      floodfill(r + dr[d], c + dc[d], ch);
}

void solve(int t){
   memset(v, 0, sizeof v);
   for(int row = 0; row < n; row++)
      for(int col = 0; col < m; col++)
         if( grid[row][col] != '.' )
            v[grid[row][col] - 'a']++, floodfill(row, col, grid[row][col]);
   vector < State > ans;
   for(int it = 0; it < LIM; it++)
      if( v[it] ) ans.push_back( State( v[it], it + 'a' ) );
   sort(ans.begin(), ans.end());
   printf("World #%d\n", t);
   for(int it = 0; it < ans.size(); it++)
      printf("%c: %d\n", ans[it].name, ans[it].ct);
}

int main(){
   scanf("%d", &tc);
   for(int t = 1; t <= tc; t++){
      scanf("%d %d\n", &n, &m);
      for(int row = 0; row < n; row++) scanf("%s", grid[row]);
      solve(t);
   }
   return(0);
}
