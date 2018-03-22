#include <bits/stdc++.h>

#define WHITE  -1 
#define RED     0
#define BLACK   1

using namespace std;

const int MAX_V = 1000;

int V, E, a, b, color[MAX_V];
vector <int> AdjList[MAX_V];

bool isBipartite(int source){
   bool isOK = true;
   queue <int> Q;
   Q.push(source);
   fill(color, color + V, WHITE);
   color[source] = RED;
   while( not Q.empty() and isOK ){
      int u = Q.front(); Q.pop();
      for(int j = 0; j < AdjList[u].size() and isOK; j++){
         int v = AdjList[u][j];
         if( color[v] == WHITE )
            color[v] = color[u] ^ 1, Q.push(v);
         else if( color[v] == color[u] )
            isOK = false;
      }
   }
   return isOK;
}

void solve(){
   puts( isBipartite(0) ? "BICOLORABLE." : "NOT BICOLORABLE.");
}

void read(){
   for(int i = 0; i < E; i++){
      scanf("%d %d", &a, &b);
      AdjList[a].push_back(b);
      AdjList[b].push_back(a);
   }
}

void clear(){
   for(int i = 0; i < V; i++) AdjList[i].clear();
}

int main(){
   while(scanf("%d %d", &V, &E), V){
      read();
      solve();
      clear();
   }
   return(0);
}
