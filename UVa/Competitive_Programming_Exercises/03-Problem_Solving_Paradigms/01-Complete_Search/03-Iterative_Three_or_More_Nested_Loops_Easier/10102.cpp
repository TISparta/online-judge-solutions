#include <bits/stdc++.h>

using namespace std;

int n, m[1000][1000], ans, tmp;
vector < pair <int, int> > v, w;

int main(){
   while(scanf("%d", &n) == 1){
      ans = 0, v.clear(), w.clear();
      for(int i = 0; i < n; i++)
         for(int j = 0; j < n; j++){
            scanf("%1d", &m[i][j]);
            if(m[i][j] == 1) v.push_back(make_pair(i, j));
            else if(m[i][j] == 3) w.push_back(make_pair(i, j));
         }
      for(int i = 0; i < v.size(); i++){
         tmp = INT_MAX;
         for(int j = 0; j < w.size(); j++)
            tmp = min(tmp, abs(w[j].first - v[i].first) + abs(w[j].second - v[i].second));
         ans = max(ans, tmp);
      }
      printf("%d\n", ans);
   }
   return(0);
}
