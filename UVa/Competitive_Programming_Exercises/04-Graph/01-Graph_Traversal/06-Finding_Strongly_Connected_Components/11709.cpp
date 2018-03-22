#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 1010, LEN = 50;

int V, E, a, b, dfsCounter, numSCC, dfs_num[MAX_V], dfs_low[MAX_V];
bool vis[MAX_V];
char line[LEN];
vector <int> AdjList[MAX_V], path;
map <string, int> mp;

void dfs(int u){
   dfs_low[u] = dfs_num[u] = ++dfsCounter;
   vis[u] = true;
   path.push_back(u);
   for(int j = 0; j < AdjList[u].size(); j++){
      int v = AdjList[u][j];
      if( not dfs_num[v] ) dfs(v);
      if( vis[v] ) dfs_low[u] = min(dfs_low[u], dfs_low[v]);
   }
   if( dfs_low[u] == dfs_num[u] ){
      numSCC++;
      while(true){
         int v = path.back(); path.pop_back();
         vis[v] = false;
         if( u == v ) break;
      }
   }
}

void TarjanSCC(){
   fill(dfs_num, dfs_num + V, 0);
   fill(vis, vis + V, false);
   dfsCounter = numSCC = 0;
   for(int u = 0; u < V; u++)
      if( not dfs_num[u] ) dfs(u);
}

void solve(){
   TarjanSCC();
   printf("%d\n", numSCC);
}

void read(){
   for(int i = 0; i < V; i++){
      cin.getline(line, LEN);
      mp[line] = i;
   }
   for(int i = 0; i < E; i++){
      cin.getline(line, LEN);
      a = mp[line];
      cin.getline(line, LEN);
      b = mp[line];
      AdjList[a].push_back(b);
   }
}

void clear(){
   mp.clear();
   for(int u = 0; u < V; u++) AdjList[u].clear();
}

int main(){
   while(scanf("%d %d\n", &V, &E), V | E){
      read();
      solve();
      clear();
   }
   return(0);
}
