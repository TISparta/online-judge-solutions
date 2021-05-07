// Tags: DP, Greedy
// Difficulty: 6.7
// Priority: 1
// Date: 30-04-2021

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
  ll n, q, t;
  cin >> n >> q >> t;
  vll a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vi nxt(n + 1, -1);
  vi source(n + 1, 1);
  for (int i = 0; i < q; i++) {
    int u, v;
    cin >> u >> v;
    source[u] = 0;
    nxt[v] = u;
  }
  vll cost(n + 1, 0);
  vi vis(n + 1, 0);
  for (int u = 1; u <= n; u++) {
    if (source[u] == 0) continue;
    vi dag;
    int cur = u;
    while (cur != -1) {
      vis[cur] = 1;
      dag.pb(cur);
      cur = nxt[cur];
    }
    ll sum = 0;
    for (int j = sz(dag) - 1; j >= 0; j--) {
      sum += a[dag[j]];
      cost[dag[j]] = sum;
      if (j != 0) t -= sum;
    }
  }
  if (t < 0 or accumulate(all(vis), 0) != n) {
    cout << 0 << '\n';
    return (0);
  }
  vi dp(t + 1, 0);
  const int mod = 1e9 + 7;
  dp[0] = 1;
  for (int u = 1; u <= n; u++) {
    ll add = cost[u];
    for (ll z = 0; z + add <= t; z++) {
      dp[z + add] += dp[z];
      if (dp[z + add] >= mod) dp[z + add] -= mod;
    }
  }
  cout << dp[t] << '\n';
  return (0);
}
