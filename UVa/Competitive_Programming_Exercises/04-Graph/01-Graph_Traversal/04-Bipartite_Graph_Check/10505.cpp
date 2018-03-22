#include <bits/stdc++.h>

#define WHITE  -1 
#define RED     0
#define BLACK   1

using namespace std;

const int MAX_V = 210;

int tc, V, E, a, b, black, red, ans, color[MAX_V];
vector <int> AdjList[MAX_V];

bool isBipartite(int source){
   bool isOK = true;
   queue <int> Q;
   Q.push(source);
   color[source] = RED;
   red = black = 0;
   while( not Q.empty() ){
      int u = Q.front(); Q.pop();
      if( color[u] == RED ) red++;
      if( color[u] == BLACK ) black++;
      for(int j = 0; j < AdjList[u].size(); j++){
         int v = AdjList[u][j];
         if( color[v] == WHITE )
            color[v] = color[u] ^ 1, Q.push(v);
         else if( color[v] == color[u] )
            isOK = false;
      }
   }
   return isOK;
}

int t;

void solve(){
   fill(color, color + V + 1, WHITE), ans = 0;
   for(int i = 1; i <= V; i++)
      if( color[i] == WHITE and isBipartite(i) )
         ans += max(red, black);
   printf("%d\n", ans);
}

void read(){
   scanf("%d", &V);
   for(int i = 1; i <= V; i++){
      scanf("%d", &E);
      for(int j = 0; j < E; j++){
         scanf("%d", &b);
         if( b <= V ){
            AdjList[i].push_back(b);
            AdjList[b].push_back(i);
         }
      }
   }
}

void clear(){
   for(int u = 1; u <= V; u++) AdjList[u].clear();
}

int main(){
   scanf("%d", &tc);
   while(tc--){
      read();
      solve();
      clear();
   }
   return(0);
}
