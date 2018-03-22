#include <bits/stdc++.h>

#define SIZE 60

using namespace std;

int tc, n, m, v[SIZE][SIZE], x, y;
char s[SIZE], word[SIZE];

inline void xor_swap(int &a, int &b){
   a ^= b, b ^= a, a ^= b;
}

void row(int r1, int r2){
   for(int j = 1; j <= n; j++) xor_swap(v[r1][j], v[r2][j]);
}

void col(int c1,int c2){
   for(int i = 1; i <= n; i++) xor_swap(v[i][c1], v[i][c2]);
}

void inc(int ad){
   for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
         v[i][j] = (v[i][j] + ad + 10) % 10;
}

void transpose(){
   for(int i = 1; i <= n; i++)
      for(int j = i + 1; j <= n; j++)
         xor_swap(v[i][j], v[j][i]);
}

void printMatrix(int t){
   printf("Case #%d\n", t);
   for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
         printf( j != n ? "%d" : "%d\n", v[i][j]);
   putchar('\n');
}

int main(){
   scanf("%d", &tc);
   for(int t = 1; t <= tc; t++){
      scanf("%d", &n);
      for(int i = 1; i <= n; i++)
         for(int j = 1; j <= n; j++) scanf("%1d", &v[i][j]);
      scanf("%d\n", &m);
      while(m--){
         cin.getline(s, SIZE);
         sscanf(s,"%s %d %d", word, &x, &y);
         if(strcmp(word, "row") == 0) row(x, y);
         else if(strcmp(word, "col") == 0) col(x, y);
         else if(strcmp(word, "inc") == 0) inc(1);
         else if(strcmp(word, "dec") == 0) inc(-1);
         else transpose();
      }
      printMatrix(t);
   }
   return(0);
}
