// Tags: DP
// Difficulty: 6.5
// Priority: 3
// Date: 17-11-2021

#include <bits/stdc++.h>

#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector <int> vis(m + 1, false);
  vector <int> x(n);
  vector <int> s(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> s[i];
    for (int j = 1; j <= m; j++) if (x[i] - s[i] <= j and j <= x[i] + s[i]) vis[j] = true;
  }
  vector <int> dp(m + 2);
  dp[m + 1] = 0;
  for (int i = m; i >= 1; i--) {
    if (vis[i]) {
      dp[i] = dp[i + 1];
      continue;
    }
    dp[i] = m - i + 1;
    for (int j = 0; j < n; j++) {
      int l = x[j] - s[j];
      int r = min(m + 1, x[j] + s[j]);
      if (i < l) {
        int cost = l - i;
        dp[i] = min(dp[i], cost + dp[min(m + 1, r + cost + 1)]);
      }
    }
  }
  cout << dp[1] << '\n';
  return (0);
}
