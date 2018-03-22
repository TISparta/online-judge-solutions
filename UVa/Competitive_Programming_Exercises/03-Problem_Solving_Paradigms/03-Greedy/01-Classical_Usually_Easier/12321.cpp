#include <bits/stdc++.h>

#define SIZE 10010

using namespace std;

int L, G, x, r, lo, ans, _max, j;
pair <int, int> v[SIZE];

int main(){
   while(scanf("%d %d", &L, &G), L | G){
      for(int i = 0; i < G; i++)
         scanf("%d %d", &x, &r), v[i] = make_pair(x - r, x + r);
      sort(v, v + G);
      lo = ans = 0;
      for(int i = 0; i < G && lo < L; ++ans){
         _max = lo;
         for(j = i; j < G && v[j].first <= lo; j++)
            _max = max(_max, v[j].second);
         lo = _max;
         if(j == i) break;
         i = j;
      }
      ans = (lo < L) ? -1 : G - ans;
      printf("%d\n", ans);
   }
   return(0);
}
