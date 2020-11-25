// DP
// 4
// 24-11-2020

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
  int n, k, x;
  cin >> n >> k >> x;
  const ll INF = 1e15;
  vector <vll> dp(n + 1, vll(x + 1, -INF));
  vll a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  dp[n][0] = 0;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 1; j <= x; j++) {
      for (int ii = i + 1; ii <= min(n, i + k); ii++) {
        dp[i][j] = max(dp[i][j], a[i] + dp[ii][j - 1]);
      }
    }
  }
  ll ans = -INF;
  for (int i = 0; i < k; i++) ans = max(ans, dp[i][x]);
  if (ans < 0) ans = -1;
  cout << ans << '\n';
  return (0);
}
