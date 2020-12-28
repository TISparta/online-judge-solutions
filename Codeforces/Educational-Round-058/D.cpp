// DP on trees, Number Theory
// 5
// 14-01-2019

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2e5 + 10;

int n, ans, a[MAX_N];
vector <int> primes[MAX_N];
vector <int> G[MAX_N];
map <pair <int, int>, int> dp;

void dfs (int u, int p) {
  for (int pu: primes[a[u]]) {
    dp[{u, pu}] = 1;
    ans = max(ans, 1);
  }
  for (int v: G[u]) {
    if (v == p) continue;
    dfs(v, u);
    for (int pu: primes[a[u]]) {
      for (int pv: primes[a[v]]) {
        if (pu == pv) {
          ans = max(ans, dp[{u, pu}] + dp[{v, pv}]);
          dp[{u, pu}] = max(dp[{u, pu}], dp[{v, pv}] + 1);
          ans = max(ans, dp[{u, pu}]);
        }
      }
    }
  }
}

int main () {
  for (int u = 2; u < MAX_N; u++) if (primes[u].empty()) for (int v = u; v < MAX_N; v += u) primes[v].push_back(u);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  bool oneForAll = true;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    oneForAll &= (a[i] == 1);
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  if (oneForAll) {
    puts("0");
    return (0);
  }
  dfs(1, 1);
  cout << ans << endl;
  return (0);
}
