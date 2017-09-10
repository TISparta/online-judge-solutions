#include <bits/stdc++.h>

using namespace std;

int tc, M, N, Q, x, y, ct;
char s[100][100];

bool isAllOne(int i, int j, int x, int y, char ch){
   if(i < 0 || j < 0 || x >= M || y >= N) return false;
   for(int p = i; p <= x; p++)
      for(int q = j; q <= y; q++)
         if(s[p][q] != ch) return false;
   return true;
}

void solution(int p, int q, char ch){
   for(int r = 0; r < min(M, N); r++)
      if(isAllOne(p - r, q - r, p + r, q + r, ch)) ct = 2 * r + 1;
   printf("%d\n", ct);
}

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%d %d %d", &M, &N, &Q);
      for(int i = 0; i < M; i++) scanf("%s", s[i]);
      printf("%d %d %d\n", M, N, Q);
      while(Q--){
         scanf("%d %d", &x, &y);
         solution(x, y, s[x][y]);
      }
   }
   return(0);
}
