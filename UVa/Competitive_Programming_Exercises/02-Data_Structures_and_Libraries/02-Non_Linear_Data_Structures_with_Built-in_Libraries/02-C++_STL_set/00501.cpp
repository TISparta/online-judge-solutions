#include <bits/stdc++.h>

#define SIZE 30010

using namespace std;

int tc, ct, t, m, n, a[SIZE], u;
multiset <int> ::iterator it;

int main(){
   scanf("%d",&tc);
   while(tc--){
      multiset <int> v;
      scanf("%d %d", &m, &n);
      for(int i = 0; i < m; i++) scanf("%d", &a[i]);
      ct = t = 0;
      while(n--){
         scanf("%d",&u);
         if(t==0){
            while(ct != u){
               v.insert(a[ct]);
               ct++;
            }
            it = v.begin();
         }
         else{
            while(ct != u){
               if(a[ct] < *it) v.insert(a[ct]), --it;
               else v.insert(a[ct]);
               ct++;
            }
         }
         if(t) ++it;
         printf("%d\n", *it);
         t++;
      }
      if(tc) putchar('\n');
   }
   return(0);
}
