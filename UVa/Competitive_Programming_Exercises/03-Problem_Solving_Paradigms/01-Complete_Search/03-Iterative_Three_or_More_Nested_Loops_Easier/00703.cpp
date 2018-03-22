#include <bits/stdc++.h>

using namespace std;

int n, m[110][110], ct;
vector <int> ans[10000], v;
bool ok;

int main(){
   while(scanf("%d", &n) == 1){
      ct = 0;
      for(int i = 0; i < n; i++)
         for(int j = 0; j < n; j++)
            scanf("%d", &m[i][j]);
      for(int a = 0; a < n; a++)
         for(int b = 0; b < n; b++)
            for(int c = 0; c < n; c++)
               if( ( a < b && b < c ) || ( a > b && b > c ) ){
                  if( m[a][b] && m[b][c] && m[c][a]){
                     ans[ct].push_back(a + 1);
                     ans[ct].push_back(b + 1);
                     ans[ct++].push_back(c + 1);
                  }
                  else if( !m[a][b] && !m[b][c] && !m[c][a] && 
                           !m[b][a] && !m[c][b] && !m[a][c]){
                     v.clear();
                     v.push_back(a + 1);
                     v.push_back(b + 1);
                     v.push_back(c + 1);
                     sort(v.begin(),v.end());
                     ok = true;
                     for(int i = 0; i < ct; i++)
                        if(ans[i] == v){
                           ok = false;
                           break;
                        }
                     if(ok) ans[ct++] = v;
                  }
               }
      printf("%d\n", ct);
      for(int i = 0; i < ct; i++)
         printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]), ans[i].clear();
   }
   return(0);
}
