#include <bits/stdc++.h>

#define SIZE 110

using namespace std;

int n, r, c, k, v[SIZE][SIZE], u[SIZE][SIZE];
bool visited[SIZE][SIZE];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};

void simulate(){
   memset(visited, false, sizeof visited);
   memset(u, -1, sizeof u);
   for(int i = 1; i <= r; i++)
      for(int j = 1; j <= c; j++)
         for(int it = 0; it < 4; it++){
            int x = i + dx[it], y = j + dy[it];
            if(!visited[x][y] && v[x][y] == (v[i][j] + 1 + n) % n)
               u[x][y] = v[i][j], visited[x][y] = true;
         }
   for(int i = 1; i <= r; i++)
      for(int j = 1; j <= c; j++)
         if(u[i][j] == -1) u[i][j] = v[i][j];
   for(int i = 1; i <= r; i++)
      for(int j = 1; j <= c; j++)
         v[i][j] = u[i][j];
}

void printMatrix(){
   for(int i = 1; i <= r; i++)
      for(int j = 1; j <= c; j++)
         printf( j != c ? "%d " : "%d\n", u[i][j]);
}

int main(){
   while(scanf("%d %d %d %d", &n, &r, &c, &k),n | r | c | k){
      memset(v, -1, sizeof v);
      for(int i = 1; i <= r; i++)
         for(int j = 1; j <= c; j++) scanf("%d", &v[i][j]);
      while(k--) simulate();
      printMatrix();
   }
   return(0);
}
