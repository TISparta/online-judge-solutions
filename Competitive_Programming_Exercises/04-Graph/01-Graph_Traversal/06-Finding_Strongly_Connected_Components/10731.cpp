#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 30, LEN = 60;

int N, a, len, dfsCounter, dfs_low[MAX_V], dfs_num[MAX_V];
char line[LEN];
bool vis[MAX_V], Adj[MAX_V][MAX_V], in_stack[MAX_V], first = true;
vector <int> path;
vector < vector < char > > ans;

void dfs(int u){
   dfs_low[u] = dfs_num[u] = ++dfsCounter;
   in_stack[u] = true;
   path.push_back(u);
   for(int v = 0; v < MAX_V; v++)
      if( Adj[u][v] ){
         if( not dfs_num[v] ) dfs(v);
         if( in_stack[v] ) dfs_low[u] = min(dfs_low[u], dfs_low[v]);
      }
   if( dfs_low[u] == dfs_num[u] ){
      vector <char> s;
      while(true){
         int v = path.back(); path.pop_back();
         in_stack[v] = false;
         s.push_back(v + 'A');
         if( u == v ) break;
      }
      sort(s.begin(), s.end());
      ans.push_back(s);
   }
}

void solve(){
   if( not first ) putchar('\n');
   first = false;
   memset(dfs_num, 0, sizeof dfs_num);
   dfsCounter = 0;
   for(int u = 0; u < MAX_V; u++)
      if( vis[u] and not dfs_num[u] ) dfs(u);
   sort(ans.begin(), ans.end());
   for(int i = 0; i < ans.size(); i++)
      for(int j = 0, sz = ans[i].size(); j < sz; j++)
         printf( j == sz - 1 ? "%c\n" : "%c ", ans[i][j] );
}

void read(){
   for(int i = 0; i < N; i++){
      cin.getline(line, LEN);
      len = strlen(line);
      a = line[len - 1] - 'A';
      len -= 2;
      for(int j = 0; j < len; j += 2)
         vis[line[j] - 'A'] = true, Adj[a][line[j] - 'A'] = true;
   }
}

void clear(){
   ans.clear();
   memset(vis, false, sizeof vis);
   memset(Adj, false, sizeof Adj);
}

int main(){
   while(scanf("%d\n", &N), N){
      read();
      solve();
      clear();
   }
   return(0);
}
