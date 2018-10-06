/**
 * > Author : TISparta
 * > Date : 06-10-18
 * > Tags : LCA
 * > Difficulty : 5 / 10
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 4.5e5 + 10, LG = 20, MAX_BITS = 6;

struct Mask {
  vector <long long> b;
  Mask () {
    b.resize(MAX_BITS, 0LL);
  }
  void clear () {
    for (int i = 0; i < MAX_BITS; i++) b[i] = 0LL; 
  }
  void set (int val) {
    b[val / 60] |= (1LL << (val % 60));
  }
  Mask& operator |= (const Mask& other) {
    for (int i = 0; i < MAX_BITS; i++) b[i] |= other.b[i];
    return *this;
  }
  int count () {
    int ret = 0;
    for (int i = 0; i < MAX_BITS; i++) ret += __builtin_popcountll(b[i]);
    return ret;
  }
};

int V, Q, root, H[MAX_V], up[LG][MAX_V], color[MAX_V];
vector <int> G[MAX_V];
Mask ans[MAX_V];

Mask dfs (int u, int p = -1) {
  ans[u].set(color[u]);
  for (int bit = 1; bit < LG; bit++) {
    int v = up[bit - 1][u];
    if (v == -1) break;
    up[bit][u] = up[bit - 1][v];
  }
  for (int v: G[u]) {
    if (v == p) continue;
    H[v] = H[u] + 1;
    up[0][v] = u;
    ans[u] |= dfs(v, u);
  }
  return ans[u];
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
    if (up[bit][u] != up[bit][v])
      u = up[bit][u], v = up[bit][v];
  return up[0][u];
}

void processQueries () {
  while (Q--) {
    int u, v;
    scanf("%d %d", &u, &v);
    printf("%d\n", ans[getLCA(u, v)].count());
  }
}

void readTree () {
  scanf("%d %d %d", &V, &Q, &root);
  for (int i = 0; i < V; i++) scanf("%d", color + i);
  for (int i = 1; i < V; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
}

void clear () {
  for (int i = 0; i < LG; i++) fill(up[i], up[i] + V, -1);
  for (int i = 0; i < V; i++) {
    G[i].clear();
    ans[i].clear();
    H[i] = 0;
  }
}

int main () {
  memset(up, -1, sizeof up);
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    readTree();
    dfs(root);
    processQueries();
    clear();  
  }
  return (0);
}
