#include <bits/stdc++.h>

using namespace std;

string line, word;

bool isvowel(char ch){
   ch = tolower(ch);
   return ( ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u' );
}

int main(){
   while(getline(cin, line)){
      for(int it = 0; it < line.size();){
         if( not isalpha(line[it]) ) putchar(line[it++]);
         else{
            char ch = line[it];
            word = "";
            if( isvowel(ch) ) word += ch;
            for(it++; it < line.size() and isalpha(line[it]); it++)
               word += line[it];
            if( not isvowel(ch) ) word += ch;
            word += "ay";
            printf("%s", word.c_str());
         }
      }
      putchar('\n');
   }
   return(0);
}
