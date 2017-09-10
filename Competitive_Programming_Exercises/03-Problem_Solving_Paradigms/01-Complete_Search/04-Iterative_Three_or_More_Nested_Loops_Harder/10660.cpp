#include <bits/stdc++.h>

#define SIZE 8

using namespace std;

int tc, n, r, c, v, grid[SIZE][SIZE], r1, c1, r2, c2, r3, c3, r4, c4, r5, c5, sum, _min, tmp, ans1, ans2, ans3, ans4, ans5;

inline int dis(int x, int y, int X, int Y){
   return abs(X - x) + abs(Y - y);
}

int main(){
   scanf("%d", &tc);
   while(tc--){
      memset(grid, 0, sizeof grid);
      scanf("%d", &n);
      while(n--){
         scanf("%d %d %d", &r, &c, &v);
         grid[r][c] = v;
      }
      _min = INT_MAX;
      for(int p1 = 0; p1 < 25; p1++) for(int p2 = p1 + 1; p2 < 25; p2++)
         for(int p3 = p2 + 1; p3 < 25; p3++) for(int p4 = p3 + 1; p4 < 25; p4++)
            for(int p5 = p4 + 1; p5 < 25; p5++){
               r1 = p1 / 5, c1 = p1 % 5;
               r2 = p2 / 5, c2 = p2 % 5;
               r3 = p3 / 5, c3 = p3 % 5;
               r4 = p4 / 5, c4 = p4 % 5;
               r5 = p5 / 5, c5 = p5 % 5;
               sum = 0;
               for(int row = 0; row < 5; row++)
                  for(int col = 0; col < 5; col++){
                     tmp = dis(row, col, r1, c1) * grid[row][col];
                     tmp = min(tmp, dis(row, col, r2, c2) * grid[row][col]);
                     tmp = min(tmp, dis(row, col, r3, c3) * grid[row][col]);
                     tmp = min(tmp, dis(row, col, r4, c4) * grid[row][col]);
                     tmp = min(tmp, dis(row, col, r5, c5) * grid[row][col]);
                     sum += tmp;
                  }
               if( sum < _min ) _min = sum, ans1 = p1, ans2 = p2, ans3 = p3, ans4 = p4, ans5 = p5;
            }
      printf("%d %d %d %d %d\n", ans1, ans2, ans3, ans4, ans5);
   }
   return(0);
}
