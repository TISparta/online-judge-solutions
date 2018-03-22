#include <bits/stdc++.h>

using namespace std;

int n, u, v, q, _source, d[3000];
vector <int> G[30000];
pair <int, int> ans;

pair <int, int> bfs(int source){
   for(int i = 0; i < n; i++) d[i] = -1;
   queue <int> Q;
   pair <int, int> _max = make_pair(0, 0);
   int ct = 0, pib = 0;
   Q.push(source), d[source] = 0;
   while(!Q.empty()){
      u = Q.front(), Q.pop();
      if(pib != d[u]){
         if(ct > _max.first)
            _max = make_pair(ct,pib+1);
         ct = 0;
      }
      pib = d[u];
      for(int i = 0; i < G[u].size(); i++){
         v = G[u][i];
         if(d[v] == -1)
            d[v] = d[u] + 1, Q.push(v), ct++;
      }
   }
   return _max;
}

int main(){
   scanf("%d", &n);
   for(int i = 0; i < n; i++){
      scanf("%d", &u);
      for(int j = 0; j < u; j++) scanf("%d", &v), G[i].push_back(v);
   }
   scanf("%d", &q);
   while(q--){
      scanf("%d", &_source);
      if(G[_source].size() == 0) puts("0");
      else ans = bfs(_source), printf("%d %d\n", ans.first, ans.second);
   }
   return(0);
}
