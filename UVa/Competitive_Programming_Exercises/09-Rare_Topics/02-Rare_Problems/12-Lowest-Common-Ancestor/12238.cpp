#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 1e5 + 10, LG = 18;

int V, H[MAX_V], jump[LG][MAX_V];
long long add[MAX_V];
vector <int> G[MAX_V], W[MAX_V];

void dfs (int u, int p = -1) {
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i], w = W[u][i];
    if (v != p) {
      H[v] = H[u] + 1;
      jump[0][v] = u;
      add[v] = w + add[u];
      dfs(v, u);
    }
  }
}

void buildLCA () {
  for (int k = 1; k < LG; k++) {
    for (int v = 0; v < V; v++) {
      int u = jump[k - 1][v];
      if (~u) jump[k][v] = jump[k - 1][u];
    }
  }
}

void walk (int& u, int d) {
  for (int k = LG - 1; k >= 0; k--) if ((d >> k) bitand 1) u = jump[k][u];
}

int getLCA (int u, int v) {
  if (H[u] < H[v]) swap(u, v);
  walk(u, H[u] - H[v]);
  if (u == v) return u;
  for (int k = LG - 1; k >= 0; k--) {
    if (jump[k][u] != jump[k][v]) {
      u = jump[k][u];
      v = jump[k][v];
    }
  }
  return jump[0][u];
}

void processQueries () {
  int q;
  scanf("%d", &q);
  while (q--) {
    int u, v;
    scanf("%d %d", &u, &v);
    printf("%lld", add[u] + add[v] - 2 * add[getLCA(u, v)]);
    if (q) putchar(' ');
  }
  putchar('\n');
}

bool readTree () {
  scanf("%d", &V);
  if (V == 0) return false;
  for (int u = 1, v, w; u < V; u++) {
    scanf("%d %d", &v, &w);
    G[u].push_back(v); W[u].push_back(w);
    G[v].push_back(u); W[v].push_back(w);
  }
  return true;
}

void clear () {
  fill(add, add + V + 10, 0);
  for (int i = 0; i < LG; i++) fill(jump[i], jump[i] + V + 10, -1);
  for (int i = 0; i < V; i++) G[i].clear(), W[i].clear();
}

int main () {
  memset(jump, -1, sizeof jump);
  while (readTree()) {
    dfs(0);
    buildLCA();
    processQueries();
    clear();
  }
  return (0);
}
