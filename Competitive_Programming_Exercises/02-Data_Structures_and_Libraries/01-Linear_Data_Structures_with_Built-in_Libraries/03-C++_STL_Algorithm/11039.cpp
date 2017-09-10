#include <bits/stdc++.h>


using namespace std;

int tc, n, tmp, j, ans;

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%d", &n);
      vector < pair <int, bool> > v;
      for(int i = 0; i < n; i++) scanf("%d", &tmp), v.push_back( make_pair(abs(tmp), (tmp > 0)) );
      sort(v.begin(), v.end());
      ans = 0;
      for(int i = 0; i < n;){
         for(j = i; j < n;j++)
         if(v[i].second != v[j].second){
            ans++;
            break;
         }
         i = j;
      }
      if(n != 0) ans++;
      printf("%d\n", ans);
   }
   return(0);
}
