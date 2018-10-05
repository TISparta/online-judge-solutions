#include <bits/stdc++.h>

#define pb(A) push_back(A)

using namespace std;

const int MAX_V = 5e3 + 10, LG = 15;

int V, H[MAX_V], ANC[LG][MAX_V];
vector <int> G[MAX_V];

void dfs (int u, int p = -1) {
  for (int v: G[u]) {
    if (v != p) {
      H[v] = H[u] + 1;
      ANC[0][v] = u;
      dfs(v, u);
    }
  }
}

void buildTable () {
  for (int bit = 1; bit < LG; bit++) {
    for (int u = 1; u <= V; u++) {
      int v = ANC[bit - 1][u];
      if (~v) ANC[bit][u] = ANC[bit - 1][v];
    }
  } 
}

int walk (int u, int k) {
  for (int bit = LG - 1; bit >= 0; bit--)
    if ((k >> bit) bitand 1) u = ANC[bit][u];
  return u;
}

int getLCA (int u, int v) {
  if (H[u] != H[v]) u = walk(u, H[u] - H[v]);
  if (u == v) return u;
  for (int bit = LG - 1; bit >= 0; bit--)
    if (~ANC[bit][u] and ANC[bit][u] != ANC[bit][v])
      u = ANC[bit][u], v = ANC[bit][v];
  return ANC[0][u];
} 

void processQueries () {
  int Q;
  scanf("%d", &Q);
  while (Q--) {
    int u, v;
    scanf("%d %d", &u, &v);
    if (H[u] < H[v]) swap(u, v);
    int lca = getLCA(u, v);
    int d = H[u] + H[v] - 2 * H[lca];
    if (d & 1) {
      int ans1 = walk(u, d / 2);
      int ans2 = ANC[0][ans1];
      if (ans1 > ans2) swap(ans1, ans2);
      printf("The fleas jump forever between %d and %d.\n", ans1, ans2);
    }
    else {
      printf("The fleas meet at %d.\n", walk(u, d / 2)); 
    }
  }
}

void readTree () {
  int u, v;
  for (int i = 1; i < V; i++) {
    scanf("%d %d", &u, &v);
    G[u].pb(v);
    G[v].pb(u);
  }
}

void clear () {
  for (int bit = 0; bit < LG; bit++) for (int v = 1; v <= V; v++) ANC[bit][v] = -1;
  for (int v = 1; v <= V; v++) G[v].clear();
}

int main () {
  while (scanf("%d", &V), V) {
    clear();
    readTree();
    dfs(1);
    buildTable();
    processQueries();
  }
  return (0);
}
