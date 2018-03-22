#include <bits/stdc++.h>

#define MAX 25

using namespace std;

int T, R, H, TR[MAX][MAX], RH[MAX][MAX], HT[MAX][MAX];
int ans_T, ans_R, ans_H, ans_P, p, _min;
bool ok;

int main(){
   while(scanf("%d %d %d", &T, &R, &H) == 3){
      ok = false, _min = INT_MAX;
      for(int i = 0; i < T; i++)
         for(int j = 0; j <= R; j++)
            scanf("%d", &TR[i][j]);
      for(int i = 0; i < R; i++)
         for(int j = 0; j <= H; j++)
            scanf("%d", &RH[i][j]);
      for(int i = 0; i < H; i++)
         for(int j = 0; j <= T; j++)
            scanf("%d", &HT[i][j]);
      for(int t = 0; t < T; t++)
         for(int r = 0; r < R; r++)
            for(int h = 0; h < H; h++)
               if(!TR[t][r + 1] && !RH[r][h + 1] && !HT[h][t + 1]){
                  ok = true;
                  p = TR[t][0] + RH[r][0] + HT[h][0];
                  if(p < _min)
                     _min = p, ans_T = t, ans_R = r, ans_H = h, ans_P = p;
               }
      if(ok) printf("%d %d %d:%d\n", ans_T, ans_R, ans_H, ans_P);
      else  printf("Don't get married!\n");
   }
   return(0);
}
