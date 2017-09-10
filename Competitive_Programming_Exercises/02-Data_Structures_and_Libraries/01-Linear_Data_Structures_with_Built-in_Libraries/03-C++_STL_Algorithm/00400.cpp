#include <bits/stdc++.h>

using namespace std;

int n, ml, nr, nc, it;
vector <string> s;

void sep(){
   for(int i = 0; i < 60; i++) putchar('-');
   putchar('\n');
}

int main(){
   while(scanf("%d\n", &n) == 1){
      s.resize(n), ml = -1;
      for(int i = 0; i < n; i++) cin>>s[i], ml = max(ml, (int)s[i].size());
      sort(s.begin(), s.end());
      sep();
      nc = 62 / (ml + 2), nr = (n + nc - 1) / nc, it = 0;
      ml += 2;
      vector <vector <string> > v(nr, vector <string> (nc));
      for(int j = 0; j < nc; j++)
         for(int i = 0; i < nr; i++){
            v[i][j] = s[it++];
            if(it == n) i = j = 110;
         }
      for(int i = 0; i < nr; i++){
         for(int j = 0; j < nc; j++)
            if(j != nc-1 && !v[i][j + 1].empty()) printf("%-*s", ml, v[i][j].c_str());
            else printf("%s\n", v[i][j].c_str()), j = nc;
      }
   }
   return(0);
}
