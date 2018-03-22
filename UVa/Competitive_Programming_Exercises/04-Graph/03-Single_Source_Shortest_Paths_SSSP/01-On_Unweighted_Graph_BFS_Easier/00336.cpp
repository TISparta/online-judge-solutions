#include <bits/stdc++.h>

using namespace std;

int n, tc;
long long _source, TTL, u, v;
map <long long, vector <long long> > G;
map <long long, int> d;
set <long long> vert;

int bfs(int source){
   for(auto it : vert) d[it] = INT_MAX;
   queue <long long> Q;
   Q.push(source), d[source] = 0;
   while(!Q.empty()){
      u = Q.front(), Q.pop();
      for(int i = 0; i < G[u].size(); i++){
         v = G[u][i];
         if(d[v] == INT_MAX && d[u] + 1 <= TTL)
            d[v] = d[u] + 1, Q.push(v);
      }
   }
   int ct = 0;
   for(auto it : vert)
      if(d[it] > TTL) ct++;
   return ct;
}

int main(){
   while(scanf("%d", &n), n){
      G.clear(), vert.clear();
      for(int i = 0; i < n; i++) scanf("%lld %lld", &u, &v), G[u].push_back(v), G[v].push_back(u), vert.insert(u), vert.insert(v);
      while(scanf("%lld %lld", &_source,&TTL), _source|TTL){
         printf("Case %d: %d nodes not reachable from node %lld with TTL = %lld.\n", ++tc, bfs(_source), _source, TTL);
      }
   }
   return(0);
}
