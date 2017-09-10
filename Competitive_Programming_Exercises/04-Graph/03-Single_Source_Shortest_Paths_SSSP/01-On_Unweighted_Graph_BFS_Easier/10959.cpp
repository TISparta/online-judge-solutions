#include <bits/stdc++.h>

using namespace std;

int tc, n, m, u, v, d[1010];
bool Adj[1010][1010];

void bfs(int source){
   for(int i = 0; i < n; i++) d[i] = -1;
   queue <int> Q;
   Q.push(source), d[source] = 0;
   while(!Q.empty()){
      u = Q.front(), Q.pop();
      for(int i = 0; i < n; i++)
         if(Adj[u][i] && d[i] == -1)
            d[i] = d[u] + 1, Q.push(i);
   }
}

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%d %d", &n, &m);
      memset(Adj, false, sizeof Adj);
      for(int i = 0; i < m; i++) scanf("%d %d", &u, &v), Adj[u][v] = Adj[v][u] = true;
      bfs(0);
      for(int i = 1; i < n; i++) printf("%d\n", d[i]);
      if(tc) putchar('\n');
   }
   return(0);
}
