/**
 * > Author: TISparta
 * > Date: 16-08-18
 * > Tags: DP
 * > Difficulty: 3 / 10
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, m;
vector <ll> s;
unordered_map <ll, ll> memo;

ll dp (ll y) {
  if (memo.count(y)) return memo[y];
  ll ret = 0;
  for (ll x: s) {
    if (x >= y) break;
    if (y % x == 0)
      ret = max(ret, 1 + (y / x) * dp(x));
  }
  return memo[y] = ret;
}

void readCase () {
  cin >> n >> m;
  s.resize(m);
  for (int i = 0; i < m; i++) cin >> s[i];
  sort(begin(s), end(s));
}

void initCase () {
  memo.clear();
}

int main () {
  int tc;
  cin >> tc;
  while (tc--) {
    initCase();
    readCase();
    cout << dp(n) << endl;
  }
  return (0);
}
