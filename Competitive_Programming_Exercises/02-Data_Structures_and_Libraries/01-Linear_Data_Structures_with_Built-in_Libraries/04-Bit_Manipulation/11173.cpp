#include <bits/stdc++.h>

using namespace std;

int tc, n, k;

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%d %d", &n, &k);
      printf("%d\n",k ^ (k>>1));
   }
   return(0);
}
