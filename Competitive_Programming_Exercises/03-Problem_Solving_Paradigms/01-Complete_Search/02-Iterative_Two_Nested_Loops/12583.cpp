#include <bits/stdc++.h>

using namespace std;

int tc, n, k, ans;
vector <int> ct[26];
char s[510];

int main(){
   scanf("%d", &tc);
   for(int t = 1; t <= tc; t++){
      scanf("%d %d %s", &n, &k, s);
      ans = 0;
      for(int i = 0; i < 26; i++) ct[i].clear();
      for(int i = 0; i < n; i++)
         ct[s[i] - 'A'].push_back(i);
      for(int i = 0; i < 26; i++)
         for(int j = 1; j < ct[i].size(); j++)
            if(ct[i][j] - ct[i][j - 1] <= k) ans++;
      printf("Case %d: %d\n", t, ans);
   }
   return(0);
}
