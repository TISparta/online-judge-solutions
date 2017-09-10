#include <bits/stdc++.h>

#define WHITE  -1
#define GRAY    0
#define BLACK   1

using namespace std;

const int MAX_V = 1000010;

int E, V, a, b, vis[MAX_V];
vector <int> AdjList[MAX_V], ts;

bool dfs(int u){
   vis[u] = GRAY;
   bool ret = true;
   for(int j = 0; j < AdjList[u].size(); j++){
      int v = AdjList[u][j];
      if( vis[v] == WHITE )
         ret &= dfs(v);
      else if( vis[v] == GRAY )
         return false;
   }
   vis[u] = BLACK;
   ts.push_back(u);
   return ret;
}

bool TopologicalSort(){
   bool ret = true;
   fill(vis, vis + V + 1, WHITE);
   for(int u = 1; u <= V; u++)
      if( vis[u] == WHITE )
         ret &= dfs(u);
   return ret;
}

void read(){
   for(int i = 0; i < E; i++){
      scanf("%d %d", &a, &b);
      AdjList[a].push_back(b);
   }
}

void solve(){
   bool ret = TopologicalSort();
   if( not ret ) puts("IMPOSSIBLE");
   else for(int i = ts.size() - 1; i >= 0; i--) printf("%d\n", ts[i]);
}

void clear_(){
   ts.clear();
   for(int i = 1; i <= V; i++) AdjList[i].clear();
}

int main(){
   while(scanf("%d %d", &V, &E), E | V){
      read();
      solve();
      clear_();
   }
   return(0);
}
