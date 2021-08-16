// Tags: DP
// Difficulty: 5.3
// Priority: 3
// Date: 01-02-2019

#include <bits/stdc++.h>

using namespace std;

const int MAX_M = 2e3 + 10, MOD = 1e9 + 7;

typedef long long ll;

inline ll add (ll a, ll b) { return (a + b) % MOD; }

int M, D, memo[MAX_M][MAX_M][3][3];
string a, b;

int dp (int pos, int rem, int lt, int gt) {
  if (pos == int(a.size())) return rem == 0;
  if (~memo[pos][rem][lt][gt]) return memo[pos][rem][lt][gt];
  ll ret = 0;
  if (lt and gt) {
    for (int d = 0; d <= 9; d++) {
      if (pos % 2 == 1 and d != D) continue;
      if (pos % 2 == 0 and d == D) continue;
      ret = add(ret, dp(pos + 1, (rem * 10 + d) % M, lt, gt));
    }
  }
  else if (lt) {
    for (int d = a[pos] - '0'; d <= 9; d++) {
      if (pos % 2 == 1 and d != D) continue;
      if (pos % 2 == 0 and d == D) continue;
      ret = add(ret, dp(pos + 1, (rem * 10 + d) % M, lt, d > a[pos] - '0'));
    }
  }
  else if (gt) {
    for (int d = 0; d <= b[pos] - '0'; d++) {
      if (pos % 2 == 1 and d != D) continue;
      if (pos % 2 == 0 and d == D) continue;
      ret = add(ret, dp(pos + 1, (rem * 10 + d) % M, d < b[pos] - '0', gt));
    }
  }
  else {
    for (int d = a[pos] - '0'; d <= b[pos] - '0'; d++) {
      if (pos % 2 == 1 and d != D) continue;
      if (pos % 2 == 0 and d == D) continue;
      ret = add(ret, dp(pos + 1, (rem * 10 + d) % M, d < b[pos] - '0', d > a[pos] - '0'));
    }
  }
  return memo[pos][rem][lt][gt] = ret;
}

int main () {
  memset(memo, -1, sizeof memo);
  cin >> M >> D >> a >> b;
  cout << dp(0, 0, 0, 0) << endl;
  return (0);
}
