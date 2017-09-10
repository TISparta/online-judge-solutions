#include <bits/stdc++.h>

using namespace std;

int tc, N, L, corner, mid, diagonal, table, v[100];
int m[1000][5][5], money[1000];
bool x[1000][5][5], ok_corner[1000], ok_mid[1000], ok_diagonal[1000], ok_table[1000];

void reset(){
   for(int p = 0; p < L; p++)
      for(int i = 0; i < 5; i++)
         for(int j = 0; j < 5; j++)
            x[p][i][j] = false;
   for(int p = 0; p < L; p++)
      money[p] = ok_corner[p] = ok_mid[p] = ok_diagonal[p] = ok_table[p] = false;
}

void check(int ball, int p){
   if(ball <= 35 && !ok_corner[p]){
      if(x[p][0][0] && x[p][4][0] && x[p][0][4] && x[p][4][4])
         money[p] += corner, ok_corner[p] = true;
   }
   if(ball <= 40 && !ok_mid[p]){
      if(x[p][2][0] && x[p][2][1] && x[p][2][2] && x[p][2][3] && x[p][2][4])
         money[p] += mid, ok_mid[p] = true;
   }
   if(ball <= 45 && !ok_diagonal[p]){
      if(x[p][0][0] && x[p][1][1] && x[p][2][2] && x[p][3][3] && x[p][4][4] &&
         x[p][0][4] && x[p][1][3] && x[p][3][1] && x[p][4][0])
         money[p] += diagonal, ok_diagonal[p] = true;
   }
   if(ball >= 25 && !ok_table[p]){
      for(int i = 0; i < 5; i++)
         for(int j = 0; j < 5; j++)
            if(!x[p][i][j]) return;
      money[p] += table, ok_table[p] = true;
   }
}

void fillNumber(int num, int p){
   for(int i = 0; i < 5; i++)
      for(int j = 0; j < 5; j++)
         if(m[p][i][j] == num){
            x[p][i][j] = true;
            return;
         }
}

int main(){
   scanf("%d", &tc);
   for(int t = 1; t <= tc; t++){
      scanf("%d %d", &N, &L);
      for(int i = 0; i < N; i++) scanf("%d", &v[i]);
      scanf("%d %d %d %d", &corner, &mid, &diagonal, &table);
      for(int p = 0; p < L; p++)
         for(int i = 0; i < 5; i++)
            for(int j = 0; j < 5; j++)
               scanf("%d", &m[p][i][j]);
      for(int i = 0; i < N; i++)
         for(int j = 0; j < L; j++)
            fillNumber(v[i], j), check(i + 1, j);
      printf("Case %d:\n", t);
      for(int i = 0; i < L; i++)
         printf("%d\n",money[i]);
      if(t != tc) putchar('\n');
      reset();
   }
   return(0);
}
