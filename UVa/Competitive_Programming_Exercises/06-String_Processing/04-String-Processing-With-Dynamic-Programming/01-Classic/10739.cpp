#include <bits/stdc++.h>

using namespace std;

const int MAX_LEN = 1e3 + 5;

int memo[MAX_LEN][MAX_LEN];
string s;

int dp (int i, int j) {
  if (i > j) return memo[i][j] = 0;
  if (~memo[i][j]) return memo[i][j];
  if (s[i] == s[j]) return memo[i][j] = dp(i + 1, j - 1);
  return memo[i][j] = 1 + min(dp(i + 1, j - 1), min(dp(i + 1, j), dp(i, j - 1)));
}

int main () {
  int tc;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    memset(memo, -1, sizeof memo);
    cin >> s;
    printf("Case %d: %d\n", t, dp(0, s.size() - 1));
  }
  return (0);
}
