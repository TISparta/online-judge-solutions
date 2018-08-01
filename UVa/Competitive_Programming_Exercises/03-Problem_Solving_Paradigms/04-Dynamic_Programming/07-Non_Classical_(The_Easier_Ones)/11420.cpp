#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int SIZE = 70;

ll n, s, memo[2][SIZE][SIZE];

ll dp (bool secure, int locked, int id) {
  if (id == n) return locked == s;
  if (~memo[secure][locked][id]) return memo[secure][locked][id];
  ll ret = 0;
  ret += dp(true, locked + secure, id + 1);
  ret += dp(false, locked, id + 1);
  return memo[secure][locked][id] = ret;
}

int main () {
  while (cin >> n >> s) {
    if (n < 0 and s < 0) break;
    memset(memo, -1, sizeof memo);
    if (s > n) cout << 0 << endl;
    else cout << dp(true, 0, 0) << endl;
  }
  return (0);
}
