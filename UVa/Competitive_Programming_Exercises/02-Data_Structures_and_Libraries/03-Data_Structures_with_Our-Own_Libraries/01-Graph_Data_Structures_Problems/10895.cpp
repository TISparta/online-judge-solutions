#include <bits/stdc++.h>

using namespace std;

vector < pair<int,int> > a[10005];
int aux[10005];

int main(){
   int n, m, r, tmp, k;
   while(scanf("%d %d", &n, &m) != EOF){
      k = 1;
      for(int i = 0; i < n; i++){
         scanf("%d", &r);
            for(int j = 0;j < r; j++)
               scanf("%d", &aux[j]);
            for(int j = 0;j < r; j++){
               scanf("%d", &tmp);
               a[aux[j]].push_back( make_pair(tmp, k) );
            }
         k++;
      }
      printf("%d %d\n", m, n);
      for(int i = 1; i <= m; i++){
         cout<<a[i].size();
         for(int j = 0; j < a[i].size(); j++)
            printf(" %d", a[i][j].second);
         putchar('\n');
         for(int j = 0;j < a[i].size(); j++){
            if(j) putchar(' ');
            printf("%d", a[i][j].first);
         }
         putchar('\n');
      }
      for(int i = 0; i < 10005; i++) a[i].clear();
   }
   return(0);
}
