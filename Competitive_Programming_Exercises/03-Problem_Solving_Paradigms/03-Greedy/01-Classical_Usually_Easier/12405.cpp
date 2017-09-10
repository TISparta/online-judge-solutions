#include <bits/stdc++.h>

using namespace std;

int tc, n, ans;
char s[105];

int main(){
   scanf("%d", &tc);
   for(int t = 1; t <= tc; t++){
      scanf("%d", &n);
      scanf("%s", s);
      ans = 0;
      for(int i = 0; i < n; i++){
         if(s[i] == '#') continue;
         ans++;
         s[i] = s[i + 1] = s[i + 2] = '#';
      }
      printf("Case %d: %d\n", t, ans);
   }
   return(0);
}
