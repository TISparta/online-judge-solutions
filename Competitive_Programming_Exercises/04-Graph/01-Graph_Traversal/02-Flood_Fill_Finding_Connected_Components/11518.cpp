#include <bits/stdc++.h>

#define SIZE 10010

using namespace std;

int tc, n, m, l, a, b;
vector <int> G[SIZE];
bool vis[SIZE];

void dfs(int u){
   vis[u] = true;
   for(int v = 0; v < G[u].size(); v++)
      if( not vis[G[u][v]] )
         dfs(G[u][v]);
}

void clear_(){
   for(int it = 1; it <= n; it++) G[it].clear();
   memset(vis, false, sizeof vis);
}

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%d %d %d", &n, &m, &l);
      for(int it = 0; it < m; it++){
         scanf("%d %d", &a, &b);
         G[a].push_back(b);
      }
      for(int it = 0; it < l; it++){
         scanf("%d", &a);
         dfs(a);
      }
      printf("%d\n", accumulate(vis, vis + n + 1, 0));
      clear_();
   }
   return(0);
}
