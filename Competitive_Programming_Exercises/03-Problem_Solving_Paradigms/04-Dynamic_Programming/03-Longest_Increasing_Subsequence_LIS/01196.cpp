#include <bits/stdc++.h>

using namespace std;

int n, lis[10010], LIS, pos;
vector < pair <int, int> > u(10010);
vector <int> v(10010);

int main(){
   while(scanf("%d",&n), n){
      LIS = 0;
      for(int i = 0; i < n; i++) scanf("%d %d", &u[i].first, &u[i].second);
      sort(u.begin(), u.begin() + n);
      for(int i = 0; i < n; i++) v[i] = u[i].second;
      for(int i = 0; i < n; i++){
         pos = lower_bound(lis, lis + LIS, v[i] + 1) - lis;
         lis[pos] = v[i];
         if(pos + 1 > LIS) LIS = pos + 1;
      }
      printf("%d\n", LIS);
   }
   puts("*");
   return(0);
}
