#include <bits/stdc++.h>

using namespace std;

const int LEN = 1000;

int len;
char line[LEN];

void Decode(){
   for(int it = len - 1; it >= 0;){
      int ascii = line[it--] - '0';
      if( ascii == 1 ){
         ascii = 10 * ascii + ( line[it--] - '0' );
         ascii = 10 * ascii + ( line[it--] - '0' );
      }
      else
         ascii = 10 * ascii + ( line[it--] - '0' );
      putchar(ascii);
   }
   putchar('\n');
}

void Encode(){
   for(int it = len - 1; it >= 0; it--){
      int ascii = line[it];
      while(ascii) putchar('0' + ascii % 10), ascii /= 10;
   }
   putchar('\n');
}

int main(){
   while(cin.getline(line, LEN)){
      len = strlen(line);
      if( isdigit(line[0]) ) Decode();
      else Encode();
   }
   return(0);
}
