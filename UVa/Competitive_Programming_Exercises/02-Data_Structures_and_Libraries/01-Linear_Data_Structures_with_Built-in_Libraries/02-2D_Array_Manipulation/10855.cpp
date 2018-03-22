#include <bits/stdc++.h>

#define SIZE 1010

using namespace std;

int n, m;
char u[SIZE][SIZE], v[SIZE][SIZE], w[SIZE][SIZE];

bool check(int x, int y){
   for(int i = x; i < x + m; i++)
      for(int j = y; j < y + m; j++)
         if(v[i][j] != u[i - x][j - y]) return false;
   return true;
}

int appearances(){
   int ct = 0;
   for(int i = 0; i < n - m + 1; i++)
      for(int j = 0; j < n - m + 1; j++)
         if(check(i, j)) ct++;
   return ct;
}

void rotate(){
   for(int i = 0; i < m; i++)
      for(int j = 0; j < m; j++) w[i][j] = u[m - j - 1][i];
   for(int i = 0; i < m; i++)
      for(int j = 0; j < m; j++) u[i][j] = w[i][j];
}

int main(){
   while(scanf("%d %d\n",&n,&m),n|m){
      for(int i = 0; i < n; i++) scanf("%s", v[i]);
      for(int i = 0; i < m; i++) scanf("%s", u[i]);
      for(int it = 0; it < 4; it++){
         printf( it != 3 ? "%d " : "%d\n", appearances());
         rotate();
      }
   }
   return(0);
}
