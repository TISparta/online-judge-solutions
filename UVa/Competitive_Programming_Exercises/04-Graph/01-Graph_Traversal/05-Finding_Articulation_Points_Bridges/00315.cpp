#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 110, LEN = 300;

int V, dfs_low[MAX_N], dfs_num[MAX_N], dfs_parent[MAX_N], dfsCounter, dfsRoot, rootChildren;
char line[MAX_N], *p;
bool Articulation_Point[MAX_N];
vector <int> AdjList[MAX_N];

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

int ArticulationPoints(){
   fill(dfs_low, dfs_low + V + 1, 0);
   fill(dfs_num, dfs_num + V + 1, 0);
   fill(dfs_parent, dfs_parent + V + 1, -1);
   fill(Articulation_Point, Articulation_Point + V + 1, false);
   dfsRoot = 1, dfsCounter = rootChildren = 0; 
   dfs(dfsRoot);
   Articulation_Point[dfsRoot] = ( rootChildren > 1 );
   int ret = 0;
   for(int u = 1; u <= V; u++) ret += Articulation_Point[u];
   return ret;
}

void solve(){
   printf("%d\n", ArticulationPoints());   
}

int read(){
   while(cin.getline(line, LEN)){
      p = strtok(line, " ");
      int u = atoi(p);
      if( u == 0 ) break;
      p = strtok(NULL, " ");
      while(p){
         AdjList[u].push_back(atoi(p));
         AdjList[atoi(p)].push_back(u);
         p = strtok(NULL, " ");
      }
   }
}

void clear(){
   for(int u = 1; u <= V; u++) AdjList[u].clear();
}

int main(){
   while(scanf("%d\n", &V), V){
      read();
      solve();
      clear();
   }
   return(0);
}
