#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 3010;

int V, ct, dfsCounter, numSCC, dfs_low[MAX_V], dfs_num[MAX_V];
bool in_stack[MAX_V], vis[MAX_V];
string line, word_u, word_v;
stringstream ss;
vector <int> AdjList[MAX_V], SCC[MAX_V], path;
vector <string> ans;
map <string, int> mp;
map <int, string> inv_mp;

void dfs1(int u){
   dfs_num[u] = dfs_low[u] = ++dfsCounter;
   in_stack[u] = true;
   path.push_back(u);
   for(int j = 0; j < AdjList[u].size(); j++){
      int v = AdjList[u][j];
      if( not dfs_num[v] ) dfs1(v);
      if( in_stack[v] ) dfs_low[u] = min(dfs_low[u], dfs_low[v]);
   }
   if( dfs_low[u] == dfs_num[u] ){
      int v;
      do{
         v = path.back(); path.pop_back();
         in_stack[v] = false;
         SCC[numSCC].push_back(v);
      }while( u != v );
      numSCC++;
   }
}

void TarjanSCC(){
   V = ct;
   fill(dfs_num, dfs_num + V, 0);
   fill(in_stack, in_stack + V, false);
   dfsCounter = numSCC = 0;
   for(int u = 0; u < V; u++)
      if( not dfs_num[u] ) dfs1(u);
}

void dfs2(int u){
   if( vis[u] ) return;
   vis[u] = true;
   ans.push_back( inv_mp[u] );
   for(int j = 0; j < AdjList[u].size(); j++){
      int v = AdjList[u][j];
      if( not vis[v] ) dfs2(v);
   }
}

void solve(){
   TarjanSCC();
   fill(vis, vis + V, false);
   for(int u = 0; u < numSCC; u++)
      if( SCC[u].size() > 1 ) dfs2(SCC[u].front());
   sort(ans.begin(), ans.end());
   printf("%d\n", (int)ans.size());
   for(int i = 0, sz = ans.size(); i < sz; i++)
      printf( i == sz - 1 ? "%s\n" : "%s ", ans[i].c_str());
}

int counter(string& x){
   if( mp.find(x) != mp.end() ) return mp[x];
   inv_mp[ct] = x;
   return mp[x] = ct++;
}

void read(){
   for(int i = 0; i < V; i++){
      getline(cin, line);
      ss.clear();
      ss << line;
      ss >> word_u;
      int u = counter(word_u);
      while(ss >> word_v) AdjList[u].push_back(counter(word_v));
   }
}

void clear(){
   ct = 0;
   mp.clear();
   ans.clear();
   for(int u = 0; u < V; u++) AdjList[u].clear();
   for(int u = 0; u < numSCC; u++) SCC[u].clear();
}

int main(){
   while(scanf("%d\n", &V), V){
      read();
      solve();
      clear();
   }
   return(0);
}
