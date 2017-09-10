#include <bits/stdc++.h>

using namespace std;

int tc, n;
string s1, s2, _source, _target;
map <string, int> d;
map <string, string> path;
map <string, vector<string> >G;

void printPath(string source, string target){
   if(source == target) return;
   printPath(source, path[target]);
   cout << path[target] << ' ' << target << endl;
}

int bfs(string source, string target){
   queue <string> Q;
   Q.push(source), d[source] = 0;
   while(!Q.empty()){
      string u = Q.front(); Q.pop();
      if(u == target) return d[u];
      for(int i = 0; i < (int)G[u].size(); i++){
         string v = G[u][i];
         if(d[v] == -1)
            d[v] = d[u]+1, path[v] = u, Q.push(v);
      }
   }
   return -1;
}

int main(){
   while(scanf("%d", &n) == 1){
      G.clear();
      if(tc++) putchar('\n');
      for(int i = 0; i < n; i++){
         cin >> s1 >> s2;
         G[s1].push_back(s2);
         G[s2].push_back(s1);
         d[s1] = d[s2] = -1;
      }
      cin >> _source >> _target;
      if(bfs(_source, _target) == -1) printf("No route\n");
      else printPath(_source, _target);
   }
   return(0);
}
