#include <bits/stdc++.h>

#define SIZE 310

using namespace std;

int tc, n;
long v[SIZE][SIZE];

bool symmetric(){
   for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
         if(v[i][j] < 0 || v[i][j] != v[n + 1 - i][n + 1 - j]) return false;
   return true;
}

int main(){
   scanf("%d", &tc);
   for(int t = 1;t <= tc; t++){
      scanf("\n%*c %*c %d", &n);
      for(int i = 1;i <= n; i++)
         for(int j = 1; j <= n; j++)
            scanf("%ld", &v[i][j]);
      if(symmetric()) printf("Test #%d: Symmetric.\n", t);
      else printf("Test #%d: Non-symmetric.\n", t);
   }
   return(0);
}
