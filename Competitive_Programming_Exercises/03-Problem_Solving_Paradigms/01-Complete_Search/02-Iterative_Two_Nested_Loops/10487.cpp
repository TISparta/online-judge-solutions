#include <bits/stdc++.h>

using namespace std;

int n, m, q, ans, _min, tc;
vector <int> v;

int main(){
   while(scanf("%d", &n), n){
      v.resize(n);
      for(int i = 0; i < n; i++)
         scanf("%d", &v[i]);
      scanf("%d", &m);
      printf("Case %d:\n", ++tc);
      while(m--){
         scanf("%d", &q);
         _min = INT_MAX;
         for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
               if(i != j && abs(q- (v[i] + v[j])) < _min)
                  _min = abs(q - (v[i] + v[j])), ans = v[i] + v[j];
         printf("Closest sum to %d is %d.\n", q, ans);
      }
   }
}
