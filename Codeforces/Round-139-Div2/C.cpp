// Tags: DP
// Difficulty: 3.3
// Priority: 2
// Date: 18-08-2021

#include <bits/stdc++.h>
     
#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple

using namespace std;
     
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <pii> vpii;
typedef vector <pll> vpll;

const int N = 1010;
int dp[N][N][2];

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  memset(dp, -1, sizeof dp);
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  vector <string> s(n);
  for (int i = 0; i < n; i++) cin >> s[i];
  vi a(m);
  for (int c = 0; c < m; c++) {
    for (int r = 0; r < n; r++) a[c] += (s[r][c] == '#');
  }
  const int INF = 1e9;
  function <int(int,int,int)> rec = [&] (int i, int cnt, int type) {
    if (i == m) return (cnt == 0) ? 0 : INF;
    if (dp[i][cnt][type] != -1) return dp[i][cnt][type];
    int ret = INF;
    if (cnt + 1 <= y) ret = min(ret, (type == 0 ? a[i] : n - a[i]) + rec(i + 1, cnt + 1, type));
    if (x <= cnt + 1 and cnt + 1 <= y) ret = min(ret, (type == 0 ? a[i] : n - a[i]) + rec(i + 1, 0, 1 - type));
    return dp[i][cnt][type] = ret;
  };
  int ans = min(rec(0, 0, 0), rec(0, 0, 1));
  cout << ans << '\n';
  return (0);
}
