#include <bits/stdc++.h>

using namespace std;

int tc, ct, n, m, q, d[110], p, ans;
string s1, s2, _source, _target;
vector <int> G[110];
map <string, int> vert;

int bfs(int source, int target){
   for(int i = 0; i < ct; i++) d[i] = -1;
   queue <int> Q;
   Q.push(source), d[source] = 0;
   while(!Q.empty()){
      int u = Q.front(); Q.pop();
      for(int i = 0; i < G[u].size(); i++){
         int v = G[u][i];
         if(d[v] == -1)
            d[v] = d[u] + 1, Q.push(v);
      }
      if(d[target] != -1) return d[target] * 100 * p;
   }
   return -1;
}

int main(){
   scanf("%d\n", &tc);
   puts("SHIPPING ROUTES OUTPUT");
   for(int t = 1; t <= tc; t++){
      putchar('\n');
      printf("DATA SET  %d\n\n",t);
      for(int i = 0; i < ct; i++) G[i].clear();
      vert.clear(), ct = 0;
      scanf("%d %d %d", &n, &m, &q);
      for(int i = 0; i < n; i++) cin >> s1, vert[s1] = ct++;
      for(int i = 0; i < m; i++) cin >> s1 >> s2, G[vert[s1]].push_back(vert[s2]), G[vert[s2]].push_back(vert[s1]);
      while(q--){
         cin >> p >> _source >> _target;
         ans = bfs(vert[_source], vert[_target]);
         if(ans == -1) puts("NO SHIPMENT POSSIBLE");
         else printf("$%d\n", ans);
      }
   }
   putchar('\n');
   puts("END OF OUTPUT");
   return(0);
}
