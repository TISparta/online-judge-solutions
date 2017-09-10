#include <bits/stdc++.h>

#define SIZE 10010 

using namespace std;

int n, p, j, ans, ct;
double l, dx, r, w, lo, _max;
pair <double, double> v[SIZE];

int main(){
   while(scanf("%d %lf %lf", &n, &l, &w) == 3){
      ct = 0, w /= 2.0;
      for(int i = 0; i < n; i++){
         scanf("%d %lf", &p, &r);
         if(r > w){
            dx = sqrt(r * r - w * w);
            v[ct++] = make_pair(p - dx, p + dx);
         }
      }
      sort(v, v + ct);
      lo = ans = 0;
      for(int i = 0; i < ct && lo < l; ans++){
         _max = lo;
         for(j = i; j < ct && v[j].first <= lo; j++)
            _max = max(_max, v[j].second);
         lo = _max;
         if(j == i) break;
         i = j;
      }
      ans = (lo < l) ? -1 : ans;
      printf("%d\n", ans);
   }
   return(0);
}
