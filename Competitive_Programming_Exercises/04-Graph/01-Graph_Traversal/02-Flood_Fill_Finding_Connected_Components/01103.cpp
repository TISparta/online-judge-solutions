#include <bits/stdc++.h>

#define SIZE 210

using namespace std;

int tc, n, m, CC;
char line[SIZE], ch;
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
string grid[SIZE];
string hexa[16] = {"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
string w = "WAKJSD", ans;

inline bool is_possible(int R, int C){
   return ( 0 <= R and 0 <= C and R < n and C < m and grid[R][C] != '*');
}

void floodfill(int r, int c, char ch1, char ch2){
   if( grid[r][c] != ch1 ) return;
   grid[r][c] = ch2;
   for(int d = 0; d < 4; d++){
      int R = r + dr[d], C = c + dc[d];
      if( is_possible(R, C) ){
         if( ch1 == '1' and grid[R][C] == '0' )
            floodfill(R, C, '0', '*'), CC++;
         else
            floodfill(R, C, ch1, ch2);
      }
   }
}

void clear_(){
   for(int row = 0; row < n; row++)
      grid[row].clear();
   ans.clear();
}

int main(){
   while(scanf("%d %d\n", &n, &m), n | m){
      for(int it = 0; it < m; it++)
         grid[0] += "0000";
      grid[0] += "00";
      for(int row = 1; row <= n; row++){
         scanf("%s", line);
         grid[row] += "0";
         for(int it = 0; it < m; it++){
            ch = line[it];
            if(isdigit(ch))
               grid[row] += hexa[ch - '0'];
            else
               grid[row] += hexa[ch - 'a' + 10];
         }
         grid[row] += "0";
      }
      for(int it = 0; it < m; it++)
         grid[n + 1] += "0000";
      grid[n + 1] += "00";
      m *= 4, m += 2, n += 2;
      floodfill(0, 0, '0', '*');
      for(int row = 1; row < n; row++)
         for(int col = 1; col < m; col++)
            if( grid[row][col] == '1' ){
               CC = 0;
               floodfill(row, col, '1', '*');
               ans += w[CC];
            }
      sort(ans.begin(), ans.end());
      printf("Case %d: %s\n", ++tc, ans.c_str());
      clear_();
   }
   return(0);
}
