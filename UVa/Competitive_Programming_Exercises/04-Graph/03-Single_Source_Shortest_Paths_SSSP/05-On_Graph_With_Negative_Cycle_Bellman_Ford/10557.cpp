#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 1000, INF = 1000000000;

int V, b, c, r, dis[MAX_V], W[MAX_V];
vector <int> AdjList[MAX_V];
bool vis[MAX_V];

bool dfs(int x, int y){
   if( x == y ) return true;
   vis[x] = true;
   bool check = false;
   for(int j = 0; j < AdjList[x].size(); j++)
      if( not vis[AdjList[x][j]] )
         check |= dfs(AdjList[x][j], y);
   return check;
}

bool reachable(int x, int y){
   memset(vis, false, sizeof vis);
   return dfs(x, y);
}

bool NegativeCycle(){
   for(int u = 0; u < V; u++)
      for(int j = 0; j < AdjList[u].size(); j++){
         int v = AdjList[u][j], w = W[v];
         if( dis[v] > dis[u] + w and dis[u] + w < 0 and reachable(u, V) )
            return true;
      }
   return false;
}

void BellmanFord(int source){
   fill(dis, dis + V + 1, INF);
   dis[source] = -100;
   for(int i = 0; i < V - 1; i++)
      for(int u = 1; u <= V; u++)
         for(int j = 0; j < AdjList[u].size(); j++){
            int v = AdjList[u][j], w = W[v];
            if( dis[v] > dis[u] + w and dis[u] + w < 0 )
               dis[v] = dis[u] + w;
         }
}

void clear_(){
   for(int i = 1; i <= V; i++) AdjList[i].clear();
}

int main(){
   while(scanf("%d", &V), V != -1){
      clear_();
      for(int i = 1; i <= V; i++){
         scanf("%d %d", &c, &r);
         for(int j = 0; j < r; j++){
            scanf("%d", &b);
            AdjList[i].push_back(b);
         }
         W[i] = -c;
      }
      BellmanFord(1);
      if( dis[V] < 0 or NegativeCycle() ) puts("winnable");
      else puts("hopeless");
   }
   return(0);
}
