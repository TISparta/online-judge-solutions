// Tags: Constructive Algorithms
// Difficulty: 5.0
// Priority: 3
// Date: 07-01-2019

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5 + 10;

int n, parent[MAX_N];
long long s[MAX_N], a[MAX_N];
vector <int> G[MAX_N];
bool ok = true;

void dfs (int u, int sum = 0, int h = 1) {
  if (h == 0) {
    if (G[u].empty()) {
      a[u] = 0;
      return;
    }
    long long val = 1e15;
    for (int v: G[u]) val = min(val, s[v] - sum);
    if (val < 0) ok = false;
    a[u] = val;
  }
  else a[u] = s[u] - sum;
  for (int v: G[u]) dfs(v, sum + a[u], h ^ 1);
}

int main () {
  cin >> n;
  for (int i = 2; i <= n; i++) {
    cin >> parent[i];
    G[parent[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) cin >> s[i];
  memset(a, -1, sizeof a);
  dfs(1);
  if (ok) cout << accumulate(a + 1, a + n + 1, 0LL) << endl;
  else cout << -1 << endl;
  return (0);
}
