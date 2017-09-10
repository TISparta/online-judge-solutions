#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 110, LEN = 60;

int tc, V, E, inDegree[MAX_V];
char word[MAX_V][LEN], word1[LEN], word2[LEN];
vector <int> AdjList[MAX_V], ts;
map <string, int> mp;

void TopologicalSort(){
   priority_queue <int, vector <int>, greater <int> > pq;
   for(int u = 0; u < V; u++) if( inDegree[u] == 0 ) pq.push(u);
   while( not pq.empty() ){
      int u = pq.top(); pq.pop();
      ts.push_back(u);
      for(int j = 0; j < AdjList[u].size(); j++){
         int v = AdjList[u][j];
         inDegree[v]--;
         if( inDegree[v] == 0 ) pq.push(v);
      }
   }
}

void solve(){
   TopologicalSort();
   printf("Case #%d: Dilbert should drink beverages in this order:", ++tc);
   for(int i = 0; i < V; i++) printf( i == V - 1 ? " %s.\n\n" : " %s", word[ts[i]]);
}

void read(){
   for(int i = 0; i < V; i++){
      scanf("%s", word[i]);
      mp[word[i]] = i;
   }
   scanf("%d\n", &E);
   for(int i = 0; i < E; i++){
      scanf("%s %s", word1, word2);
      int u = mp[word1], v = mp[word2];
      AdjList[u].push_back(v);
      inDegree[v]++;
   }
}

void clear(){
   mp.clear();
   ts.clear();
   for(int i = 0; i < V; i++) AdjList[i].clear(), inDegree[i] = 0;
}

int main(){
   while(scanf("%d\n", &V) == 1){
      read();
      solve();
      clear();
   }
   return(0);
}
