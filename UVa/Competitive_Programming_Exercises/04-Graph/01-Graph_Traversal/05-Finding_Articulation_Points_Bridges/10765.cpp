#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 10010;

int V, M, a, b, dfsRoot, rootChildren, dfsCounter, dfs_low[MAX_V], dfs_num[MAX_V], dfs_parent[MAX_V], Articulation_Point[MAX_V];
vector <int> AdjList[MAX_V];
vector < pair <int, int> > ans;

void dfs(int u){
   dfs_low[u] = dfs_num[u] = ++dfsCounter;
   for(int j = 0; j < AdjList[u].size(); j++){
      int v = AdjList[u][j];
      if( not dfs_num[v] ){
         dfs_parent[v] = u;
         dfs(v);
         if( u == dfsRoot ) rootChildren++;
         if( dfs_low[v] >= dfs_num[u] ) Articulation_Point[u]++;
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
   fill(Articulation_Point, Articulation_Point + V, 0);
   dfsCounter = 0;
   dfsRoot = 0, rootChildren = 0;
   dfs(dfsRoot);
   Articulation_Point[dfsRoot] = ( rootChildren > 1 );
}

void solve(){
   ArticulationPoints();
   for(int u = 0; u < V; u++)
      ans.push_back( make_pair(u, Articulation_Point[u] + 1) );
   sort(ans.begin(), ans.end(), [](const pair <int, int> & x, const pair <int, int> & y){
            if( x.second != y.second ) return x.second > y.second;
            return x.first < y.first;
         });
   for(int i = 0; i < M; i++) printf("%d %d\n", ans[i].first, ans[i].second);
   putchar('\n');
}

void read(){
   while(scanf("%d %d", &a, &b), ~a and ~b){
      AdjList[a].push_back(b);
      AdjList[b].push_back(a);
   }
}

void clear(){
   ans.clear();
   for(int u = 0; u < V; u++) AdjList[u].clear();
}

int main(){
   while(scanf("%d %d", &V, &M), V | M){
      read();
      solve();
      clear();
   }
   return(0);
}
