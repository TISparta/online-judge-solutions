/**
 * > Author : TISparta
 * > Date : 05-10-18
 * > Tags : LCA
 * > Difficulty : 4 / 10
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 1e5 + 10, LG = 17;

int V, up[LG][MAX_V], maxW[LG][MAX_V], H[MAX_V];
vector <pair <int, int>> G[MAX_V];

void dfs (int u, int p = -1) {
  for (int bit = 1; bit < LG; bit++) {
    int v = up[bit - 1][u];
    if (v == -1) break;
    up[bit][u] = up[bit - 1][v];
    maxW[bit][u] = max(maxW[bit - 1][u], maxW[bit - 1][v]);
  }
  for (auto v: G[u]) {
    if (v.first != p) {
      H[v.first] = H[u] + 1;
      up[0][v.first] = u;
      maxW[0][v.first] = v.second;
      dfs(v.first, u);
    }
  }
}

int walk (int u, int k, int& mx) {
  for (int bit = LG - 1; bit >= 0; bit--)
    if ((k >> bit) bitand 1) {
      mx = max(mx, maxW[bit][u]);
      u = up[bit][u];
    }
  return u;
}

void getLCA (int u, int v, int& mx) {
  if (H[u] < H[v]) swap(u, v);
  u = walk(u, H[u] - H[v], mx);
  if (u == v) return;
  for (int bit = LG - 1; bit >= 0; bit--)
    if (up[bit][u] != up[bit][v]) {
      mx = max(mx, max(maxW[bit][u], maxW[bit][v]));
      u = up[bit][u];
      v = up[bit][v];
    }
  mx = max(mx, max(maxW[0][u], maxW[0][v]));
  return;
}

void processQueries () {
  int q;
  scanf("%d", &q);
  while (q--) {
    int u, v;
    scanf("%d %d", &u, &v);
    int mx = 0;
    getLCA(u, v, mx);
    printf("%d\n", mx);
  }
}

void readTree () {
  for (int i = 1; i < V; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    G[u].push_back({v, w});
    G[v].push_back({u, w});
  }
}

void clear () {
  memset(up, -1, sizeof up);
  for (int i = 1; i <= V; i++) G[i].clear();
}

int main () {
  while (scanf("%d", &V), V) {
    clear();
    readTree();
    dfs(1);
    processQueries();
    puts("");
  }
  return (0);
}
