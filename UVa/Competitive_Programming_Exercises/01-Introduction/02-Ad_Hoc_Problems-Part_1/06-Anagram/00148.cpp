#include <bits/stdc++.h>

#define SIZE  2010
#define LEN 43

using namespace std;

int ct, abc[LEN], pib[LEN], n, N, aux;
char v[SIZE][LEN], s[LEN], w[SIZE][LEN], vis[SIZE][LEN], ss[LEN], ans[SIZE][LEN], *p;

int cmp(){
   bool more = false, less = false;
   for(int it = 0; it < LEN; it++)
      if(pib[it] < abc[it]) less = true;
      else if( pib[it] > abc[it]) more = true;
   if(more) return 1;
   if(less) return -1;
   return 0;
}

bool isValid(int idx){
   for(int it = 0; it < n; it++)
      if( strcmp(vis[it], v[idx]) == 0 ) return false;
   return true;
}

void backtrack(int idx){
   int d = cmp();
   if( d == 1 ) return;
   if( d == 0 ){
      printf("%s =", s);
      for(int it = 0; it < aux; it++)
         printf(it != aux - 1 ? " %s" : " %s\n", ans[it]);
      return;
   }
   if( idx == N ) return;
   for(int it = idx; it < N; it++){
         for(int i = 0; w[it][i]; i++)
            pib[w[it][i] - 'A']++;
         strcpy(ans[aux++], w[it]);
         backtrack(it + 1);
         for(int i = 0; w[it][i] ;i++)
            pib[w[it][i] - 'A']--;
         aux--;
   }
}

int main(){
   while(scanf("%s", v[ct]), v[ct][0] != '#') ct++;
   getchar();
   while(cin.getline(s, LEN), s[0] != '#'){
      strcpy(ss, s), n = 0;
      p = strtok(ss, " ");
      while(p){
         strcpy(vis[n++], p);
         p = strtok(NULL, " ");
      }
      memset(abc, 0, sizeof abc);
      for(int it = 0; s[it]; it++)
         if( s[it] != ' ' )
            abc[s[it] - 'A']++;
      N = aux = 0;
      for(int it = 0; it < ct; it++){
         memset(pib, 0, sizeof pib);
         for(int i = 0; v[it][i]; i++)
            pib[v[it][i] - 'A']++;
         if( cmp() <= 0 and isValid(it) ) strcpy(w[N++], v[it]);
      }
      memset(pib, 0, sizeof pib);
      backtrack(0);
   }
   return(0);
}
