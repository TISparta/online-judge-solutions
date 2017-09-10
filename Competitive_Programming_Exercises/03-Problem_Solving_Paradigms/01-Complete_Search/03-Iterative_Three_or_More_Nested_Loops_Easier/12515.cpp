#include <bits/stdc++.h>

using namespace std;

int M, Q, ct, _min, ans;
char s[1010][510], v[510];

int main(){
   scanf("%d %d", &M, &Q);
   getchar();
   for(int i = 0; i < M; i++)
      scanf("%s", s[i]);
   while(Q--){
      scanf("%s", v), _min = INT_MAX;
      for(int i = 0; i < M; i++)
         for(int pib = 0; pib < (int)strlen(s[i]) - (int)strlen(v) + 1; pib++){
            ct = 0;
            for(int j= pib; j < pib + strlen(v);j++)
               if(s[i][j] != v[j - pib]) ct++;
            if(ct < _min) _min = ct, ans = i + 1;
         }
      printf("%d\n", ans);
   }
   return(0);
}
