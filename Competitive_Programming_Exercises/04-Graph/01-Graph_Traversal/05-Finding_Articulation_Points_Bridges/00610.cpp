#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1010;

int tc, V, E, a, b, dfsCounter, dfs_low[MAX_N], dfs_num[MAX_N], dfs_parent[MAX_N];
bool path[MAX_N][MAX_N];
vector < int > AdjList[MAX_N];

void dfs(int u){
   dfs_low[u] = dfs_num[u] = ++dfsCounter;
   for(int j = 0; j < AdjList[u].size(); j++){
      int v = AdjList[u][j];
      if( not dfs_num[v] ){
         dfs_parent[v] = u;
         dfs(v);
         path[u][v] = true;
         if( dfs_low[v] > dfs_num[u] ) path[v][u] = true;
         dfs_low[u] = min(dfs_low[u], dfs_low[v]);
      }
      else if( v != dfs_parent[u] )
         path[v][u] = true, path[u][v] = false, dfs_low[u] = min(dfs_low[u], dfs_num[v]);
   }
}

void Bridges(){
   fill(dfs_low, dfs_low + V + 1, 0);
   fill(dfs_num, dfs_num + V + 1, 0);
   fill(dfs_parent, dfs_parent + V + 1, -1);
   dfsCounter = 0;
   dfs(1);
}

void solve(){
   Bridges();
   printf("%d\n\n", ++tc);
   for(int u = 1; u <= V; u++)
      for(int v = 1; v <= V; v++)
         if( path[u][v] ) printf("%d %d\n", u, v);
   puts("#");
}

void read(){
   for(int i = 0; i < E; i++){
      scanf("%d %d", &a, &b);
      AdjList[a].push_back(b);
      AdjList[b].push_back(a);
   }
}

void clear(){
   fill(path[0], path[V + 1], false);
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
