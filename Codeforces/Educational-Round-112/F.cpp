// Tags: DSU, BIT, LCA
// Difficulty: 7.5
// Priority: 1
// Date: 11-08-2021

#include <bits/stdc++.h>
     
#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define mp make_pair
     
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
  vi tin;
  vi tout;
  vi depth;
  vi path_xor;
  int timer;
  const int LG = 18;

  LCA (const vector <vpii>& g, int n) {
    up = vector <vi> (n + 1, vi(LG, -1));
    tin = vi (n + 1, -1);
    tout = vi (n + 1, -1);
    depth = vi(n + 1);
    path_xor = vi(n + 1, 0);
    timer = 1;

    function <void(int,int)> dfs = [&] (int u, int p) -> void {
      depth[u] = (p == -1) ? 0 : depth[p] + 1;
      tin[u] = timer++;
      for (int bit = 1; bit < LG; bit++) {
        int v = up[u][bit - 1];
        if (v == -1) break;
        up[u][bit] = up[v][bit - 1];
      }
      for (auto [v, w]: g[u]) {
        if (v == p) continue;
        up[v][0] = u;
        path_xor[v] = path_xor[u] ^ w;
        dfs(v, u);
      }
      tout[u] = timer;
    };
    
    for (int u = 1; u <= n; u++) if (tin[u] == -1) dfs(u, -1);
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
};

template <typename T = int>
struct BIT {
  vector <T> ft;
  BIT (int n): ft(n + 2, 0) {}
  void update (int pos, T val) {
    while (pos < sz(ft)) {
      ft[pos] += val;
      pos += pos & -pos;
    }
  }
  void update (int l, int r, T val) {
    if (l > r) return;
    update(l, val);
    update(r + 1, -val);
  }
  T sum (int pos) {
    T ret = 0;
    while (pos) {
      ret += ft[pos];
      pos -= pos & -pos;
    }
    return ret;
  }
  T sum (int l, int r) {
    if (l > r) return 0;
    return sum(r) - sum(l - 1);
  }
};

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, q;
  cin >> n >> q;
  DSU dsu(n + 1);
  vector <tuple <int, int, int>> query(q);
  vector <vpii> g(n + 1);
  vi ans(q, -1);
  for (int i = 0; i < q; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    query[i] = mt(u, v, w);
    if (dsu.join(u, v)) {
      // tree-edge
      ans[i] = 1;
      g[u].eb(v, w);
      g[v].eb(u, w);
    }
  }
  LCA lca(g, n);
  BIT ft(lca.timer + 1);
  // mark edges of path p --> u
  auto walk = [&] (int u, int p) {
    while (u != p) {
      ft.update(lca.tin[u], lca.tout[u] - 1, 1);
      u = lca.up[u][0];
    }
  };
  for (int i = 0; i < q; i++) {
    if (ans[i] != -1) continue;
    ans[i] = 0;
    auto [u, v, w] = query[i]; 
    // valid cycle xor
    int cycle_xor = lca.path_xor[u] ^ lca.path_xor[v] ^ w;
    if (cycle_xor != 1) continue;
    // edges of cycles not used
    int p = lca.lca(u, v);
    int sum = ft.sum(lca.tin[u]) + ft.sum(lca.tin[v]) - 2 * ft.sum(lca.tin[p]);
    if (sum != 0) continue;
    walk(u, p);
    walk(v, p);
    ans[i] = 1;
  }
  for (int i = 0; i < q; i++) {
    if (ans[i]) cout << "YES\n";
    else cout << "NO\n";
  }
  return (0);
}
