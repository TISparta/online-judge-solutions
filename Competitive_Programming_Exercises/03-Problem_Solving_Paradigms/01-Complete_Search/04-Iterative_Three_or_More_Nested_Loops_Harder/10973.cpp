#include <bits/stdc++.h>

#define SIZE 3010

using namespace std;

int tc, V, E, a, b, ans;
bool Adj[SIZE][SIZE];

int main(){
   scanf("%d", &tc);
   while(tc--){
      memset(Adj, false, sizeof Adj);
      scanf("%d %d", &V, &E);
      for(int it = 0; it < E; it++) scanf("%d %d", &a, &b), Adj[a][b] = Adj[b][a] = true;
      ans = 0;
      for(int v1 = 1; v1 <= V; v1++)
         for(int v2 = v1 + 1; v2 <= V; v2++){
            if( Adj[v1][v2] )
               for(int v3 = v2 + 1; v3 <= V; v3++)
                  if( Adj[v2][v3] and Adj[v3][v1]) ans++;
         }
      printf("%d\n", ans);
   }
   return(0);
}
