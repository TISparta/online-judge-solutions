#include <bits/stdc++.h>

using namespace std;

const int LEN = 30;

int tc;
char s1[LEN], s2[LEN];

inline bool isvowel(char ch){
   return ( ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u' );
}

bool check(){
   if( strlen(s1) != strlen(s2) ) return false;
   for(int it = 0; s1[it]; it++){
      int ct = isvowel(s1[it]) + isvowel(s2[it]);
      if( ct == 1 ) return false;
      if( ct == 0 and s1[it] != s2[it] ) return false;
   }
   return true;
}

int main(){
   scanf("%d\n", &tc);
   while(tc--){
      scanf("%s", s1);
      scanf("%s", s2);
      puts( check() ? "Yes" : "No" );
   }
   return(0);
}
