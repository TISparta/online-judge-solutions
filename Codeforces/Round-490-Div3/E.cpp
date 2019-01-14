/**
 * > Author: TISparta
 * > Date: 08-01-19
 * > Tags: DFS, Greedy
 * > Difficulty: 4 / 10
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 5e3 + 10;

vector <int> G[MAX_V];
vector <bool> vis1, vis2;

int dfs2 (int u) {
  vis2[u] = true;
  int ret = vis1[u] == false;
  for (int v: G[u]) if (not vis2[v]) ret += dfs2(v);
  return ret;
}

int dfs1 (int u) {
  vis1[u] = true;
  int ret = 1;
  for (int v: G[u]) if (not vis1[v]) ret += dfs1(v);
  return ret;
}

int main () {
  int n, m, s;
  cin >> n >> m >> s;
  s--;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    G[--u].push_back(--v);
  }
  vis1.resize(n, false);
  vis2.resize(n, false);
  set <pair <int, int>> Q;
  dfs1(s);
  for (int u = 0; u < n; u++) {
    if (not vis1[u]) {
      fill(begin(vis2), end(vis2), false);
      Q.insert({dfs2(u), u});
    }
  }
  int ans = 0;
  while (not Q.empty()) {
    int u = rbegin(Q) -> second;
    Q.erase(Q.find(*rbegin(Q)));
    if (vis1[u]) continue;
    ans++;
    dfs1(u);
  }
  cout << ans << endl;
  return  (0);
}
