#include <bits/stdc++.h>

#define SIZE 30

using namespace std;

int tc, CC;
char ch, ch1, ch2, line[SIZE];
bool Adj[SIZE][SIZE], vis[SIZE];

void dfs(int u){
   vis[u] = true;
   for(int v = 0; v <= (ch - 'A'); v++)
      if( Adj[u][v] and not vis[v])
         dfs(v);
}

int main(){
   scanf("%d\n", &tc);
   int t = 0;
   while(tc--){
      t++;
      memset(Adj, false, sizeof Adj);
      memset(vis, false, sizeof vis);
      CC = 0;
      cin.getline(line, SIZE);
      sscanf(line, "%c", &ch);
      while(cin.getline(line, SIZE)){
         if( sscanf(line, "%c%c", &ch1, &ch2) != 2 ) break;
         Adj[ch1 - 'A'][ch2 - 'A'] = Adj[ch2 - 'A'][ch1 - 'A'] = true;
      }
      for(int u = 0; u <= (ch - 'A'); u++)
         if( not vis[u] )
            dfs(u), CC++;
      printf("%d\n", CC);
      if( tc ) putchar('\n');
   }
   return(0);
}
