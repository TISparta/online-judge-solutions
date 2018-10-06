/**
 * > Author : TISparta
 * > Date : 05-10-18
 * > Tags : LCA
 * > Difficulty : 4 / 10
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 1e5 + 10, LG = 17;

int V, up[LG][MAX_V], minW[LG][MAX_V], maxW[LG][MAX_V], H[MAX_V];
vector <pair <int, int>> G[MAX_V];

void dfs (int u, int p = -1) {
  for (int bit = 1; bit < LG; bit++) {
    int v = up[bit - 1][u];
    if (v == -1) break;
    up[bit][u] = up[bit - 1][v];
    minW[bit][u] = min(minW[bit - 1][u], minW[bit - 1][v]);
    maxW[bit][u] = max(maxW[bit - 1][u], maxW[bit - 1][v]);
  }
  for (auto v: G[u]) {
    if (v.first != p) {
      H[v.first] = H[u] + 1;
      up[0][v.first] = u;
      minW[0][v.first] = maxW[0][v.first] = v.second;
      dfs(v.first, u);
    }
  }
}

int walk (int u, int k, int& mn, int& mx) {
  for (int bit = LG - 1; bit >= 0; bit--)
    if ((k >> bit) bitand 1) {
      mn = min(mn, minW[bit][u]);
      mx = max(mx, maxW[bit][u]);
      u = up[bit][u];
    }
  return u;
}

void getLCA (int u, int v, int& mn, int& mx) {
  if (H[u] < H[v]) swap(u, v);
  u = walk(u, H[u] - H[v], mn, mx);
  if (u == v) return;
  for (int bit = LG - 1; bit >= 0; bit--)
    if (~up[bit][u] and up[bit][u] != up[bit][v]) {
      mn = min(mn, min(minW[bit][u], minW[bit][v]));
      mx = max(mx, max(maxW[bit][u], maxW[bit][v]));
      u = up[bit][u];
      v = up[bit][v];
    }
  mn = min(mn, min(minW[0][u], minW[0][v]));
  mx = max(mx, max(maxW[0][u], maxW[0][v]));
  return;
}

void processQueries () {
  int q;
  scanf("%d", &q);
  while (q--) {
    int u, v;
    scanf("%d %d", &u, &v);
    int mn = INT_MAX, mx = 0;
    getLCA(u, v, mn, mx);
    printf("%d %d\n", mn, mx);
  }
}

void readTree () {
  scanf("%d", &V);
  for (int i = 1; i < V; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    G[u].push_back({v, w});
    G[v].push_back({u, w});
  }
}

void clear () {
  memset(up, -1, sizeof up);
  fill(minW[0], minW[LG], INT_MAX);
}

int main () {
  clear();
  readTree();
  dfs(1);
  processQueries();
  return (0);
}
