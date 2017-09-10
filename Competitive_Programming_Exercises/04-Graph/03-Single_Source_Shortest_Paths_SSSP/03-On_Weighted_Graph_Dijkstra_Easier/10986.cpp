#include <bits/stdc++.h>

using namespace std;

const int SIZE = 20010, INF = 1000000000;

typedef pair <int, int> ii;

int tc, V, E, S, T, a, b, c, d, dis[SIZE];
vector <int> AdjList[SIZE], W[SIZE];

int Dijkstra(int source, int target){
   fill(dis, dis + V, INF), dis[source] = 0;
   set < ii > st;
   st.insert( ii(0, source) );
   while( not st.empty() ){
      ii front = *st.begin(); st.erase( st.begin() );
      int d = front.first, u = front.second;
      if( u == target ) return dis[u];
      for(int j = 0; j < AdjList[u].size(); j++){
         int v = AdjList[u][j], w = W[u][j];
         if( dis[v] > dis[u] + w ){
            dis[v] = dis[u] + w;
            st.insert( ii(dis[v], v) );
         }
      }
   }
   return dis[target];
}

int main(){
   scanf("%d", &tc);
   for(int t = 1; t <= tc; t++){
      scanf("%d %d %d %d", &V, &E, &S, &T);
      for(int i = 0; i < E; i++){
         scanf("%d %d %d", &a, &b, &c);
         AdjList[a].push_back(b);
         W[a].push_back(c);
         AdjList[b].push_back(a);
         W[b].push_back(c);
      }
      d = Dijkstra(S, T);
      if( d != INF )
         printf("Case #%d: %d\n", t, d);
      else
         printf("Case #%d: unreachable\n", t);
      for(int i = 0; i < V; i++)
         AdjList[i].clear(), W[i].clear();
   }
   return(0);
}
