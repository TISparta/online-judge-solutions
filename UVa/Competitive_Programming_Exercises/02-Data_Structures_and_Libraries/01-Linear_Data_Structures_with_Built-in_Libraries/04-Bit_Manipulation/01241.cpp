#include <bits/stdc++.h>

using namespace std;

int a[1<<11];

int main(){
   int c, tmp, lim, ans, n, m;
   scanf("%d", &c);
   while(c--){
      ans = 0;
      scanf("%d %d", &n, &m);
      lim = 1<<n;
      memset(a, 1, sizeof a);
      for(int i = 0; i < m; i++) scanf("%d", &tmp), a[tmp - 1] = 0;
      while(lim != 1){
         for(int i = 0; i < lim; i += 2){
            if( ( a[i] && !a[i + 1] ) || ( !a[i] && a[i + 1] ) ) ans++;
            a[i / 2] = a[i] || a[i + 1];
         }
         lim /= 2;
      }
      printf("%d\n",ans);;
   }
   return(0);
}
