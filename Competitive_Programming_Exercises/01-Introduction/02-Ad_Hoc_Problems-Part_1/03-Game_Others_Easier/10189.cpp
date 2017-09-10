#include <bits/stdc++.h>

#define SIZE 110

using namespace std;

int tc, n, m, table[SIZE][SIZE];
char mines[SIZE][SIZE];
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(){
   while(scanf("%d %d\n", &n, &m), n | m){
      for(int row = 0; row < n; row++)
         scanf("%s", mines[row]);
      memset(table, 0, sizeof table);
      for(int row = 0; row < n; row++)
         for(int col = 0; col < m; col++){
            if( mines[row][col] == '*' )
               for(int it = 0; it < 8; it++){
                  int r = row + dy[it], c = col + dx[it];
                  if( r >= 0 and c >= 0 and r < n and c < m )
                     table[r][c]++;
               }
         }
      if(tc) putchar('\n');
      printf("Field #%d:\n", ++tc);
      for(int row = 0; row < n; row++){
         for(int col = 0; col < m; col++)
            if( mines[row][col] == '*' ) putchar('*');
            else printf("%d", table[row][col]);
         putchar('\n');
      }
   }
   return(0);
}
