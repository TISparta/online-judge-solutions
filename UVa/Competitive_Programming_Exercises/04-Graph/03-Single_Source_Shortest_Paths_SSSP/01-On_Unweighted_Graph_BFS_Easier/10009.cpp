#include <bits/stdc++.h>

using namespace std;

int tc, m, q;
string s1, s2, u, v, _source, _target;
map <string, vector <string> > G;
set <string> vert;
map <string, int> d;
map <string, string> p;

void printPath(string u){
   if(u == _source){
      printf("%c", _source[0]);
      return;
   }
   printPath(p[u]);
   printf("%c", u[0]);
}

void bfs(string source){
   for(auto it : vert) d[it] = -1;
   queue <string> Q;
   Q.push(source), d[source] = 0;
   while(!Q.empty()){
      u = Q.front(), Q.pop();
      for(int i = 0; i < G[u].size(); i++){
         v = G[u][i];
         if(d[v] == -1)
            d[v] = d[u] + 1, p[v] = u, Q.push(v);
      }
      if(d[_target] != -1) return;
   }
}

int main(){
   scanf("%d", &tc);
   while(tc--){
      G.clear(), vert.clear();
      scanf("%d %d\n", &m, &q);
      for(int i = 0; i < m; i++){
         cin >> s1 >> s2;
          G[s1].push_back(s2), G[s2].push_back(s1);
         vert.insert(s1), vert.insert(s2);
      }
      while(q--){
         cin >> _source >> _target;
         bfs(_source);
         printPath(_target), putchar('\n');
      }
      if(tc) putchar('\n');
   }
   return(0);
}
