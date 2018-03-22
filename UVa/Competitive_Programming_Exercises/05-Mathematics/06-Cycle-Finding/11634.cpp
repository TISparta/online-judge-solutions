#include <bits/stdc++.h>

using namespace std;

const int SIZE = 10005;

int n, ct;
bool vis[SIZE];

int numValues(){
   ct = 0;
   memset(vis, false, sizeof vis);
   while( not vis[n] ){
      vis[n] = true;
      n = ( n * n / 100 ) % 10000;
      ct++;
   }
   return ct;
}

int main(){
   while( scanf("%d", &n), n)
      printf("%d\n", numValues());
   return(0);
}
