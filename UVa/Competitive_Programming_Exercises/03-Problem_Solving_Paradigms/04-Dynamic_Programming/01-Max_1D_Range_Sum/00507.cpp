#include <bits/stdc++.h>

using namespace std;

int tc, s, v, ans, pre, sum;
pair <int, int> r;

int main(){
   scanf("%d", &tc);
   for(int t = 1; t <= tc; t++){
      ans = sum = 0;
      pre = 1;
      scanf("%d", &s);
      for(int i = 1; i < s; i++){
         scanf("%d", &v);
         sum += v;
         if(ans < sum) ans = sum, r = make_pair(pre, i);
         if(ans == sum && i - pre > r.second - r.first) r = make_pair(pre, i);
         if(sum < 0) sum = 0, pre = i + 1;
      }
      if(ans == 0) printf("Route %d has no nice parts\n", t);
      else printf("The nicest part of route %d is between stops %d and %d\n", t, r.first, r.second + 1);
   }
   return(0);
}
