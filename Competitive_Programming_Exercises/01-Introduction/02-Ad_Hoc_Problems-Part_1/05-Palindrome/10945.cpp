#include <bits/stdc++.h>

#define SIZE 1010

using namespace std;

char s[SIZE], ch;
int len;

bool is_palindrome(){
   for(int i = 0, j = len - 1; i < j; i++, j--)
      if( tolower(s[i]) != tolower(s[j]) ) return false;
   return true;
}

int main(){
   while(true){
      len = 0;
      while( ( ch = getchar() ) != '\n' )
         if( isalpha(ch) )
            s[len++] = ch;
      s[len] = '\0';
      if( strcmp(s, "DONE") == 0 ) break;
      puts( is_palindrome() ? "You won't be eaten!" : "Uh oh..");
   }
   return(0);
}
