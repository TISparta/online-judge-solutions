#include <bits/stdc++.h>

using namespace std;

int n, m, t, q;
vector <int> a;

int main(){
   while(scanf("%d %d", &n, &m), n | m){
      a.resize(n);
      for(int i = 0; i < n; i++) scanf("%d", &a[i]);
      printf("CASE# %d:\n", ++t);
      sort(a.begin(), a.end());
      for(int i = 0; i < m; i++){
         scanf("%d", &q);
         if(!binary_search(a.begin(), a.end(), q)) printf("%d not found\n", q);
         else printf("%d found at %d\n", q, (int)(lower_bound(a.begin(), a.end(), q) - a.begin() + 1));
      }
      a.clear();
   }
   return(0);
}
