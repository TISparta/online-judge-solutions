// Tags: DP
// Difficulty: 6.3
// Priority: 5
// Date: 06-03-2020

#include <bits/stdc++.h>
     
#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define mp make_pair
     
using namespace std;
     
typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <ll> vll;
     
int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector <int> t(n + 1);
  vector <int> d(n + 1);
  for (int i = 1; i <= n; i++) cin >> t[i] >> d[i];
  const int INF = 1e9;
  vector <vi> dp(n + 1, vi (k + 1, INF));
  for (int j = 0; j <= k; j++) dp[0][j] = 1;
  // dp[i][j] = minimum time to finish the first i calls
  // ignoring at most j of them
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      if (j) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]); // ignore
      dp[i][j] = min(dp[i][j], max(dp[i - 1][j], t[i]) + d[i]);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, t[i] - dp[i - 1][k]);
  }
  ans = max(ans, 86400 - dp[n][k] + 1);
  cout << ans << '\n';
  return (0);
}
