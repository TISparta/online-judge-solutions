#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 210, MAX_E = 40000, INF = 1000000000;

int tc, V, E, Q, x, fw[MAX_V], dis[MAX_V], u[MAX_E], v[MAX_E], w[MAX_E];
bool relax;

inline int pow3(int p){
   return p * p * p;
}

void BellmanFord(int source){
   fill(dis, dis + V + 1, INF);
   dis[source] = 0;
   for(int i = 1; i < V; i++){
      relax = false;
      for(int j = 0; j < E; j++)
         if( dis[u[j]] != INF and dis[v[j]] > dis[u[j]] + w[j] )
            dis[v[j]] = dis[u[j]] + w[j], relax = true;
      if( not relax ) break;
   }
   for(int j = 0; j < E; j++)
      if( dis[u[j]] != INF and dis[v[j]] > dis[u[j]] + w[j] )
         dis[v[j]] = -INF;
}

int main(){
   while( scanf("%d", &V) == 1 ){
      for(int i = 1; i <= V; i++) scanf("%d", fw + i);
      scanf("%d", &E);
      for(int i = 0; i < E; i++){
         scanf("%d %d", u + i, v + i);
         w[i] = pow3(fw[v[i]] - fw[u[i]]);
      }
      printf("Set #%d\n", ++tc);
      BellmanFord(1);
      scanf("%d", &Q);
      while(Q--){
         scanf("%d", &x);
         if( dis[x] < 3 or dis[x] == INF ) puts("?");
         else printf("%d\n", dis[x]);
      }
   }
   return(0);
}
