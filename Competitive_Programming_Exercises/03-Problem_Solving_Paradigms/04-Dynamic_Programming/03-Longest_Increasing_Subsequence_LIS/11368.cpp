#include <bits/stdc++.h>

using namespace std;

int tc, n, lis[20010], LIS, pos, ans;
vector < pair <int, int> > u(20010);
vector <int> v, w;

bool cmp(const pair <int, int> p1, const pair <int, int> p2){
   return (p1.second > p2.second || (p1.second == p2.second && p1.first < p2.first) );
}

int main(){
   scanf("%d", &tc);
   while(tc--){
      v.clear(), ans = LIS = 0;
      scanf("%d", &n);
      for(int i = 0; i < n; i++) scanf("%d %d", &u[i].first, &u[i].second);
      sort(u.begin(), u.begin() + n, cmp);
      for(int i = 0; i < n; i++) v.push_back(u[i].first);
      for(int i = 0; i < n; i++){
         pos = lower_bound(lis, lis + LIS, v[i] + 1) - lis;
         lis[pos] = v[i];
         if(pos + 1 > LIS) LIS = pos + 1, ans++;
      }
      printf("%d\n", ans);
   }
   return(0);
}
