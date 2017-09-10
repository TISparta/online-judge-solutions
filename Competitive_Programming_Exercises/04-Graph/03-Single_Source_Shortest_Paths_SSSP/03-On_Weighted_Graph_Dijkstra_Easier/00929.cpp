#include <bits/stdc++.h>

using namespace std;

const int SIZE = 1010, INF = 1000000000;

typedef pair <int, int> ii;

int tc, N, M, W[SIZE][SIZE], dis[SIZE * SIZE];
int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};

inline bool isValid(int R, int C){
   return ( 0 <= R and 0 <= C and R < N and C < M );
}

int Dijkstra(int source, int target){
   fill(dis, dis + N * M + 1, INF);
   dis[source] = W[0][0];
   set < ii > st;
   st.insert( ii(0, source) );
   while( not st.empty() ){
      int u = st.begin() -> second, ru = u / M, cu = u % M;
      st.erase( st.begin() );
      if( u == target ) return dis[u];
      for(int d = 0; d < 4; d++){
         int rv = ru + dr[d], cv = cu + dc[d], v = rv * M + cv, w = W[rv][cv];
         if( isValid(rv, cv) and dis[v] > dis[u] + w )
            dis[v] = dis[u] + w, st.insert( ii(dis[v], v) );
      }
   }
}

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%d %d", &N, &M);
      for(int i = 0; i < N; i++)
         for(int j = 0; j < M; j++)
            scanf("%d", &W[i][j]);
      printf("%d\n", Dijkstra(0, N * M - 1));
   }
   return(0);
}
