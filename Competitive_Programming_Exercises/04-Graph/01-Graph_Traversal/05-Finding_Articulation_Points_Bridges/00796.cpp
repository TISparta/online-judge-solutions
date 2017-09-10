#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1010;

int V, Ei, a, b, dfsCounter, dfs_low[MAX_N], dfs_num[MAX_N], dfs_parent[MAX_N];
vector <int> AdjList[MAX_N];
vector < pair < int, int > > bridge;

void dfs(int u){
   dfs_low[u] = dfs_num[u] = ++dfsCounter;
   for(int j = 0; j < AdjList[u].size(); j++){
      int v = AdjList[u][j];
      if( not dfs_num[v] ){
         dfs_parent[v] = u;
         dfs(v);
         if( dfs_low[v] > dfs_num[u] ) bridge.push_back( make_pair(min(u, v), max(u, v)) );

         dfs_low[u] = min(dfs_low[u], dfs_low[v]);
      }
      else if( v != dfs_parent[u] )
         dfs_low[u] = min(dfs_low[u], dfs_num[v]);
   }
}

void Bridges(){
   fill(dfs_low, dfs_low + V, 0);
   fill(dfs_num, dfs_num + V, 0);
   fill(dfs_parent, dfs_parent + V, -1);
   dfsCounter = 0;
   for(int u = 0; u < V; u++)
      if( not dfs_num[u] )
         dfs(u);
}

void solve(){
   Bridges();
   sort(bridge.begin(), bridge.end());
   printf("%d critical links\n", (int) bridge.size());
   for(int i = 0; i < bridge.size(); i++)
      printf("%d - %d\n", bridge[i].first, bridge[i].second);
   putchar('\n');
}

void read(){
   for(int i = 0; i < V; i++){
      scanf("%d (%d)", &a, &Ei);
      for(int j = 0; j < Ei; j++){
         scanf("%d", &b);
         AdjList[a].push_back(b);
      }
   }
}

void clear(){
   bridge.clear();
   for(int u = 0; u < V; u++) AdjList[u].clear();
}

int main(){
   while(scanf("%d", &V) == 1){
      read();
      solve();
      clear();
   }
   return(0);
}
