#include <bits/stdc++.h>

using namespace std;

const int LEN = 35;

char line[LEN];
map <char, char> mp;

int main(){
   for(int i = 0; i < 15; i++)
      mp[ 'A' + i ] = '0' + ( 2 + i / 3 );
   for(char ch = 'P'; ch <= 'S'; ch++)
      mp[ch] = '7';
   for(char ch = 'T'; ch <= 'V'; ch++)
      mp[ch] = '8';
   for(char ch = 'W'; ch <= 'Z'; ch++)
      mp[ch] = '9'; 
   mp['0'] = '0', mp['1'] = '1', mp['-'] = '-';
   while(~scanf("%s", line)){
      for(int it = 0; line[it]; it++)
         putchar( mp[line[it]] );
      putchar('\n');
   }
   return(0);
}
