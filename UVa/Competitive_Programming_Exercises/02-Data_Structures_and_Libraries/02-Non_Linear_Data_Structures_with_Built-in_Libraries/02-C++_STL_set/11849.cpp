#include <bits/stdc++.h>

using namespace std;

int n, m, num, ans;

int main(){
   while(scanf("%d %d", &n, &m), n | m){
      set <int> v;
      ans = 0;
      for(int i = 0; i < n; i++) scanf("%d", &num), v.insert(num);
      for(int i = 0; i < m; i++){
         scanf("%d", &num);
         if(v.find(num) != v.end()) ans++;
      }
      printf("%d\n", ans);
   }
   return(0);
}
