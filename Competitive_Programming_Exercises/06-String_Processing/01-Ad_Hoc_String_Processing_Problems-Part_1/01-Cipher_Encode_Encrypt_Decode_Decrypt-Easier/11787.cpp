#include <bits/stdc++.h>

using namespace std;

const int LEN = 510;

int tc, ans, pre, cur;
char line[LEN];
map <char, int> mp, ct;
string s = "MTFPSUB";
bool flag, pos, neg;

int main(){
   mp['B'] = 1, mp['U'] = 2, mp['S'] = 3, mp['P'] = 4;
   mp['F'] = 5, mp['T'] = 6, mp['M'] = 7;
   scanf("%d\n", &tc);
   while(tc--){
      flag = pos = neg = false;
      ct.clear();
      scanf("%s", line);
      for(int it = 0; line[it] and not flag; it++){
         ct[line[it]]++;
         if( ct[line[it]] == 10 ){
            puts("error");
            flag = true;
         }
      }
      if( flag ) continue;
      pre = mp[line[0]];
      for(int it = 1; line[it]; it++){
         cur = mp[line[it]];
         if( cur - pre > 0 ) pos = true;
         if( cur - pre < 0 ) neg = true;
         pre = cur;
      }
      if( pos and neg ){
         puts("error");
         continue;
      }
      ans = 0;
      for(int it = 0; it < s.size(); it++)
         ans = 10 * ans + ct[s[it]];
      printf("%d\n", ans);
   }
   return(0);
}
