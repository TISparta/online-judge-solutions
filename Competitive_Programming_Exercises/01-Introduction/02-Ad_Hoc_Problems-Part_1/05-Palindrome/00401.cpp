#include <bits/stdc++.h>

#define SIZE 30

using namespace std;

char s[SIZE];
bool is_pal, is_mir;
int len;

bool check_pal(){
   for(int i = 0, j = len - 1; i < j; i++, j--)
      if( s[i] != s[j] ) return false;
   return true;
}

bool good(char ch1, char ch2){
   if( ch1 == 'B' or ch1 == 'C' or ch1 == 'D' ) return false;
   if( ch1 == 'F' or ch1 == 'G' or ch1 == 'K' ) return false;
   if( ch1 == 'N' or ch1 == 'p' or ch1 == 'Q' ) return false;
   if( ch1 == 'R' or ch1 == '4' or ch1 == '6' ) return false;
   if( ch1 == '7' or ch1 == '9') return false;
   if( ch1 == '3' ) return ( ch2 == 'E' );
   if( ch1 == 'E' ) return ( ch2 == '3' );
   if( ch1 == 'J' ) return ( ch2 == 'L' );
   if( ch1 == 'L' ) return ( ch2 == 'J' );
   if( ch1 == '2' ) return ( ch2 == 'S' );
   if( ch1 == 'S' ) return ( ch2 == '2' );
   if( ch1 == '5' ) return ( ch2 == 'Z' );
   if( ch1 == 'Z' ) return ( ch2 == '5' );
   return ( ch1 == ch2 );
}

bool check_mir(){
   for(int i = 0, j = len - 1; i <= j; i++, j--)
      if( not ( good(s[i], s[j]) ) ) return false;
   return true;
}

int main(){
   while(scanf("%s", s) != EOF){
      len = strlen(s);
      is_pal = check_pal();
      is_mir = check_mir();
      if(is_pal){
         if(is_mir) printf("%s -- is a mirrored palindrome.\n\n", s);
         else printf("%s -- is a regular palindrome.\n\n", s);
      }
      else{
         if(is_mir) printf("%s -- is a mirrored string.\n\n", s);
         else printf("%s -- is not a palindrome.\n\n", s);
      }
   }
   return(0);
}
