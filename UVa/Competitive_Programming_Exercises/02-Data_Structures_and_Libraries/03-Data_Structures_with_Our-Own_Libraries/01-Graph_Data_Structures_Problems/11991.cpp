#include <bits/stdc++.h>

using namespace std;

vector <int> a[1000005];

int main(){
   int n, m, tmp, x, y;
   while(scanf("%d %d", &n, &m) != EOF){
      for(int i = 1; i <= n; i++)
         scanf("%d", &tmp),
         a[tmp].push_back(i);
      for(int i = 0; i < m; i++){
         scanf("%d %d", &x, &y);
         if(a[y].size() < x)
            printf("0\n");
         else
            printf("%d\n",a[y][x - 1]);
      }
      for(int i = 0; i < 1000005; i++)
         a[i].clear();
   }
   return(0);
}
