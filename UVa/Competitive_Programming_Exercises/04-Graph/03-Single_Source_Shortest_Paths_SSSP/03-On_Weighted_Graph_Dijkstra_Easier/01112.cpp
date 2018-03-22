#include <bits/stdc++.h>

using namespace std;

const int SIZE = 110, INF = 1000000000;

typedef pair <int, int> ii;

int tc, V, S, T, E, a, b, c, ans, dis[SIZE];
vector <int> AdjList[SIZE], W[SIZE];

void Dijkstra(int source){
   fill(dis, dis + V + 1, INF);
   dis[source] = 0;
   set <ii> st;
   st.insert( ii(0, source) );
   while( not st.empty() ){
      int u = st.begin() -> second;
      st.erase( st.begin() );
      for(int j = 0; j < AdjList[u].size(); j++){
         int v = AdjList[u][j], w = W[u][j];
         if( dis[v] > dis[u] + w )
            dis[v] = dis[u] + w, st.insert( ii(dis[v], v) );
      }
   }
}

void clear_(){
   for(int i = 1; i <= V; i++) AdjList[i].clear(), W[i].clear();
}

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%d %d %d %d", &V, &S, &T, &E);
      for(int i = 0; i < E; i++){
         scanf("%d %d %d", &a, &b, &c);
         AdjList[b].push_back(a);
         W[b].push_back(c);
      }
      Dijkstra(S);
      ans = 0;
      for(int i = 1; i <= V; i++)
         if( dis[i] <= T ) ans++;
      printf("%d\n", ans);
      if( tc ) putchar('\n');
      clear_();
   }
   return(0);
}
