#include <bits/stdc++.h>

using namespace std;

int tc, n, m, num, a, b, ans;

int main(){
   scanf("%d", &tc);
   while(tc--){
      multiset <int> u, v;
      set <int> visited;
      ans = 0;
      scanf("%d %d", &n, &m);
      for(int i = 0; i < n; i++) scanf("%d", &num), u.insert(num);
      for(int i = 0; i < m; i++) scanf("%d", &num), v.insert(num);
      for(multiset <int> ::iterator it = u.begin(); it != u.end(); ++it){
         if(visited.find(*it) == visited.end()){
            a = u.count(*it), b = 0;
            if(v.find(*it) != v.end()) b = v.count(*it), v.erase(*it);
            visited.insert(*it);
            ans += abs(a - b);
         }
      }
      ans += v.size();
      printf("%d\n", ans);
   }
   return(0);
}
