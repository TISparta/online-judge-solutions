#include <bits/stdc++.h>

using namespace std;

typedef pair <int,int> pii;

int tc, l, r, M, pib, _max;
vector <pii> v,ans;

int main(){
   scanf("%d", &tc);
   while(tc--){
      v.clear(), ans.clear();
      scanf("%d", &M);
      while(scanf("%d %d", &l, &r), l + r) v.push_back( make_pair(l, r) );
      sort(v.begin(), v.end());
      l = _max = 0;
      for(int i = 0; i < v.size(); i++){
         pib = -1;
         for(int j = i; j < v.size(); j++){
            if(v[j].first > l){
               i = j - 1;
               break;
            }
            if(v[j].second > _max) _max = v[j].second, pib = j;
         }
         if(pib == -1) break;
         ans.push_back(v[pib]), l = _max;
         if(_max >= M) break;
      }
      if(ans.back().second < M) ans.clear();
      printf("%d\n", (int)ans.size());
      for(int i = 0; i < ans.size(); i++) printf("%d %d\n", ans[i].first, ans[i].second);
      if(tc) putchar('\n');
   }
   return(0);
}
