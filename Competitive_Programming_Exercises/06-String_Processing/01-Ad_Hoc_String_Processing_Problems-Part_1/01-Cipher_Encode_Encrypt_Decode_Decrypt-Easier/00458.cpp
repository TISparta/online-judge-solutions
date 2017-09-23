#include <bits/stdc++.h>

using namespace std;

const int LEN = 1000;

char line[LEN];

int main(){
   while(cin.getline(line, LEN)){
      for(int it = 0; line[it]; it++) putchar(line[it] - 7);
      putchar('\n');
   }
   return(0);
}
