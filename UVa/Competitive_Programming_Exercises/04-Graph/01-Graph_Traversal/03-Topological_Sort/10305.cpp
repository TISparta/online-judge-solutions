#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 110;

int V, E, a, b;
bool vis[MAX_V];
vector <int> AdjList[MAX_V], ts;

void dfs(int u){
   vis[u] = true;
   for(int j = 0; j < AdjList[u].size(); j++){
      int v = AdjList[u][j];
      if( not vis[v] )
         dfs(v);
   }
   ts.push_back(u);
}

void TopologicalSort(){
   ts.clear();
   memset(vis, false, sizeof vis);
   for(int u = 1; u <= V; u++)
      if( not vis[u] )
         dfs(u);
   reverse(ts.begin(), ts.end());
}

int main(){
   while(scanf("%d %d", &V, &E), V | E){
      for(int i = 0; i < E; i++){
         scanf("%d %d", &a, &b);
         AdjList[a].push_back(b);
      }
      TopologicalSort();
      for(int i = 0, sz = ts.size(); i < sz; i++)
         printf( i == sz - 1 ? "%d\n" : "%d ", ts[i] );
      for(int i = 1; i <= V; i++) AdjList[i].clear();
   }
   return(0);
}
