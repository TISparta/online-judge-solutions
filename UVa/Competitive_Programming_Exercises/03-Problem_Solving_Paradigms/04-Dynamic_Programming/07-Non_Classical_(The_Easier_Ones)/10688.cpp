#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 510, INF = 1e7;

int n, k, memo[MAX_N][MAX_N];

int dp (int l, int r) {
  if (l >= r) return 0;
  if (~memo[l][r]) return memo[l][r];
  int ret = INF;
  for (int i = l; i <= r; i++) {
    ret = min(ret, (i + k) * (r - l + 1) + dp(l, i - 1) + dp(i + 1, r));
  }
  return memo[l][r] = ret;
}

int main () {
  int tc;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    memset(memo, -1, sizeof memo);
    cin >> n >> k;
    cout << "Case " << t << ": " << dp(1, n) << endl;
  }
  return (0);
}
