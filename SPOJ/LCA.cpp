/**
 * > Author : TISparta
 * > Date : 05-10-18
 * > Tags : LCA
 * > Difficulty : 3 / 10
 */

#include <bits/stdc++.h>

#define pb(A) push_back(A)

using namespace std;

const int MAX_V = 1e3 + 10, LG = 12;

int V, up[LG][MAX_V], H[MAX_V];
vector <int> G[MAX_V];

void dfs (int u, int p = -1) {
  up[0][u] = p;
  for (int bit = 1; bit < LG; bit++) {
    int v = up[bit - 1][u];
    if (v == -1) break;
    up[bit][u] = up[bit - 1][v];
  }
  for (int v: G[u]) {
    if (v != p) {
      H[v] = H[u] + 1;
      dfs(v, u);
    }
  }
}

int walk (int u, int k) {
  for (int bit = LG - 1; bit >= 0; bit--)
    if ((k >> bit) bitand 1) u = up[bit][u];
  return u;
}

int getLCA (int u, int v) {
  if (H[u] < H[v]) swap(u, v);
  u = walk(u, H[u] - H[v]);
  if (u == v) return u;
  for (int bit = LG - 1; bit >= 0; bit--)
    if (~up[bit][u] and up[bit][u] != up[bit][v])
      u = up[bit][u], v = up[bit][v];
  return up[0][u];
}

void processQueries () {
  int q;
  scanf("%d", &q);
  while (q--) {
    int u, v;
    scanf("%d %d", &u, &v);
    printf("%d\n", getLCA(u, v));
  }
}

void readTree () {
  scanf("%d", &V);
  for (int u = 1; u <= V; u++) {
    int cnt;
    scanf("%d", &cnt);
    while (cnt--) {
      int v;
      scanf("%d", &v);
      G[u].pb(v);
      G[v].pb(u);
    }
  }
}

void clear () {
  memset(up, -1, sizeof up);
  for (int u = 0; u < MAX_V; u++) G[u].clear();
}

int main () {
  int tc;
  scanf("%d", &tc);
  for (int t = 1; t <= tc; t++) {
    clear();
    readTree();
    dfs(1);
    printf("Case %d:\n", t);
    processQueries();
  }
  return (0);
}
