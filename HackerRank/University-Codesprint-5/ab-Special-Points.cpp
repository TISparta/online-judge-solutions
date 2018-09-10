/**
 * > Author : TISparta
 * > Date : 09-09-18
 * > Tags : DFS
 * > Difficulty : 3 / 10
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 3e5;

int n, m, a, b;
int vis[MAX_N + 10];
vector <int> G[MAX_N + 10];
int mn, mx, ans;

void dfs2 (int u) {
  int adj = int(G[u].size());
  if (1LL * mn * a < adj and adj < 1LL * b * mx) ans++;
  vis[u] = 2;
  for (int v: G[u]) if (vis[v] == 1) dfs2(v);
}

void dfs1 (int u) {
  vis[u] = 1;
  mn = min(mn, int(G[u].size()));
  mx = max(mx, int(G[u].size()));
  for (int v: G[u]) if (vis[v] == 0) dfs1(v);
}

void solve () {
  for (int u = 1; u <= n; u++) {
    if (vis[u] == 0) {
      mn = INT_MAX, mx = INT_MIN;
      dfs1(u);
      dfs2(u);
    }
  }
}

int main () {
  cin >> n >> m >> a >> b;
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  solve();
  cout << ans << endl;
  return (0);
}
