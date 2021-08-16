// Tags: Brute Force
// Difficulty: 5.0
// Priority: 4
// Date: 09-06-2017

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e6 + 10;

int n, m, a[MAX_N], LCM[MAX_N], f[MAX_N], l = 1, k;

int main(){
   cin >> n >> m;
   for(int i = 0; i < n; i++) scanf("%d", a + i);
   for(int i = 0; i < n; i++)
      if( a[i] <= m ) f[ a[i] ]++;
   for(int i = 1; i <= m; i++)
      for(int j = i; j <= m; j += i)
         LCM[j] += f[i];
   for(int i = 1; i <= m; i++)
      if( LCM[i] > k ) l = i, k = LCM[i];
   cout << l << ' ' << k << endl;
   for(int i = 0; i < n; i++)
      if( l % a[i] == 0 ) printf("%d ", i + 1); cout << endl;
   return(0);
}
