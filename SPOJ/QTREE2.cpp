/**
 * > Author : TISparta
 * > Date : 06-10-18
 * > Tags : LCA
 * > Difficulty : 4 / 10
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 1e4 + 10, LG = 15;

int V, H[MAX_V], dis[MAX_V], up[LG][MAX_V];
vector <vector <pair <int, int>>> G;

void dfs (int u, int p = -1) {
  for (int bit = 1; bit < LG; bit++) {
    int v = up[bit - 1][u];
    if (v == -1) break;
    up[bit][u] = up[bit - 1][v];
  }
  for (auto pp: G[u]) {
    int v = pp.first, w = pp.second;
    if (v == p) continue;
    H[v] = H[u] + 1;
    dis[v] = dis[u] + w;
    up[0][v] = u;
    dfs(v, u);
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
    if (up[bit][u] != up[bit][v])
      u = up[bit][u], v = up[bit][v];
  return up[0][u];
}

void processQueries () {
  char command[10];
  getchar();
  while (scanf("%s", command), strcmp(command, "DONE")) {
    if (command[0] == 'D') {
      int u, v;
      scanf("%d %d", &u, &v);
      int lca = getLCA(u, v);
      printf("%d\n", dis[u] + dis[v] - 2 * dis[lca]);
    }
    else {
      int u, v, k;
      scanf("%d %d %d", &u, &v, &k);
      int lca = getLCA(u, v);
      k--;
      if (k <= H[u] - H[lca]) printf("%d\n", walk(u, k));
      else printf("%d\n", walk(v, (H[v] - H[lca]) - (k - (H[u] - H[lca]))));
    }
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
  G.clear();
  memset(up, -1, sizeof up);
  memset(dis, 0, sizeof dis);
  G.resize(MAX_V);
}

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    clear();
    readTree();
    dfs(1);
    processQueries();
    puts("");
  }
  return (0);
}
