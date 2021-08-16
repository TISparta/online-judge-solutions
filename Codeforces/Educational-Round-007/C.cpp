// Tags: Implementation
// Difficulty: 3.0
// Priority: 2
// Date: 08-06-2017

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2e5 + 10;

int n, m, l, r, x, a[MAX_N], left_ancestor[MAX_N];

int main(){
   scanf("%d %d", &n, &m);
   for(int i = 1; i <= n; i++) scanf("%d", a + i);
   for(int i = 2; i <= n; i++)
      if( a[i] == a[i - 1] ) left_ancestor[i] = left_ancestor[i - 1];
      else left_ancestor[i] = i - 1;
   while(m--){
      scanf("%d %d %d", &l, &r, &x);
      if( a[r] != x ) printf("%d\n", r);
      else if( left_ancestor[r] and l <= left_ancestor[r] ) printf("%d\n", left_ancestor[r]);
      else puts("-1");
   }
   return(0);
}
