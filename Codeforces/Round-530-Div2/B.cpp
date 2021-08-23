// Tags: Math
// Difficulty: 1.6
// Priority: 3
// Date: 07-01-2019

#include <bits/stdc++.h>

using namespace std;

int main () {
  int n;
  cin >> n;
  int ans = INT_MAX;
  for (int a = 1; 1LL * a * a <= n; a++) ans = min(ans, a + (n + a - 1) / a);
  cout << ans << endl;
  return (0);
}
