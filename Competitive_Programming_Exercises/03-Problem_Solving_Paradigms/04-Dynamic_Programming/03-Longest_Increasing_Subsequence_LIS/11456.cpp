#include <bits/stdc++.h>

using namespace std;

int tc, n, ans;
vector <int> v, lis, lds;

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%d", &n);
      v.resize(n), lis.resize(n), lds.resize(n);
      ans = 0;
      for(int i = 0; i < n; i++) scanf("%d", &v[i]), lis[i] = lds[i] = 1;
      for(int i = n - 1; i >= 0; i--){
         for(int j = i + 1; j < n; j++){
            if(v[i] > v[j] && lis[i] < lis[j] + 1)
               lis[i] = lis[j] + 1;
            if(v[i] < v[j] && lds[i] < lds[j] + 1)
               lds[i] = lds[j] + 1;
         }
         ans = max(ans, lis[i] + lds[i] - 1);
      }
      printf("%d\n", ans);
   }
   return(0);
}
