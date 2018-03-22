#include <bits/stdc++.h>

using namespace std;

const int LEN = 210;

int tc;
char line[LEN];

int main(){
   scanf("%d\n", &tc);
   for(int t = 1; t <= tc; t++){
      printf("Case %d: ", t);
      scanf("%s", line);
      for(int it = 0; line[it]; ){
         char ch = line[it];
         int ct = 0;
         for(it++; line[it] and isdigit(line[it]); it++)
            ct = 10 * ct + ( line[it] - '0' );
         while(ct--) putchar(ch);
      }
      putchar('\n');
   }
   return(0);
}
