#include <bits/stdc++.h>

using namespace std;

int tc, n;
char s[300][300], s1[300], s2[300], ss[300];
vector <int> G[300];

int bfs(int source, int dest){
   int d[n];
   for(int i = 0; i < n; i++) d[i] = -1;
   d[source] = 0;
   queue <int> Q;
   Q.push(source);
   while(!Q.empty()){
      int u = Q.front();
      Q.pop();
      for(int i = 0; i < G[u].size(); i++){
         int v = G[u][i];
         if(d[v] == -1){
            d[v] = d[u] + 1;
            Q.push(v);
         }
      }
      if(d[dest] != -1) return d[dest];
   }
}

int ind(char* sss){
   for(int i = 0; i < n; i++) if(strcmp(sss, s[i]) == 0) return i;
}

bool relation(int x,int y){
   if(strlen(s[x]) != strlen(s[y])) return false;
   int dif = 0;
   for(int i = 0; i < strlen(s[x]); i++)
      if(s[x][i] != s[y][i]) dif++;
   return (dif==1);
}

int main(){
   scanf("%d\n", &tc);
   while(tc--){
      n = 0;
      while(true){
         cin.getline(s[n], 300);
         if(strcmp(s[n], "*") == 0) break;
         n++;
      }
      for(int i = 0; i < n; i++)
         for(int j = i + 1; j < n; j++)
            if(relation(i, j)){
               G[i].push_back(j);
               G[j].push_back(i);
            }
      while(true){
         cin.getline(ss, 300);
         if(sscanf(ss, "%s %s", s1, s2) != 2) break;
         printf("%s %s %d\n", s1, s2, bfs(ind(s1), ind(s2)));
      }
      if(tc) putchar('\n');
      for(int i = 0; i < n; i++) G[i].clear();
   }
   return(0);
}
