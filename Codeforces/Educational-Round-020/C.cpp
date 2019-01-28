/**
 * > Author: TISparta
 * > Date: 07-01-19
 * > Tags: Greedy
 * > Difficulty: 3 / 10
 */

#include <bits/stdc++.h>

using namespace std;

bool check (long long d, long long k, long long n) {
  long long last = n - d * k * (k - 1) / 2;
  long double L = n - 1.0 * d * k * (k - 1) / 2;
  if (L < 0) return false;
  return last > 0 and last % d == 0 and last > d * (k - 1);
}

int main () {
  long long n, k;
  cin >> n >> k;
  long long ans = -1;
  for (long long d = 1; d * d <= n; d++) {
    if (n % d == 0) {
      if (check(d, k, n)) ans = max(ans, d);
      if (check(n / d, k, n)) ans = max(ans, n / d);
    }
  }
  if (~ans) {
    for (int i = 1; i + 1 <= k; i++) cout << ans * i << ' ';
    cout << n - ans * k * (k - 1) / 2 << endl;
  }
  else cout << -1 << endl;
  return (0);
}
