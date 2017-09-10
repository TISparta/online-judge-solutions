#include <bits/stdc++.h>

using namespace std;

int n, u, v, q, _source, _target, d[310], path[310], ans;
char s[500], *p;
vector <int> G[310];

void printPath(int source, int target, int ct){
   if(source == target){
      printf("%d ", source);
      return;
   }
   printPath(source, path[target], ct + 1);
   printf( ct==0 ? "%d\n" : "%d ", target);
}

int bfs(int source, int target){
   for(int i = 1; i <= n; i++) d[i] = -1;
   queue <int> Q;
   Q.push(source), d[source] = 0;
   while(!Q.empty()){
      u = Q.front(), Q.pop();
      for(int i = 0; i < G[u].size(); i++){
         v = G[u][i];
         if(d[v] == -1)
            d[v] = d[u] + 1, path[v] = u, Q.push(v);
      }
      if(d[target] != -1) return d[target];
   }
   return -1;
}

int main(){
   while(scanf("%d", &n) == 1){
      puts("-----");
      for(int i = 0; i < n; i++){
         scanf("%d-", &v);
         cin.getline(s, 500);
         p = strtok(s, ",");
         while(p) G[v].push_back(atoi(p)), p = strtok(NULL, ",");
      }
      scanf("%d", &q);
      while(q--){
         scanf("%d %d", &_source, &_target);
         ans = bfs(_source, _target);
         if(ans == -1) puts("connection impossible");
         else printPath(_source, _target, 0);
      }
      for(int i = 1; i <= n; i++) G[i].clear();
   }
   return(0);
}
