#include <bits/stdc++.h>

using namespace std;

vector <int> a[50];
vector <bool> m(1000000);
bool v[1000000];
int n, ans, c;

void g(){
   for(int i = 1; i < 1000; i++)
      m[i * i] = true;
}

void f(int ct){
   for(int i = 0; i < n; i++)
      if(!a[i].size() || ( !v[ct] && m[a[i][a[i].size() - 1] + ct] )){
         a[i].push_back(ct);
         v[ct] = true;
         ans++;
         f(ct + 1);
      }
}

int main(){
   g();
   scanf("%d", &c);
   while(c--){
      scanf("%d", &n);
      f(1); 
      for(int i = 0; i < n; i++)
         a[i].clear();
      printf("%d\n", ans);
      ans = 0;
      memset(v, false, sizeof v);
   }
   return(0);
}
