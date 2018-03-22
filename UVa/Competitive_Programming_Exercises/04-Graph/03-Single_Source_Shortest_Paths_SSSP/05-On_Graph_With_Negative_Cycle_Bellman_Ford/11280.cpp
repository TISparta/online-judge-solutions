#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 110, MAX_E = 1010, LEN = 25, INF = 1000000000;

int tc, V, E, Q, u, v, w, mx, dis, W[MAX_V][MAX_V], memo[MAX_V][MAX_V];
char word[LEN], word1[LEN], word2[LEN];
map <string, int> mp;

int dp(int id, int ct){
   if( id == V ) return 0;
   if( ct < 0 ) return INF;
   if( ~memo[id][ct] ) return memo[id][ct];
   int ret = INF;
   for(int j = 1; j <= V; j++)
      if( W[id][j] != INF )
         ret = min(ret, W[id][j] + dp(j, ct - 1));
   return memo[id][ct] = ret;
}

int main(){
   scanf("%d", &tc);
   for(int t = 1; t <= tc; t++){
      printf("Scenario #%d\n", t);
      scanf("%d\n", &V);
      memset(memo, -1, sizeof memo);
      fill(W[1], W[V + 1], INF);
      for(int i = 1; i <= V; i++){
         scanf("%s\n", word);
         mp[word] = i;
      }
      scanf("%d\n", &E);
      for(int i = 0; i < E; i++){
         scanf("%s %s %d\n", word1, word2, &w);
         u = mp[word1], v = mp[word2];
         W[u][v] = min(W[u][v], w);
      }
      scanf("%d", &Q);
      while(Q--){
         scanf("%d", &mx);
         dis = dp(1, mx);
         if( dis == INF ) puts("No satisfactory flights");
         else printf("Total cost of flight(s) is $%d\n", dis);
      }
      if( t != tc ) putchar('\n');
   }
   return(0);
}
