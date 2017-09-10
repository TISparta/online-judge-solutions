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
   while( not Q.empty() and isOK ){
      int u = Q.front(); Q.pop();
      if( color[u] == RED ) red++;
      if( color[u] == BLACK ) black++;
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

int t;

void solve(){
   bool ret = true;
   fill(color, color + V, WHITE), ans = 0;
   for(int i = 0; i < V and ret; i++)
      if( color[i] == WHITE ){
         ret &= isBipartite(i);
         ans += ( min(red, black) != 0 ) ? min(red, black) : max(red, black);
      }
   if( not ret ) ans = -1;
   printf("%d\n", ans);
}

void read(){
   scanf("%d %d", &V, &E);
   for(int i = 0; i < E; i++){
      scanf("%d %d", &a, &b);
      AdjList[a].push_back(b);
      AdjList[b].push_back(a);
   }
}

void clear(){
   for(int u = 0; u < V; u++) AdjList[u].clear();
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
