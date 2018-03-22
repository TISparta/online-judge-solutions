#include <bits/stdc++.h>

#define SIZE 30

using namespace std;

int tc, n, y[SIZE], a[SIZE], b[SIZE], year;
bool ok;

int main(){
   while(scanf("%d", &n), n){
      year = 0;
      for(int i = 0;i < n; i++) scanf("%d %d %d", &y[i], &a[i], &b[i]), year = max(year, y[i]);
      while(true){
         ok = true;
         for(int i = 0; i < n; i++)
            if((year - y[i]) % (b[i] - a[i])) ok = false;
         if(ok || year == 10000) break;
         year++;
      }
      printf("Case #%d:\n", ++tc);
      if(year == 10000) puts("Unknown bugs detected.\n");
      else printf("The actual year is %d.\n\n", year);
   }
   return(0);
}
