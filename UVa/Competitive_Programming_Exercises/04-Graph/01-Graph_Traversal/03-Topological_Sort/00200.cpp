#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 30;

bool vis[MAX_V];
string s;
vector <int> AdjList[MAX_V], ts;
vector <string> word;

void dfs(int u){
   vis[u] = true;
   for(int j = 0; j < AdjList[u].size(); j++){
      int v = AdjList[u][j];
      if( not vis[v] ) dfs(v);
   }
   ts.push_back(u);
}

void TopologicalSort(){
   for(int u = 0; u < MAX_V; u++)
      if( not vis[u] and not AdjList[u].empty() )
         dfs(u);
}

void ConstructGraph(){
   for(int i = 0; i < word.size(); i++)
      for(int j = i + 1; j < word.size(); j++)
         for(int k = 0; k < min(word[i].size(), word[j].size()); k++){
            int u = word[i][k] - 'A', v = word[j][k] - 'A';
            if( u == v ) continue;
            AdjList[u].push_back(v);
            break;
         }
}

void solve(){
   ConstructGraph();
   TopologicalSort();
   for(int i = ts.size() - 1; i >= 0; i--) putchar(ts[i] + 'A');
   putchar('\n');
}

inline void read(){
   while(cin >> s, s[0] != '#') word.push_back(s);
}

int main(){
   read();
   solve();
   return(0);
}
