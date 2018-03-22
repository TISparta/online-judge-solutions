#include <bits/stdc++.h>

using namespace std;

struct tri{
   int x, y, size;
};

int m[1100][1100], _x, _y, _max, d, n, tc;
tri v[20010];

int main(){
   scanf("%d", &tc);
   while(tc--){
      _max = -1, _x = _y = INT_MAX;
      scanf("%d", &d);
      scanf("%d", &n);
      for(int i = 0; i < n; i++) scanf("%d %d %d", &v[i].x, &v[i].y, &v[i].size);
      for(int i = 0; i < n; i++)
         for(int p = max(1, v[i].x - d); p <= min(1025, v[i].x + d); p++)
            for(int q = max(1, v[i].y - d); q <= min(1025, v[i].y + d); q++)
               m[p][q] += v[i].size;
      for(int i = 1025; i >= 1; i--)
         for(int j = 1025; j >= 1; j--){
            if(m[i][j] >= _max)
               _max = m[i][j], _x = i, _y = j;
            m[i][j] = 0;
         }
      printf("%d %d %d\n", _x, _y, _max);
   }
   return(0);
}
