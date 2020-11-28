// DP, Cummulative Sums
// 5
// 27-11-2020

#include <bits/stdc++.h>
     
#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define mp make_pair
     
using namespace std;
     
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <pii> vpii;
typedef vector <pll> vpll;

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m;
  string s;
  cin >> n >> s >> m;
  string t(m, 'a');
  for (int i = 1; i < m; i += 2) t[i] = 'b';
  vi acc_a(n);
  vi acc_b(n);
  for (int i = 0; i < 2; i++) {
    acc_a[i] = (s[i] == 'a' or s[i] == '?');
    acc_b[i] = (s[i] == 'b' or s[i] == '?');
  }
  for (int i = 2; i < n; i++) {
    acc_a[i] = (s[i] == 'a' or s[i] == '?') + acc_a[i - 2];
    acc_b[i] = (s[i] == 'b' or s[i] == '?') + acc_b[i - 2];
  }
  int cnt_a = (m + 1) / 2;
  int cnt_b = m - cnt_a;
  auto valid = [&] (int i) {
    int j = i + m - 1;
    if (j >= n) return false;
    int x = acc_a[i + m - 1 - (m % 2 == 0)] - (i - 2 >= 0 ? acc_a[i - 2] : 0);
    if (x != cnt_a) return false;
    if (m == 1) return true;
    int y = acc_b[i + m - 1 - (m % 2 == 1)] - (i - 1 >= 0 ? acc_b[i - 1] : 0);
    return (y == cnt_b);
  };
  vi acc(n + 1);
  acc[0] = 0;
  for (int i = 1; i <= n; i++) acc[i] = acc[i - 1] + (s[i - 1] == '?');
  vpii dp(n + 1);
  dp[n] = pii(0, 0);
  for (int i = n - 1; i >= 0; i--) {
    dp[i] = dp[i + 1];
    if (not valid(i)) continue;
    pii res = dp[i + m];
    res.first += 1;
    res.second -= (acc[i + m] - acc[i]);
    dp[i] = max(dp[i], res);
  }
  cout << -dp[0].second << '\n';
  return (0);
}
