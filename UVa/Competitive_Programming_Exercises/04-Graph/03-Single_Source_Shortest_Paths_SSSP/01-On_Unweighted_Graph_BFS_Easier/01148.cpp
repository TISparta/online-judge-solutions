#include <bits/stdc++.h>

using namespace std;

int tc, n, d[100010], _source, _target, u, v, nu;
vector <int> G[100010];

int bfs(int source, int target){
   queue <int> Q;
   Q.push(source), d[source] = 0;
   while(!Q.empty()){
      u = Q.front(), Q.pop();
      if(u == target) return d[target] - 1;
      for(int i = 0; i < G[u].size(); i++){
         v = G[u][i];
         if(d[v] == -1)
            d[v] = d[u] + 1, Q.push(v);
      }
   }
}

int main(){
   scanf("%d", &tc);
   while(tc--){
      for(int i = 0; i < n; i++) G[i].clear();
      scanf("%d", &n);
      for(int i = 0; i < n; i++){
         d[i] = -1;
         scanf("%d %d", &u, &nu);
         for(int j = 0; j < nu; j++)
            scanf("%d", &v), G[u].push_back(v), G[v].push_back(u);
      }
      scanf("%d %d", &_source, &_target);
      printf("%d %d %d\n", _source, _target, bfs(_source, _target));
      if(tc) putchar('\n');
   }
   return(0);
}
