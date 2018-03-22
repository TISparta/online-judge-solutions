#include <bits/stdc++.h>

#define SIZE 510

using namespace std;

int n, m, a, b, c, w, ans;
vector < pair <int, int> > G[SIZE];
bool vis[SIZE];

int floodfill(int u){
   vis[u] = true;
   int ct = 1;
   for(int v = 0; v < G[u].size(); v++)
      if( not vis[G[u][v].first] and G[u][v].second == w )
         ct += floodfill(G[u][v].first);
   return ct;
}

void clear_(){
   w = ans = INT_MIN;
   for(int it = 1; it <= n; it++) G[it].clear();
   memset(vis, false, sizeof vis);
}

bool check(int u){
   for(int v = 0; v < G[u].size(); v++)
      if( G[u][v].second == w ) return true;
   return false;
}

int main(){
   while(scanf("%d %d", &n, &m), n | m){
      clear_();
      for(int it = 0; it < m; it++){
         scanf("%d %d %d", &a, &b, &c);
         G[a].push_back( make_pair(b, c) );
         G[b].push_back( make_pair(a, c) );
         w = max(w, c);
      }
      for(int it = 1; it <= n; it++)
         if( check(it) )
            ans = max(ans, floodfill(it));
      printf("%d\n", ans);
   }
   return(0);
}
