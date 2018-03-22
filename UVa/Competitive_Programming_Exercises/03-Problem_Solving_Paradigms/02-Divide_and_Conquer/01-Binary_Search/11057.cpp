#include <bits/stdc++.h>

using namespace std;

int n, m, min_dif;
vector <int> a;
pair <int, int> ans;

int main(){
   while(scanf("%d", &n) == 1){
      a.resize(n);
      for(int i = 0; i < n; i++) scanf("%d", &a[i]);
      sort(a.begin(), a.end());
      scanf("%d", &m);
      min_dif = INT_MAX;
      for(int i = 0; i < n; i++){
         if(abs(a[i] - (m - a[i])) < min_dif && binary_search(a.begin(), a.end(), m - a[i]))
            ans = make_pair(a[i], m - a[i]), min_dif = abs(a[i] - (m - a[i]));
      }
      printf("Peter should buy books whose prices are %d and %d.\n\n", ans.first, ans.second);
      a.clear();
   }
   return(0);
}
