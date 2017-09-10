#include <bits/stdc++.h>

#define SIZE 15
#define LIM 110

using namespace std;

int tc, n, lim, grid[SIZE][SIZE], dis[LIM], ans[SIZE];
int dr[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dc[] = {1, 1, 0, -1, -1, -1, 0, 1};

inline bool is_possible(int R, int C){
   return ( 0 <= R and 0 <= C and R < n and C < n );
}

void bfs(){
   fill(ans, ans + SIZE, 0);
   fill(dis, dis + LIM, -1);
   queue < int > Q;
   dis[ n / 2 * n +  n / 2 ] = 1;
   Q.push( n / 2 * n + n / 2 );
   if( n % 2 == 0 )
      for(int d = 2; d < 5; d++){
         int u = ( n / 2 + dr[d] ) * n + n / 2 + dc[d];
         dis[u] = 1;
         Q.push(u);
      }
   while( not Q.empty() ){
      int u = Q.front(); Q.pop();
      int r = u / n, c = u % n;
      ans[ dis[u] ] += grid[r][c];
      for(int d = 0; d < 8; d++){
         int row = r + dr[d], col = c + dc[d], v = row * n + col;
         if( not is_possible(row, col) ) continue;
         if( dis[v] == -1 )
            dis[v] = dis[u] + 1, Q.push(v);
      }
   }
}

int main(){
   while(scanf("%d", &n), n){
      for(int row = 0; row < n; row++)
         for(int col = 0; col < n; col++)
            scanf("%d", &grid[row][col]);
      bfs();
      printf("Case %d: ", ++tc);
      for(int it = ( n + 1 ) / 2; it >= 1; it--)
         printf( it != 1 ? "%d " : "%d\n", ans[it]);
   }
   return(0);
}
