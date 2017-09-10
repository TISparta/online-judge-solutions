#include <bits/stdc++.h>

using namespace std;

int tc, C, R, pib, it;
vector <int> ans;

int main(){
   scanf("%d", &tc);
   for(int t = 1; t <= tc; t++){
      ans.clear();
      scanf("%d %d", &C, &R);
      pib = C - R;
      for(it = 1; it * it < pib; it++)
         if(pib % it==0){
            if(it > R) ans.push_back(it);
            if(pib / it >R) ans.push_back(pib / it);
         }
      if(it * it==pib && it > R) ans.push_back(it);
      if(R - C > R) ans.push_back(R - C);
      sort(ans.begin(), ans.end());
      printf("Case #%d:", t);
      for(int i = 0;i < ans.size(); i++) printf(" %d", ans[i]);
      if(R == C) printf(" 0");
      putchar('\n');
   }
   return(0);
}
