#include <bits/stdc++.h>

using namespace std;

const int LEN = 1000;

int i, j;
char line[LEN];

int main(){
   while(cin.getline(line, LEN)){
      for(i = 0; line[i]; i++){
         j = i;
         while(line[j] and line[j] != ' ') j++;
         reverse(line + i, line + j);
         i = j;
      }
      printf("%s\n", line);
   }
   return(0);
}
