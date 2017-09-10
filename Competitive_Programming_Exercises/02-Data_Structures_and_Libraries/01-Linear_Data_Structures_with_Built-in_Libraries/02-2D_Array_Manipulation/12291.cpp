#include <bits/stdc++.h>

#define SIZE 15

using namespace std;

int n, m, lx, ly, rx, ry, row, column, r, c;
bool ans;
char u[SIZE][SIZE], v[SIZE][SIZE], w[SIZE][SIZE], x[SIZE][SIZE], y[SIZE][SIZE];

bool simulate2(int a,int b){
   for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
         y[i][j] = x[i][j];
   for(int i = 0; i <= row; i++)
      for(int j = 0; j <= column; j++)
         if(w[i][j] == '*'){
            if(y[a + i][b + j] == '.') return false;
            y[a + i][b + j] = '.';
         }
   for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
         if(y[i][j] == '*') return false;
   return true;
}

bool check(){
   for(int i = 0; i < r; i++)
      for(int j = 0; j < c; j++)
         if(simulate2(i, j)) return true;
   return false;
}

bool simulate1(int a, int b){
   for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
         x[i][j] = u[i][j];
   for(int i = 0; i <= row; i++)
      for(int j = 0; j <= column; j++)
         if(w[i][j] == '*'){
            if(x[a + i][b + j] == '.') return false;
            x[a + i][b + j] = '.';
         }
   return check();
}

void findLimits(){
   for(int j = 0; j < m; j++)
      for(int i = 0; i < m; i++)
         if(v[i][j] == '*') lx = j, i = j = m;
   for(int i = 0; i < m; i++)
      for(int j = 0; j < m; j++)
         if(v[i][j] == '*') ly = i, i = j = m;
   for(int j= m - 1; j >= 0; j--)
      for(int i= m - 1; i >= 0; i--)
         if(v[i][j] == '*') rx = j, i = j = -1;
   for(int i= m - 1; i >= 0; i--)
      for(int j= m - 1; j >= 0; j--)
         if(v[i][j] == '*') ry = i, i = j = -1;
}

int main(){
   while(scanf("%d %d\n", &n, &m), n | m){
      ans = false;
      for(int i = 0; i < n; i++) scanf("%s", u[i]);
      for(int i = 0; i < m; i++) scanf("%s", v[i]);
      findLimits();
      for(int i = ly; i <= ry; i++)
         for(int j = lx; j <= rx; j++)
            w[i - ly][j - lx] = v[i][j];
      row = ry - ly, column = rx - lx;
      r = n - row, c = n - column;
      for(int i = 0; i < r; i++)
         for(int j = 0; j < c; j++)
            if(simulate1(i, j)) ans = true, i = j = n;
      printf("%d\n", ans); 
   }
   return(0);
}
