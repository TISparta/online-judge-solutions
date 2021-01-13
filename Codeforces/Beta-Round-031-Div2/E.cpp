// DP
// 4
// 13-03-2019

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main () {
  vector <ll> pow10(18);
  pow10[0] = 1;
  for (int i = 1; i < int(pow10.size()); i++) pow10[i] = 10LL * pow10[i - 1];
  int n;
  string s;
  cin >> n >> s;
  for (char& ch: s) ch -= '0';
  vector <vector <ll>> dp(2 * n + 1, vector <ll> (n + 1, 0LL));
  vector <vector <int>> path(2 * n + 1, vector <int> (n + 1, 0));
  for (int i = 1; i <= 2 * n; i++) {
    for (int take = 0; take <= n; take++) {
      if (take > i - 1) break;
      if (take + 1 <= n) {
        ll val = dp[i - 1][take] + pow10[n - 1 - take] * s[i - 1];
        if (val >= dp[i][take + 1]) {
          dp[i][take + 1] = val;
          path[i][take + 1] = -1;
        }
      }
      int notake = (i - 1) - take;
      if (notake + 1 <= n) {
        ll val = dp[i - 1][take] + pow10[n - 1 - notake] * s[i - 1];
        if (val >= dp[i][take]) {
          dp[i][take] = val;
          path[i][take] = 0;
        }
      }
    }
  }
  string ans = "";
  int take = n;
  for (int i = 2 * n; i >= 1; i--) {
    int go = path[i][take];
    if (go == 0) ans += 'H';
    else ans += 'M';
    take += go;
  }
  reverse(begin(ans), end(ans));
  cout << ans << endl;
  return (0);
}
