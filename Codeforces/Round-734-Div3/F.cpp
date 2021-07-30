// Tags: DFS, DP
// Difficulty: 5.5
// Priority: 1
// Date: 23-07-2021

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
  const int mod = 1e9 + 7;
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector <vi> g(n + 1);
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
    }
    if (k == 2) {
      cout <<  1LL * n * (n - 1) / 2 << '\n';
      continue;
    }
    vi level(n + 1);
    vi cnt(n, 0);
    vi vis;
    function <void(int,int)> dfs = [&] (int u, int p) {
      level[u] = level[p] + 1;
      cnt[level[u]] += 1;
      vis.pb(level[u]);
      for (int v: g[u]) if (v != p) dfs(v, u);
    };
    int ans = 0;
    for (int c = 1; c <= n; c++) {
      level[c] = 0;
      vector <vi> z(n);
      for (int v: g[c]) {
        dfs(v, c);
        sort(all(vis));
        vis.erase(unique(all(vis)), end(vis));
        for (int l: vis) {
          z[l].pb(cnt[l]);
          cnt[l] = 0;
        }
        vis.clear();
      }
      for (int l = 1; l < n; l++) {
        int p = sz(z[l]);
        if (p < k) continue;
        vector <vi> dp(p + 1, vi(k + 1));
        for (int i = 1; i <= p; i++) {
          dp[i - 1][0] = 1;
          for (int j = 1; j <= k; j++) {
            dp[i][j] = dp[i - 1][j];
            dp[i][j] += (1LL * dp[i - 1][j - 1] * z[l][i - 1]) % mod;
            if (dp[i][j] >= mod) dp[i][j] -= mod;
          }
        }
        ans += dp[p][k];
        if (ans >= mod) ans -= mod;
      }
    }
    cout << ans << '\n';
  }
  return (0);
}
