#include <bits/stdc++.h>

#define SIZE 10010

using namespace std;

int tc, R, C, N, r, c, x, y;
bitset <SIZE> row, column;
int dx[] = {-1, 0, 0, 0, 1};
int dy[] = {0, 1, 0, -1, 0};
bool ok;

inline bool isValid(int _x, int _y){
   return (_x >= 0 && _y >= 0 && _x < R && _y < C);
}

int main(){
   while(scanf("%d %d %d", &R, &C, &N),R | C | N){
      row.reset(), column.reset();
      for(int i = 0; i < N; i++) scanf("%d %d", &r, &c), row.set(r, 1), column.set(c, 1);
      scanf("%d %d",&x, &y);
      ok = true;
      for(int i = 0; i < 5; i++){
         int X = x + dx[i];
         int Y = y + dy[i];
         if(isValid(X, Y) && (!row.test(X) && !column.test(Y)))
            ok = false;
      }
      printf("Case %d: ", ++tc);
      if(ok) puts("Party time! Let's find a restaurant!");
      else puts("Escaped again! More 2D grid problems!");
   }
   return(0);
}
