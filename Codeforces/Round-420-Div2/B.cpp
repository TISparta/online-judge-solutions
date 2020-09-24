// Brute Force
// 2
// 29-12-2018

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll m, b;

inline ll s (const ll& n) { return n * (n + 1) >> 1; }

inline ll get (const ll& x, const ll& y) { return s(x) * (y + 1) + s(y) * (x + 1); }

int main () {
  cin >> m >> b;
  ll ans = 0LL;
  for (int x = 0; x <= m * b; x++) ans = max(ans, get(x, b - (x + m - 1) / m));
  cout << ans << endl;
  return (0);
}
