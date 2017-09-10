#include <bits/stdc++.h>

using namespace std;

int main(){
   int c, n, m;
   scanf("%d", &c);
   while(c--)
      scanf("%d %d", &n, &m),
      (n - 1)%(m - 1) ? printf("cannot do this\n") : printf("%d\n",(n - 1) / (m - 1));
   return(0);
}
