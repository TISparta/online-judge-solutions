#include <bits/stdc++.h>

#define SIZE 110

using namespace std;

int tc, N, M, row, r, c;
char grid[SIZE][SIZE], line[SIZE];
int dr[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dc[] = {1, 1, 0, -1, -1, -1, 0, 1};

inline bool is_possible(int R, int C){
   return ( 0 <= R and 0 <= C and R < N and C < M );
}

int floodfill(int r, int c, char ch1, char ch2){
   if( not is_possible(r, c) ) return 0;
   if( grid[r][c] != ch1 ) return 0;
   grid[r][c]  = ch2;
   int ans = 1;
   for(int d = 0; d < 8; d++)
      ans += floodfill(r + dr[d], c + dc[d], ch1, ch2);
   return ans;
}

int main(){
   scanf("%d\n", &tc);
   while(tc--){
      N = 0;
      while(cin.getline(line, SIZE)){
         if( isdigit(line[0]) ) break;
         strcpy(grid[N++], line);
      }
      M = strlen(grid[0]);
      do{
         if( sscanf(line, "%d %d", &r, &c) != 2 ) break;
         printf("%d\n", floodfill(r - 1, c - 1, 'W', '.'));
         floodfill(r - 1, c - 1, '.', 'W');
      }while(cin.getline(line, SIZE));
      if(tc) putchar('\n');
   }
   return(0);
}
