#include <bits/stdc++.h>

using namespace std;

int n, m, b, br, bc, bn, mt[1005][1005], d[10000000];
int sx, sy, tx, ty, _source, _target;
int xx[] = {-1, 0, 0, 1};
int yy[] = {0, 1, -1, 0};

int bfs(int source){
   for(int i = 0;i < n * m; i++) d[i] = -1;
   queue <int> Q;
   Q.push(source);
   d[source] = 0;
   while(!Q.empty()){
      int u = Q.front();
      Q.pop();
      int x = u / m, y = u % m;
      for(int i = 0; i < 4; i++){
         int _x = x + xx[i], _y = y + yy[i], v = _x * m + _y;
         if(_x >= 0 && _y >= 0 && _x < n && _y < m && mt[_x][_y] && d[v] == -1)
            d[v] = d[u] + 1, Q.push(v);
      }
      if(d[_target] != -1) return d[_target];
   }
}

int main(){
   while(scanf("%d %d", &n, &m), n | m){
      for(int i = 0; i < n; i++)
         for(int j = 0; j < m; j++) mt[i][j] = true;
      scanf("%d", &b);
      for(int i = 0; i < b; i++){
         scanf("%d %d", &br, &bn);
         for(int j = 0; j < bn; j++) scanf("%d", &bc), mt[br][bc] = false;
      }
      scanf("%d %d", &sx, &sy);
      scanf("%d %d", &tx, &ty);
      _source = sx * m + sy;
      _target = tx * m + ty;
      printf("%d\n", bfs(_source));     
   }
   return(0);
}
