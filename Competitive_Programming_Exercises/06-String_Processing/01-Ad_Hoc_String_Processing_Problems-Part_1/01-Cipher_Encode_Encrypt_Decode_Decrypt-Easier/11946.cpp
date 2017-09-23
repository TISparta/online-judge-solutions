#include <bits/stdc++.h>

using namespace std;

const int LEN = 110;

int tc;
map <int, char> mp;
char line[LEN];
bool first = true;

int main(){   
   mp[0] = 'O', mp[1] = 'I', mp[2] = 'Z', mp[3] = 'E', mp[4] = 'A';
   mp[5] = 'S', mp[6] = 'G', mp[7] = 'T', mp[8] = 'B', mp[9] = 'P';
   scanf("%d\n", &tc);
   while(tc--){
      if(not first) putchar('\n');
      first = false;
      while(cin.getline(line, LEN) and line[0] != '\0'){
         for(int it = 0; line[it]; it++)
            putchar( isdigit(line[it]) ? mp[line[it] - '0'] : line[it]);
         putchar('\n');
      }
   }
   return(0);
}
