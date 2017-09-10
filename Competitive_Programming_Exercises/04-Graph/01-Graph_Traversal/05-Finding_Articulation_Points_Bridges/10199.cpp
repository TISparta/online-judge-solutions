#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 110, LEN = 35;

int tc, V, E, dfsCounter, dfsRoot, rootChildren, dfs_low[MAX_V], dfs_num[MAX_V], dfs_parent[MAX_V];
bool Articulation_Point[MAX_V];
char word[MAX_V][LEN], word1[LEN], word2[LEN];
vector <int> AdjList[MAX_V];
map <string, int> mp;
vector <string> ans;

void dfs(int u){
   dfs_low[u] = dfs_num[u] = ++dfsCounter;
   for(int j = 0; j < AdjList[u].size(); j++){
      int v = AdjList[u][j];
      if( not dfs_num[v] ){
         dfs_parent[v] = u;
         dfs(v);
         if( u == dfsRoot ) rootChildren++;
         if( dfs_low[v] >= dfs_num[u] ) Articulation_Point[u] = true;
         dfs_low[u] = min(dfs_low[u], dfs_low[v]);
      }
      else if( v != dfs_parent[u] )
         dfs_low[u] = min(dfs_low[u], dfs_num[v]);
   }
}

void ArticulationPoints(){
   fill(dfs_low, dfs_low + V, 0);
   fill(dfs_num, dfs_num + V, 0);
   fill(dfs_parent, dfs_parent + V, -1);
   fill(Articulation_Point, Articulation_Point + V, false);
   dfsCounter = 0;
   for(int u = 0; u < V; u++)
      if( not dfs_num[u] ){
         dfsRoot = u, rootChildren = 0;
         dfs(dfsRoot);
         Articulation_Point[dfsRoot] = ( rootChildren > 1 );
      }
}

void solve(){
   ArticulationPoints();
   for(int i = 0; i < V; i++)
      if( Articulation_Point[i] ) ans.push_back( word[i] );
   sort(ans.begin(), ans.end());
   if( tc++ ) putchar('\n');
   printf("City map #%d: %d camera(s) found\n", tc, (int)ans.size());
   for(int i = 0; i < ans.size(); i++) printf("%s\n", ans[i].c_str());
}

void read(){
   for(int i = 0; i < V; i++){
      scanf("%s", word[i]);
      mp[word[i]] = i;
   }
   scanf("%d\n", &E);
   for(int i = 0; i < E; i++){
      scanf("%s %s\n", word1, word2);
      int u = mp[word1], v = mp[word2];
      AdjList[u].push_back(v);
      AdjList[v].push_back(u);
   }
}

void clear(){
   mp.clear();
   for(int u = 0; u < V; u++) AdjList[u].clear();
   ans.clear();
}

int main(){
   while(scanf("%d\n", &V), V){
      read();
      solve();
      clear();
   }
   return(0);
}
