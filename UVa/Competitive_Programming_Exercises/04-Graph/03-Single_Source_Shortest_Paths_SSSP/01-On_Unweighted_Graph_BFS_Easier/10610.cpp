#include <bits/stdc++.h>

using namespace std;

int _speed, _time, ct, d[1010], ans, a1, a2, b1, b2;
pair <float,float> pos[1010];
char s[20];
vector <int> G[1010];

bool relation(pair <float, float> p1, pair<float, float> p2){
   float d = sqrt( (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second ) * (p1.second - p2.second) );
   return (d / _speed <= _time * 60);
}

int bfs(int source, int target){
   if(relation(pos[0], pos[1])) return 0;
   for(int i = 0; i < ct; i++) d[i] = -1;
   queue <int> Q;
   Q.push(source), d[source] = 0;
   while(!Q.empty()){
      int u = Q.front(); Q.pop();
      if(u == target) return d[u]-1;
      for(int i = 0; i < G[u].size(); i++){
         int v = G[u][i];
         if(d[v] == -1)
            d[v] = d[u] + 1, Q.push(v);
      }  
   }
   return -1;
}

int main(){
   while(scanf("%d %d", &_speed, &_time), _speed | _time){
      for(int i = 0; i < ct; i++) G[i].clear();
      ct = 2;
      scanf("%f %f", &pos[0].first, &pos[0].second);
      scanf("%f %f", &pos[1].first, &pos[1].second);
      getchar();
      while(true){
         cin.getline(s, 20);
         if(sscanf(s,"%d.%d %d.%d", &a1, &a2, &b1, &b2) != 4) break;
         pos[ct++] = make_pair(a1 + (float)a2 / 1000, b1 + (float)b2 / 1000);
      }
      for(int i = 0; i < ct; i++)
         for(int j = i + 1; j < ct; j++)
            if(relation(pos[i], pos[j]))
               G[i].push_back(j), G[j].push_back(i);
      ans = bfs(0, 1);
      if(ans == -1) puts("No.");
      else printf("Yes, visiting %d other holes.\n", ans);
   }
   return(0);
}
