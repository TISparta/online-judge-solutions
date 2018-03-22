#include <bits/stdc++.h>

using namespace std;

int K, Q, M, r1, c1, r2, c2, r3, c3;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
   while(~scanf("%d %d %d", &K, &Q, &M)){
      if( K == Q ) puts("Illegal state");
      else{
         r1 = K / 8, c1 = K % 8;
         r2 = Q / 8, c2 = Q % 8;
         r3 = M / 8, c3 = M % 8;
         if( not ( ( r2 == r3 and ( r1 != r3 or (r1 == r3 and not( min(c2, c3) < c1 and c1 < max(c2, c3) ) ) ) )
            or ( c2 == c3 and ( c1 != c3 or (c1 == c3 and not( min(r2, r3) < r1 and r1 < max(r2, r3) ) ) ) ) )
            or K == M or Q == M )
            puts("Illegal move");
         else{
            if( abs(r3 - r1) + abs(c3 - c1) == 1 )
               puts("Move not allowed");
            else{
               int ct = 0;
               for(int it = 0; it < 4; it++){
                  int row = r1 + dy[it], col = c1 + dx[it];
                  if( row >= 0 and col >= 0 and row < 8 and col < 8
                        and abs(row - r3) + abs(col - c3) != 1 )
                     ct++;
               }
               if( ct )
                  puts("Continue");
               else
                  puts("Stop");
            }
         }
      }

   }
   return(0);
}
