#include <bits/stdc++.h>

#define SIZE 110

using namespace std;

int tc, n, m, table[SIZE][SIZE];
char mines[SIZE][SIZE], s[SIZE][SIZE];
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
bool mine;

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%d\n", &n);
      for(int row = 0; row < n; row++)
         scanf("%s", mines[row]);
      for(int row = 0; row < n; row++)
         scanf("%s", s[row]);
      memset(table, 0, sizeof table);
      mine = false;
      for(int row = 0; row < n; row++)
         for(int col = 0; col < n; col++){
            if( mines[row][col] == '*' ){
               if( s[row][col] == 'x' ) mine = true;
               for(int it = 0; it < 8; it++){
                  int r = row + dy[it], c = col + dx[it];
                  if( r >= 0 and c >= 0 and r < n and c < n )
                     table[r][c]++;
               }
            }
         }
      for(int row = 0; row < n; row++){
         for(int col = 0; col < n; col++)
            if( s[row][col] == 'x' ){
               if( mines[row][col] == '*' and mine ) putchar('*');
               else printf("%d", table[row][col]);
            }
            else if( mine )
               printf("%c", mines[row][col]);
            else
               putchar('.');
         putchar('\n');
      }
      if(tc) putchar('\n');
   }
   return(0);
}
