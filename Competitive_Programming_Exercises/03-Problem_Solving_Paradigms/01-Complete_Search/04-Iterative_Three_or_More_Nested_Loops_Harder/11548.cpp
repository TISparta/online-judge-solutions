#include <bits/stdc++.h>

#define SIZE 100

using namespace std;

int tc, n, ans, ct;
char word[SIZE][SIZE];

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%d\n", &n);
      for(int it = 0; it < n; it++) scanf("%s", word[it]);
      ans = 0;
      for(int it1 = 0; it1 < n; it1++)
         for(int it2 = 0; it2 < n; it2++)
            if( it1 != it2 )
               for(int pos = 0; word[it1][pos]; pos++){
                  ct = 0;
                  for(int it = 0; word[it1][pos + it] and word[it2][it]; it++)
                     ct += ( word[it1][pos + it] == word[it2][it] );
                  ans = max(ans, ct);
               }
      printf("%d\n", ans);
   }
   return(0);
}
