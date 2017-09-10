#include <bits/stdc++.h>

using namespace std;

int tc, ans, v[5][5], u[5][5];
int x[] = {-1, 0, 0, 1};
int y[] = {0, 1, -1, 0};

bool check(){
   for(int i = 1; i <= 3; i++)
      for(int j = 1; j <= 3; j++) if(v[i][j]) return true;
   return false;
}

void transform(){
   for(int i = 1; i <= 3; i++)
      for(int j = 1; j <= 3; j++){
         u[i][j] = 0;
         for(int it = 0; it < 4; it++)
            u[i][j] ^= v[i + x[it]][j + y[it]];
      }
   for(int i = 1; i <= 3; i++)
      for(int j = 1; j <= 3; j++) v[i][j] = u[i][j];
}

int main(){
   scanf("%d", &tc);
   while(tc--){
      ans = -1;
      for(int i = 1; i <= 3; i++)
         for(int j = 1; j <= 3; j++) scanf("%1d", &v[i][j]);
      while(check()){
         transform();
         ans++;
      }
      printf("%d\n", ans);
   }
   return(0);
}
