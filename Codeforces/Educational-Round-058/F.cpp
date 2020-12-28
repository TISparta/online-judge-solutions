// DP
// 6
// 14-01-2019

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 402;

typedef long long ll;

int n, m, city[MAX_N], dp[MAX_N][MAX_N][MAX_N];

int main () {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> city[i];
  for (int l = 1; l <= n; l++) for (int r = l; r <= n; r++) dp[l][r][0] = city[r] - city[l];
  for (int l = 1; l <= n; l++) {
    for (int k = 1; k <= n; k++) {
      int best = l;
      for (int r = l; r <= n; r++) {
        while (best < r and max(city[r] - city[best], dp[l][best][k - 1]) >= max(city[r] - city[best + 1], dp[l][best + 1][k - 1])) {
          best++;
        }
        dp[l][r][k] = max(dp[l][best][k - 1], city[r] - city[best]);
      }
    }
  }
  ll ans = 0;
  for (int i = 1; i <= m; i++) {
    int s, t, cost, times;
    cin >> s >> t >> cost >> times;
    ans = max(ans, 1LL * dp[s][t][times] * cost);
  }
  cout << ans << endl;
  return (0);
}
