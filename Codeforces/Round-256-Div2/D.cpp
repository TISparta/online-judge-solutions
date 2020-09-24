// Binary Search
// 4
// 20-01-2019

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main () {
  ll n, m, k;
  cin >> n >> m >> k;
  ll l = 1, r = n * m;
  while (l != r) {
    ll mid = (l + r + 1) >> 1;
    ll cnt = 0;
    for (int row = 1; row <= n; row++) {
      cnt += min(m, (mid - 1) / row);
    }
    if (cnt < k) l = mid;
    else r = mid - 1;
  }
  cout << l << endl;
  return (0);
}
