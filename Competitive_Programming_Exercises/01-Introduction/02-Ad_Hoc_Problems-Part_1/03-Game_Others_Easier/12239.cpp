#include <bits/stdc++.h>

#define SIZE 100

using namespace std;

int N, B, b[SIZE];
bool vis[SIZE], ok;

int main(){
   while(scanf("%d %d", &N, &B), N | B){
      memset(vis, false, sizeof vis);
      for(int it = 0; it < B; it++) scanf("%d", &b[it]);
      for(int it1 = 0; it1 < B; it1++)
         for(int it2 = it1; it2 < B; it2++)
            vis[ abs(b[it1] - b[it2]) ] = true;
      ok = true;
      for(int it = 0; it <= N; it++)
         if( not vis[it] ) ok = false;
      if(ok) puts("Y");
      else puts("N");
   }
   return(0);
}
