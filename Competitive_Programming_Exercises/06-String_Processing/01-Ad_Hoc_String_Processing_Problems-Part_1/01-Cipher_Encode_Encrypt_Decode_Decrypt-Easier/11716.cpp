#include <bits/stdc++.h>

using namespace std;

const int LEN = 10010;

int tc, m, n;
char line[LEN];

int main(){
   scanf("%d\n", &tc);
   while(tc--){
      cin.getline(line, LEN);
      m = strlen(line);
      n = sqrt(m);
      if( n * n != m ){
         puts("INVALID");
         continue;
      }
      for(int col = 0; col < n; col++)
         for(int row = 0; row < n; row++)
            putchar( line[row * n + col] );
      putchar('\n');
   }
   return(0);
}
