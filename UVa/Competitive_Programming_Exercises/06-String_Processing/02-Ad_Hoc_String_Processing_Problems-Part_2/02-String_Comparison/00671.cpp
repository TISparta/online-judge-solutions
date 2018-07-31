#include <bits/stdc++.h>

using namespace std;

const int SIZE = 10010, LEN = 20;

int tc, n, l, ct, len[SIZE];
char w[SIZE][LEN], word[LEN], s[LEN], correct[LEN];
set <string> st;
vector <string> ans;
bool ok;

bool check1(int id){
   if( abs(l - len[id]) != 1 ) return false;
   for(int k = 0; k < max(l, len[id]); k++){
      ok = true;
      for(int i = 0, j = 0; i < l and j < len[id] and ok; i++, j++)
         if( l < len[id] and j == k ) i--;
         else if( l > len[id] and i == k ) j--;
         else if( word[i] != w[id][j] ) ok = false;
      if(ok) return true;
   }
   return false;
}

bool check2(int id){
   if( l != len[id] )  return false;
   ct = 0;
   for(int i = 0; i < l; i++)
      if( word[i] != w[id][i] ) ct++;
   return ( ct == 1 );
}

int main(){
   scanf("%d\n", &tc);
   while(tc--){
      st.clear();
      n = 0;
      while(scanf("%s\n", w[n]), w[n][0] != '#'){
         len[n] = strlen(w[n]);
         st.insert(w[n++]);
      }
      while(scanf("%s\n", word), word[0] != '#'){
         l = strlen(word);
         if( st.find(word) != st.end() ) printf("%s is correct\n", word);
         else{
            ans.clear();
            for(int it = 0; it < n; it++)
               if( check1(it) or check2(it) ) ans.push_back(w[it]);
            printf("%s:", word);
            for(int it = 0, sz = ans.size(); it < sz; it++)
               printf( it != sz - 1 ? " %s" : " %s\n", ans[it].c_str());
            if( ans.empty() ) putchar('\n');
         }
      }
      if(tc) putchar('\n');
   }
   return(0);
}
