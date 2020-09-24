// Binary Lifting
// 5
// 07-10-2019

#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 1e5 + 10, LG = 17;

int V, H[MAX_V], up[LG][MAX_V], sz[MAX_V];
vector <int> G[MAX_V];

int dfs (int u, int p = -1) {
  sz[u] = 1;
  for (int bit = 1; bit < LG; bit++) {
    int v = up[bit - 1][u];
    if (v == -1) break;
    up[bit][u] = up[bit - 1][v];
  }
  for (int v: G[u]) {
    if (v == p) continue;
    H[v] = H[u] + 1;
    up[0][v] = u;
    sz[u] += dfs(v, u);
  }
  return sz[u];
}

int walk (int u, int k) {
  for (int bit = LG - 1; bit >= 0; bit--)
    if ((k >> bit) bitand 1) u = up[bit][u];
  return u;
}

int getLCA (int u, int v) {
  u = walk(u, H[u] - H[v]);
  if (u == v) return u;
  for (int bit = LG - 1; bit >= 0; bit--)
    if (up[bit][u] != up[bit][v])
      u = up[bit][u], v = up[bit][v];
  return up[0][u];
}

int main () {
  memset(up, -1, sizeof up);
  scanf("%d", &V);
  for (int i = 1; i < V; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(1);
  int q;
  scanf("%d", &q);
  while (q--) {
    int u, v;
    scanf("%d %d", &u, &v);
    if (H[u] < H[v]) swap(u, v);
    int lca = getLCA(u, v);
    int path = (H[u] - H[lca]) + (H[v] - H[lca]);
    if (path bitand 1) {
      puts("0");
      continue;
    }
    if (u == v) {
      printf("%d\n", V);
      continue;
    }
    int m = walk(u, path / 2);
    if (m == lca) printf("%d\n", sz[1] - sz[walk(u, path / 2 - 1)] - sz[walk(v, path / 2 - 1)]);
    else printf("%d\n", sz[m] - sz[walk(u, H[u] - H[m] - 1)]);
  }
  return (0);
}
