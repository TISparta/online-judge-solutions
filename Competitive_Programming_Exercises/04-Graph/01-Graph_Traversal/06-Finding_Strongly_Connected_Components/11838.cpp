#include <bits/stdc++.h>

using namespace  std;

const int MAX_V = 2010;

int V, E, a, b, p, calls, dfsCounter, numSCC, dfs_low[MAX_V], dfs_num[MAX_V];
bool vis[MAX_V];
vector <int> AdjList[MAX_V];

void dfs(int u){
   dfs_low[u] = dfs_num[u] = ++dfsCounter;
   vis[u] = true;
   for(int j = 0; j < AdjList[u].size(); j++){
      int v = AdjList[u][j];
      if( not dfs_num[v] ) dfs(v);
      if( vis[v] ) dfs_low[u] = min(dfs_low[u], dfs_low[v]);
   }
   if( dfs_low[u] == dfs_num[u] ) numSCC++;
}

void TarjanSCC(){
   fill(dfs_num, dfs_num + V + 1, 0);
   fill(vis, vis + V + 1, false);
   dfsCounter = numSCC = calls = 0;
   for(int u = 1; u <= V; u++)
      if( not dfs_num[u] ) calls++, dfs(u);
}

void solve(){
   TarjanSCC();
   printf("%d\n", numSCC == 1 and calls == 1 );
}

void read(){
   for(int i = 0; i < E; i++){
      scanf("%d %d %d", &a, &b, &p);
      AdjList[a].push_back(b);
      if( p == 2 ) AdjList[b].push_back(a);
   }
}

void clear(){
   for(int u = 1; u <= V; u++) AdjList[u].clear();
}

int main(){
   while(scanf("%d %d", &V, &E), V | E){
      read();
      solve();
      clear();
   }
   return(0);
}
