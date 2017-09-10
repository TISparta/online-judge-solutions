#include <bits/stdc++.h>

using namespace std;

int n, alis[10010], alds[10010], lis[10010], lds[10010], LIS, LDS, pos, ans;
vector <int> v;

int main(){
   while(scanf("%d", &n) != EOF){
      v.resize(n), LIS = LDS = 0;
      for(int i = 0; i < n; i++) scanf("%d", &v[i]);
      for(int i = 0; i < n; i++){
         pos = lower_bound(alis, alis + LIS, v[i]) - alis;
         alis[pos] = v[i];
         lis[i] = pos + 1;
         if(pos + 1 > LIS) LIS = pos + 1;
      }
      reverse(v.begin(), v.end());
      for(int i = 0; i < n; i++){
         pos = lower_bound(alds, alds + LDS, v[i]) - alds;
         alds[pos] = v[i];
         lds[i] = pos + 1;
         if(pos + 1 > LDS) LDS = pos + 1;
      }
      ans = 0;
      for(int i = 0; i < n; i++) ans = max(ans, min(lis[i], lds[n - 1 - i]));
      printf("%d\n", (ans << 1) - 1);
   }
   return(0);
}
