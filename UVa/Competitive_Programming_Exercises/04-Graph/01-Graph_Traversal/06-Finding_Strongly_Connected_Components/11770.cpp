#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 10010;

int tc, V, E, CC;
bool vis[MAX_V];
vector <int> AdjList[MAX_V], ts;

void dfs(int u, bool ok = true){
   vis[u] = true;
   for(int j = 0; j < AdjList[u].size(); j++){
      int v = AdjList[u][j];
      if( not vis[v] ) dfs(v);
   }
   if( ok ) ts.push_back(u);
}

void solve(int t){
   fill(vis, vis + V + 1, false);
   for(int u = 1; u <= V; u++)
      if( not vis[u] )
         dfs(u);
   reverse(ts.begin(), ts.end());
   fill(vis, vis + V + 1, false);
   for(int j = 0; j < ts.size(); j++)
      if( not vis[ts[j]] )
         CC++, dfs(ts[j], false);
   printf("Case %d: %d\n", t, CC);
}

void read(){
   int u, v;
   scanf("%d %d", &V, &E);
   while(E--){
      scanf("%d %d", &u, &v);
      AdjList[u].push_back(v);
   }
}

void clear(){
   CC = 0;
   ts.clear();
   for(int u = 1; u <= V; u++) AdjList[u].clear();
}

int main(){
   scanf("%d", &tc);
   for(int t = 1; t <= tc; t++){
      read();
      solve(t);
      clear();
   }
   return(0);
}
