#include <bits/stdc++.h>

#define SIZE 110
#define LIM 1000010

using namespace std;

int tc, a, b, c, x, y, turn, num, v[SIZE], player[LIM];
bool completed;

int main(){
   scanf("%d", &tc);
   while(tc--){
      memset(v, 0, sizeof v);
      scanf("%d %d %d", &a, &b, &c);
      while(b--){
         scanf("%d %d", &x, &y);
         v[x] = y;
      }
      turn = 1, completed = false;
      fill(player, player + a + 5, 1);
      while(c--){
         if( turn == a + 1 ) turn = 1;
         scanf("%d", &num);
         if( completed ) continue;
         player[turn] += num;
         if( player[turn] > 100 ) player[turn] = 100;
         if( v[player[turn]] ) player[turn] = v[player[turn]];
         if( player[turn] == 100 ) completed = true;
         turn++;
      }
      for(int it = 1; it <= a; it++)
         printf("Position of player %d is %d.\n", it, player[it]);
   }
   return(0);
}
