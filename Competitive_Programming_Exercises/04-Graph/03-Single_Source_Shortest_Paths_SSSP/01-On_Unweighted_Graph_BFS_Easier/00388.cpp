#include <bits/stdc++.h>

using namespace std;

int n;
double f;
char s1, s2[50];
map <char, double> p;
map <char, vector<char> > G;
map <char, int> d;
const double fee = 0.95;

char bfs(char source){
   queue <char> Q;
   Q.push(source), d[source] = 0;
   while(!Q.empty()){
      char u = Q.front(); Q.pop();
      for(int i = 0; i < G[u].size(); i++){
         char v = G[u][i];
         if(d[v] == -1)
            d[v] = d[u] + 1, Q.push(v);
      }
   }
   double _max = -1;
   char ans;
   for(char ch = 'A'; ch <= 'Z'; ch++){
      double v = p[ch] * pow(fee, d[ch] - 1);
      if(v > _max) _max = v, ans = ch;
   }
   return ans;
}

int main(){
   while(scanf("%d\n", &n) == 1){
      p.clear(), G.clear();
      for(int i = 0; i < n; i++){
         scanf("%c %lf %s\n", &s1, &f, s2);
         p[s1] = f, d[s1] = -1;
         for(int i = 0; i < strlen(s2); i++)
            G[s1].push_back(s2[i]), G[s2[i]].push_back(s1), d[s2[i]] = -1;
      }
      printf("Import from %c\n", bfs('*'));
   }
   return(0);
}
