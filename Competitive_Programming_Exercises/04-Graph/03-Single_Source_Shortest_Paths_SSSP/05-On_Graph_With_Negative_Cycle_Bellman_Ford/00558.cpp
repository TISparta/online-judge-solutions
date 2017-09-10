#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 1010, MAX_E = 2010, INF = 1000000000;

int tc, V, E, dis[MAX_V], pred[MAX_V], u[MAX_E], v[MAX_E], w[MAX_E];

bool NegativeCycle(){
   for(int i = 0; i < E; i++)
      if( dis[v[i]] > dis[u[i]] + w[i] ) return true;
   return false;
}

void BellmanFord(int source){
   fill(dis, dis + MAX_V, INF);
   dis[source] = 0;
   for(int ct = 1;  ct < V; ct++)
      for(int i = 0; i < E; i++)
         if( dis[v[i]] > dis[u[i]] + w[i] )
            dis[v[i]] = dis[u[i]] + w[i];
}

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%d %d", &V, &E);
      for(int i = 0; i < E; i++)
         scanf("%d %d %d", u + i, v + i, w + i);
      BellmanFord(0);
      puts( NegativeCycle() ? "possible" : "not possible" );
   }
   return(0);
}
