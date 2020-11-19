// Brute Force
// 3
// 15-02-2017

#include <bits/stdc++.h>

using namespace std;

int n, l, r, c, p, idx;
vector <int> a, b, id;

int main(){
   cin >> n >> l >> r;
   a.resize(n + 1), b.resize(n + 1), id.resize(n + 1);
   for(int it = 1; it <= n; it++) cin >> a[it];
   for(int it = 1; it <= n; it++) cin >> p, id[p] = it;
   c = l - a[id[1]] - 1;
   for(int it = 1; it <= n; it++){
      idx = id[it];
      b[idx] = max(c + a[idx] + 1, l);
      c = b[idx] - a[idx];
      if( b[idx] > r ){
         puts("-1");
         return(0);
      }
   }
   for(int it = 1; it <= n; it++)
      printf( it == n ? "%d\n" : "%d ", b[it]);
   return(0);
}
