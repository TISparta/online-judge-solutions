#include <bits/stdc++.h>

#define SIZE 510

using namespace std;

int w, h, n, a1, a2, b1, b2, ans;
bool v[SIZE][SIZE];

int main(){
   while(scanf("%d %d %d", &w, &h, &n), w | h | n){
      memset(v, true, sizeof v);
      ans = 0;
      while(n--){
         scanf("%d %d %d %d", &a1, &b1, &a2, &b2);
         if(a1 > a2) swap(a1, a2);
         if(b1 > b2) swap(b1, b2);
         for(int i = a1; i <= a2; i++)
            for(int j = b1; j <= b2; j++)
               v[i][j] = false;
      }
      for(int i = 1; i <= w; i++)
         for(int j = 1; j <= h; j++)
            ans += v[i][j];
      if(ans == 0) puts("There is no empty spots.");
      else if(ans == 1) puts("There is one empty spot.");
      else printf("There are %d empty spots.\n", ans);
   }
   return(0);
}
