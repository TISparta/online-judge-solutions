#include <bits/stdc++.h>

using namespace std;

int tc, R, C, m, ans, tmp, aux;
vector <int> v[55];

int main(){
   scanf("%d", &tc);
   for(int t = 1; t <= tc; t++){
      ans = -1;
      scanf("%d %d", &R, &C);
      for(int i = 0; i < R; i++)
         for(int j = 0; j < C; j++){
            scanf("%1d", &m);
            if(!m) v[i].push_back(j);
         }
      for(int i = 0; i < R; i++){
         if(!v[i].size()){
            ans = -1;
            break;
         }
         for(int j = 0; j < v[i].size(); j++){
            aux = 0;
            for(int p = 0; p < R; p++){
               tmp = 100000;
               for(int q = 0; q < v[p].size(); q++)
                  tmp = min(tmp, abs(v[p][q] - v[i][j]));
               aux += tmp;
            }
            if(aux<ans || ans == -1) ans = aux;
         }
      }
      printf("Case %d: %d\n", t, ans);
      for(int i = 0; i < R; i++) v[i].clear();
   }
   return(0);
}
