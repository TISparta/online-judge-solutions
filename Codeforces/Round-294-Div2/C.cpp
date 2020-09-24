// Brute Force
// 3
// 17-01-2019

#include <bits/stdc++.h>

using namespace std;

int main () {
  int n, m, ans = 0;
  cin >> n >> m;
  while (true) {
    if (n > m) swap(n, m);
    if (not (1 <= n and 2 <= m)) break;
    ans++;
    n -= 1;
    m -= 2;
  }
  cout << ans << endl;
  return (0);
}
