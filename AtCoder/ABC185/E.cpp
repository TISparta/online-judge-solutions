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
  cin >> n >> m;
  vi a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  vi b(m + 1);
  for (int i = 1; i <= m; i++) cin >> b[i];
  const int INF = 1e9;
  vector <vi> dp(n + 1, vi(m + 1, INF));
  for (int i = 0; i <= n; i++) dp[i][0] = i;
  for (int j = 0; j <= m; j++) dp[0][j] = j;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j] = (a[i] != b[j]) + dp[i - 1][j - 1];
      dp[i][j] = min(dp[i][j], 1 + dp[i - 1][j]);
      dp[i][j] = min(dp[i][j], 1 + dp[i][j - 1]);
    }
  }
  cout << dp[n][m] << '\n';
  return (0);
}
