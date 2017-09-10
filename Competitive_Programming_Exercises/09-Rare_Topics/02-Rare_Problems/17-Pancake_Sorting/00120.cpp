#include <bits/stdc++.h>

using namespace std;

const int LEN = 300, SIZE = 35;

int n, v[SIZE], u[SIZE];
char line[LEN], *p;

int main(){
   while(cin.getline(line, LEN)){
      p = strtok(line, " ");
      n = 0;
      while(p) v[n] = u[n] = atoi(p), n++, p = strtok(NULL, " ");
      sort(u, u + n);
      for(int it = 0; it < n; it++)
         printf( it != n - 1 ? "%d " : "%d\n", v[it] );
      for(int it = n - 1; it >= 0; it--)
         if( v[it] != u[it] ){
            int id;
            for(id = it - 1; id >= 0; id--)
               if( v[id] == u[it] ) break;
            printf("%d ", n - id);
            for(int j = 0; j < id; j++)
               swap( v[j], v[id--]);
            printf("%d ", n - it);
            id = it;
            for(int j = 0; j < id; j++)
               swap( v[j], v[id--]);
         }
      printf("0\n");
   }
   return(0);
}
