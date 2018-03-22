#include <bits/stdc++.h>

#define WHITE  -1 
#define RED     0
#define BLACK   1

using namespace std;

const int MAX_V = 310;

int V, a, b, color[MAX_V];
vector <int> AdjList[MAX_V];
bool vis[MAX_V];

bool isBipartite(int source){
   bool isOK = true;
   queue <int> Q;
   Q.push(source);
   fill(color, color + V + 1, WHITE);
   color[source] = RED;
   while( not Q.empty() and isOK ){
      int u = Q.front(); Q.pop();
      vis[u] = true;
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
   bool ret = true;
   for(int u = 1; u <= V; u++)
      if( not vis[u] ) ret &= isBipartite(u);
   puts( ret ? "YES" : "NO" );
}

void read(){
   while(scanf("%d %d", &a, &b), a | b){
      AdjList[a].push_back(b);
      AdjList[b].push_back(a);
   }
}

void clean(){
   fill(vis, vis + V + 1, false);
   for(int u = 1; u <= V; u++) AdjList[u].clear();
}

int main(){
   while(scanf("%d", &V), V){
      read();
      solve();
      clean();
   }
}
