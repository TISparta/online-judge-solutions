#include <bits/stdc++.h>

#define SIZE 1010

using namespace std;

int tc, N, a, b, code[SIZE], guess[SIZE];
bool vis[SIZE];

int main(){
   while(scanf("%d", &N), N){
      for(int it = 0; it < N; it++) scanf("%d", &code[it]);
      printf("Game %d:\n", ++tc);
      while(true){
         for(int it = 0; it < N; it++) scanf("%d", &guess[it]);
         if(guess[0] == 0) break;
         a = b = 0;
         memset(vis, false, sizeof vis);
         for(int it = 0; it < N; it++)
            if( guess[it] == code[it] ) a++, vis[it] = true;
         for(int it = 0; it < N; it++)
            if( guess[it] != code[it] ){
               for(int i = 0; i < N; i++)
                  if( not vis[i] and code[i] == guess[it] )
                     vis[i] = true, b++, i = N;
            }
         printf("    (%d,%d)\n", a, b);
      }
   }
   return(0);
}
