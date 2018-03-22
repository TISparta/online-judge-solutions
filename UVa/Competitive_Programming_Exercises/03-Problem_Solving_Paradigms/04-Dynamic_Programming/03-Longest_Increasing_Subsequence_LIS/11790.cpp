#include <bits/stdc++.h>

#define rs resize

using namespace std;

int tc, n, ans_lis, ans_lds, ans_wlis, ans_wlds;
vector <int> v, w, wlis, wlds;

int main(){
   scanf("%d", &tc);
   for(int t = 1; t <= tc; t++){
      scanf("%d", &n);
      v.rs(n), w.rs(n), wlis.rs(n), wlds.rs(n);
      for(int i = 0; i < n; i++) scanf("%d", &v[i]);
      for(int i = 0; i < n; i++) scanf("%d", &w[i]);
      ans_wlis = ans_wlds = 0;
      for(int i = 0; i < n; i++){
         wlis[i] = wlds[i] = w[i];
         for(int j = 0; j < i; j++){
            if(v[i] > v[j] && wlis[i] < wlis[j] + w[i])
               wlis[i] = wlis[j] + w[i];
            if(v[i] < v[j] && wlds[i] < wlds[j] + w[i])
               wlds[i] = wlds[j] + w[i];
         }
         if(wlis[i] > ans_wlis) ans_wlis = wlis[i];
         if(wlds[i] > ans_wlds) ans_wlds = wlds[i];  
      }
      if(ans_wlis >= ans_wlds)
         printf("Case %d. Increasing (%d). Decreasing (%d).\n", t, ans_wlis, ans_wlds);
      else
         printf("Case %d. Decreasing (%d). Increasing (%d).\n", t, ans_wlds, ans_wlis);
   }
   return(0);
}
