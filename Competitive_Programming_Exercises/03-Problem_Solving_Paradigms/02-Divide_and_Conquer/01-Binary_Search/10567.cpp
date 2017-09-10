#include <bits/stdc++.h>

using namespace std;

char s[1000100];
vector <int> v[130];
int q, ans1, ans2, p;
bool ok;

int main(){
   scanf("%s\n", s);
   for(int i = 0, j = strlen(s); i < j; i++) v[s[i]].push_back(i);
   scanf("%d", &q);
   while(q--){
      scanf("%s", s);
      ans2 = -69;
      ok = true;
      for(int i = 0, j = strlen(s); i < j; i++){
         p = upper_bound(v[s[i]].begin(), v[s[i]].end(), ans2)-v[s[i]].begin();
         if(p == v[s[i]].size()){
            ok = false;
            break;
         }
         ans2 = v[s[i]][p];
         if(i==0) ans1 = v[s[i]][p];
      }
      if(ok) printf("Matched %d %d\n", ans1, ans2);
      else printf("Not matched\n");
   }
   return(0);
}
