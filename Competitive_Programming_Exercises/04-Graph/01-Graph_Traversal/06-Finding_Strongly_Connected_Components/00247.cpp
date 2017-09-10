#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 1010, LEN = 50;

int tc, V, E, ct, a, b, dfsCounter, numSCC, dfs_num[MAX_V], dfs_low[MAX_V];
bool vis[MAX_V];
char name[LEN], word[MAX_V][LEN];
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
         printf("%s", word[v]);
         if( u != v ) printf(", ");
         if( u == v ) break;
      }
      putchar('\n');
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
   if( tc++ ) putchar('\n');
   printf("Calling circles for data set %d:\n", tc);
   TarjanSCC();
}

void read(){
   for(int i = 0; i < E; i++){
      scanf("%s ", name);
      if( mp.find(name) == mp.end() ) mp[name] = ct, strcpy(word[ct++], name);
      a = mp[name];
      scanf("%s\n", name);
      if( mp.find(name) == mp.end() ) mp[name] = ct, strcpy(word[ct++], name);
      b = mp[name];
      AdjList[a].push_back(b);
   }
}

void clear(){
   ct = 0;
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
