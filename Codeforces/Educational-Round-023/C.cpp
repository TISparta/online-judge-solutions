// Brute Force
// 3
// 27-08-2020

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MX_SUM = 9 * 18;

int sumOfDigits (ll num) {
  int ret = 0;
  while (num) ret += (num % 10), num /= 10;
  return ret;
}

int main () {
  ll n, s;
  cin >> n >> s;
  ll ans = 0, k;
  for (k = s; k <= min(n, s + MX_SUM); k++) {
    if (k - sumOfDigits(k) >= s) ans++;
  }
  ans += max(0LL, n - k + 1);
  cout << ans << endl;
  return (0);
}
