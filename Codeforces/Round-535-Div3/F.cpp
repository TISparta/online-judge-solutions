// Tags: MST, Binary Lifting
// Difficulty: 5.3
// Priority: 1
// Date: 20-08-2021

#include <bits/stdc++.h>
     
#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple

using namespace std;
     
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <pii> vpii;
typedef vector <pll> vpll;

struct DSU {
  vi root;
  vi ss;
  int n_sets;

  DSU (int n): n_sets(n) {
    root.resize(n);
    iota(all(root), 0);
    ss = vi(n, 1);
  }

  int get (int u) {
    return root[u] = (u == root[u]) ? u : get(root[u]);
  }

  int join (int u, int v) {
    u = get(u);
    v = get(v);
    if (u == v) return 0;
    if (ss[u] < ss[v]) swap(u, v);
    root[v] = u;
    ss[u] += ss[v];
    n_sets -= 1;
    return 1;
  }
};

struct LCA {
  vector <vi> up;
  vector <vi> heavy;
  vi depth;
  const int LG = 18;

  LCA (const vector <vpii>& g, int n, int root) {
    up = vector <vi> (n + 1, vi(LG, -1));
    heavy = vector <vi> (n + 1, vi(LG, -1));
    depth = vi(n + 1);
    
    function <void(int,int)> dfs = [&] (int u, int p) -> void {
      depth[u] = (p == -1) ? 0 : depth[p] + 1;
      for (int bit = 1; bit < LG; bit++) {
        int v = up[u][bit - 1];
        if (v == -1) break;
        up[u][bit] = up[v][bit - 1];
        heavy[u][bit] = max(heavy[u][bit - 1], heavy[v][bit - 1]);
      }
      for (auto [v, w]: g[u]) {
        if (v == p) continue;
        up[v][0] = u;
        heavy[v][0] = w;
        dfs(v, u);
      }
    };
    
    dfs(root, -1);
  }

  int walk (int u, int k) {
    for (int bit = 0; bit < LG and k; bit++) {
      if ((k >> bit) & 1) {
        u = up[u][bit];
        k -= (1 << bit);
      }
    }
    return u;
  }
  
  int lca (int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    u = walk(u, depth[u] - depth[v]);
    if (u == v) return u;
    for (int bit = LG - 1; bit >= 0; bit--) {
      if (up[u][bit] != up[v][bit]) {
        u = up[u][bit];
        v = up[v][bit];
      }
    }
    return up[u][0];
  }
  
  int dis (int u, int v) {
    int p = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[p];
  }

  int get (int u, int k) {
    int ret = 0;
    for (int bit = 0; bit < LG and k; bit++) {
      if ((k >> bit) & 1) {
        ret = max(ret, heavy[u][bit]);
        u = up[u][bit];
        k -= (1 << bit);
      }
    }
    return ret;
  }

  int heaviest (int u, int v) {
    int p = lca(u, v);
    return max(get(u, depth[u] - depth[p]),
               get(v, depth[v] - depth[p]));
  }
};



int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector <tuple <int, int, int, int>> edge(m);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edge[i] = mt(w, u, v, 0);
  }
  sort(all(edge));
  DSU dsu(n + 1);
  vector <vpii> g(n + 1);
  for (auto& [w, u, v, vis]: edge) {
    if (dsu.join(u, v)) {
      vis = 1;
      g[u].eb(v, w);
      g[v].eb(u, w);
    }
  }
  LCA lca(g, n, 1);
  int ans = 0;
  for (auto [w, u, v, vis]: edge) {
    if (vis) continue;
    if (lca.heaviest(u, v) == w) ans += 1;
  }
  cout << ans << '\n';
  return (0);
}
