#include <bits/stdc++.h>

using namespace std;

const int LEN = 30;

int n, m;
map <string, string> Prural;
char word[LEN], word1[LEN], word2[LEN];

bool isvowel(char ch){
   return ( ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u' );
}

bool check(char* s){
   int l = strlen(s) - 1;
   if( s[l] == 'y' and l and not isvowel(s[l - 1]) ) return true;
   return false;
}

bool ending(char* s){
   int l = strlen(s) - 1;
   if( s[l] == 'o' or s[l] == 's' or s[l] == 'x' ) return true;
   if( l > 0 and s[l] == 'h' and ( s[l - 1] == 'c' or s[l - 1] == 's' ) ) return true;
   return false;
}

int main(){
   scanf("%d %d\n", &n, &m);
   for(int it = 0; it < n; it++){
      scanf("%s %s", word1, word2);
      Prural[word1] = word2;
   }
   for(int it = 0; it < m; it++){
      scanf("%s", word);
      if( Prural.find(word) != Prural.end() ) puts(Prural[word].c_str());
      else if( check(word) ) word[strlen(word) - 1] = 'i', printf("%ses\n", word);
      else if( ending(word) ) printf("%ses\n", word);
      else printf("%ss\n", word);
   }
   return(0);
}
