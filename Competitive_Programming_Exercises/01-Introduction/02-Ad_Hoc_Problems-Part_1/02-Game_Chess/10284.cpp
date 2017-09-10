#include <bits/stdc++.h>

#define SIZE 10
#define LIM 100

using namespace std;

char s[LIM], table[SIZE][SIZE];
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dxx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dyy[] = {1, 2, 2, 1, -1, -2, -2, -1};


void convertFEN(){
   int row = 0, col = 0;
   for(int it = 0; s[it]; it++){
      if( isdigit(s[it]) ){
         int ct = s[it] - '0';
         while(ct--) table[row][col++] = '.';
      }
      else if( s[it] != '/' )
         table[row][col++] = s[it];
      else
         row++, col = 0;
   }
}

inline bool isValid(int X, int Y){
   return ( X >= 0 and Y >= 0 and X < 8 and Y < 8 );
}

bool proof(int row, int col, int it, int d){
   if( table[row][col] == 'p' ){
      if( ( it == 5 or it == 7 ) and d == 1 ) return true;
      return false;
   }
   if( table[row][col] == 'P' ){
      if( ( it == 1 or it == 3 ) and d == 1 ) return true;

   }
   if( table[row][col] == 'r' or table[row][col] == 'R' ){
      if( it % 2 == 0 ) return true;
      return false;
   }
   if( table[row][col] == 'b' or table[row][col] == 'B' ){
      if( it % 2 == 1 ) return true;
      return false;
   }
   if( table[row][col] == 'q' or table[row][col] == 'Q' ){
      return true;
   }
   if( table[row][col] == 'k' or table[row][col] == 'K' ){
      if( d == 1 ) return true;
      return false;
   }
   return false;
}

bool check(char ch, int r, int c){
   bool ok = false;
   for(int it = 0; it < 8; it++){
      for(int d = 1; d < 8; d++){
         int R = r + d * dy[it], C = c + d * dx[it];
         if( isValid(R, C) and table[R][C] != '.' )
            ok |= proof(R, C, it, d), d = 8;
      }
   }
   for(int it = 0; it < 8; it++){
      int R = r + dyy[it], C = c + dxx[it];
      if( isValid(R, C) and ( table[R][C] == 'N' or table[R][C] == 'n' ) )
      ok = true;
   }
   return ok;
}

int solution(){
   int ans = 0;
   for(int row = 0; row < 8; row++)
      for(int col = 0; col < 8; col++)
         if( table[row][col] == '.' )
            ans += ( check(table[row][col], row, col) == false );
   return ans;
}

int main(){
   while(~scanf("%s", s)){
      convertFEN();
      printf("%d\n", solution());
   }
   return(0);
}
