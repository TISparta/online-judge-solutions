#include <bits/stdc++.h>

using namespace std;

const int SIZE = 10010, LEN = 30;

int n, q, l, ct, len[SIZE];
char w[SIZE][LEN], word[LEN], s[LEN], correct[LEN];
set <string> st;
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

bool check3(int id){
   if( l != len[id] ) return false;
   vector <int> idx;
   for(int i = 0; i < l; i++)
      if( word[i] != w[id][i] ) idx.push_back(i);
   if( idx.size() != 2 ) return false;
   int a = idx[0], b = idx[1];
   return ( a + 1 == b and word[a] == w[id][b] and word[b] == w[id][a] );
}

bool misspelling(){
   l = strlen(word);
   for(int it = 0; it < n; it++){
      if( check1(it) or check2(it) or check3(it) ){
         strcpy(correct, w[it]);
         return true;
      }
   }
   return false;
}

int main(){
   scanf("%d\n", &n);
   for(int it = 0; it < n; it++){
      scanf("%s", w[it]);
      len[it] = strlen(w[it]);
      st.insert(w[it]);
   }
   scanf("%d\n", &q);
   for(int it = 0; it < q; it++){
      scanf("%s", word);
      if( st.find(word) != st.end() ) printf("%s is correct\n", word);
      else if( misspelling() ) printf("%s is a misspelling of %s\n", word, correct);
      else printf("%s is unknown\n", word);
   }
   return(0);
}
