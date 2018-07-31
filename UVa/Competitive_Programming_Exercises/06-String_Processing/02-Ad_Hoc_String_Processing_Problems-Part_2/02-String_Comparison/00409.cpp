#include <bits/stdc++.h>

using namespace std;

const int SIZE = 30, LEN = 80;

int tc, n, m, ct[SIZE], mx;
set <string> keys;
string s;
char key[LEN], line[SIZE][LEN];

int main(){
   while(scanf("%d %d\n", &n, &m) != EOF){
      keys.clear(), mx = 0;
      for(int it = 0; it < n; it++){
         scanf("%s\n", key);
         keys.insert(key);
      }
      for(int it = 0; it < m; it++){
         ct[it] = 0;
         cin.getline(line[it], LEN);
         for(int i = 0; line[it][i]; i++){
            if( isalpha(line[it][i]) ){
               s = tolower(line[it][i]);
               for(i++; line[it][i] and isalpha(line[it][i]); i++)
                  s += tolower(line[it][i]);
               if( keys.find(s) != keys.end() )
                  ct[it]++;
            }
         }
         mx = max(mx, ct[it]);
      }
      printf("Excuse Set #%d\n", ++tc);
      for(int it = 0; it < m; it++)
         if( ct[it] == mx ) printf("%s\n", line[it]);
      putchar('\n');
   }
   return(0);
}
