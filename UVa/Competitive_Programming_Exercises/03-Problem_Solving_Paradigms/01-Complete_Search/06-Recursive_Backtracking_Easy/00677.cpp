#include <bits/stdc++.h>

using namespace std;

int n, m, foo, tmp;
vector <int> a[11], x;
bool ok, visited[11];

void backtracking(int p){
   if(x.size() == m + 1){
      putchar('(');
      for(int i = 0; i < x.size(); i++)
         i != x.size() - 1 ? printf("%d,", x[i]) : printf("%d)\n", x[i]);
      ok = false;
      return;
   }
   for(int i = 0; i < a[p].size(); i++){
      if(!visited[a[p][i]]){
         visited[a[p][i]] = true;
         x.push_back(a[p][i]);
         backtracking(a[p][i]);
         visited[a[p][i]] = false;
         x.pop_back();
      }     
   }  
}

int main(){
   visited[1] = true;
   x.push_back(1);
   while(scanf("%d%d", &n, &m) == 2){
      for(int i = 0; i < n; i++)
         for(int j = 0; j < n; j++){
            scanf("%d", &tmp);
            if(tmp)
               a[i + 1].push_back(j + 1);
         }
      ok = true;
      backtracking(1);
      if(ok)
         printf("no walk of length %d\n", m);
      for(int i = 1; i <= n; i++)
         a[i].clear();
      if(scanf("%d", &foo) == 1)
         putchar('\n');
   }
   return(0);
}
