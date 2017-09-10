#include <bits/stdc++.h>

#define SIZE 10

using namespace std;

int tc, r, c;
char table[SIZE][SIZE];
bool white, black;
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dxx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dyy[] = {1, 2, 2, 1, -1, -2, -2, -1};

bool empty(){
   for(int row = 0; row < 8; row++)
      for(int col = 0; col < 8; col++)
         if( table[row][col] != '.' ) return false;
   return true;
}

inline bool isValid(int X, int Y){
   return ( X >= 0 and Y >= 0 and X < 8 and Y < 8 );
}

bool proof(char ch, int row, int col, int it, int d){
   if( ch == 'k' ){
      if( islower(table[row][col]) ) return false;
      if( table[row][col] == 'P' ){
         if( ( it == 1 or it == 3 ) and d == 1 ) return true;
         return false;
      }
      if( table[row][col] == 'R' ){
         if( it % 2 == 0 ) return true;
         return false;
      }
      if( table[row][col] == 'B' ){
         if( it % 2 == 1 ) return true;
         return false;
      }
      if( table[row][col] == 'Q' ){
         return true;
      }
      return false;
   }
   if( ch == 'K' ){
      if( isupper(table[row][col]) ) return false;
      if( table[row][col] == 'p' ){
         if( ( it == 5 or it == 7 ) and d == 1 ) return true;
         return false;
      }
      if( table[row][col] == 'r' ){
         if( it % 2 == 0 ) return true;
         return false;
      }
      if( table[row][col] == 'b' ){
         if( it % 2 == 1 ) return true;
         return false;
      }
      if( table[row][col] == 'q' ){
         return true;
      }
      return false;
   }
}

bool check(char ch){
   for(int row = 0; row < 8; row++)
      for(int col = 0; col < 8; col++)
         if( table[row][col] == ch )
            r = row, c = col, row = col = 8;
   bool ok = false;
   for(int it = 0; it < 8; it++){
      for(int d = 1; d < 8; d++){
         int R = r + d * dy[it], C = c + d * dx[it];
         if( isValid(R, C) and table[R][C] != '.' )
            ok |= proof(ch, R, C, it, d), d = 8;
      }
   }
   for(int it = 0; it < 8; it++){
      int R = r + dyy[it], C = c + dxx[it];
      if( isValid(R, C) and ( ( ch == 'k' and table[R][C] == 'N' ) or ( ch == 'K' and table[R][C] == 'n' ) ) )
         ok = true;
   }
   return ok;
}

int main(){
   while(true){
      if(tc != 0) getchar();
      for(int row = 0; row < 8; row++) scanf("%s", table[row]);
      if( empty() ) break;
      white = check('K');
      black = check('k');
      printf("Game #%d: ", ++tc);
      if( white ) puts("white king is in check.");
      else if( black ) puts("black king is in check.");
      else puts("no king is in check.");
   }
   return(0);
}
