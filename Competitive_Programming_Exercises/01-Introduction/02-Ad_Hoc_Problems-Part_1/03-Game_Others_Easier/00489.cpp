#include <bits/stdc++.h>

#define SIZE 30

using namespace std;

int Round, wrong;
bool vis1[SIZE], vis2[SIZE], ok;
char word[SIZE], guess[SIZE];

int main(){
   while(scanf("%d\n", &Round), ~Round){
      ok = wrong = 0;
      scanf("%s", word);
      scanf("%s", guess);
      memset(vis1, false, sizeof vis1);
      memset(vis2, false, sizeof vis2);
      for(int it = 0; word[it]; it++)
         vis1[word[it] - 'a'] = true;
      for(int it = 0; guess[it] and not ok and wrong < 7; it++)
         if( not vis2[guess[it] - 'a']){
            vis2[guess[it] - 'a'] = true;
            if( not vis1[guess[it] -'a'] ) wrong++;
            ok = true;
            for(int it = 0; it < SIZE and ok; it++)
               if( vis1[it] and not vis2[it] ) ok = false;
         }
      printf("Round %d\n", Round);
      if(ok) puts("You win.");
      else if( wrong == 7 ) puts("You lose.");
      else puts("You chickened out.");
   }
   return(0);
}
