// Tags: Dijkstra, MST, LCA
// Difficulty: 7.5
// Priority: 1
// Date: 11-08-2021

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

struct LCA {
  vector <vpll> up;
  vi depth;
  const int LG = 18;

  LCA (const vector <vpll>& g, int n, int root) {
    up = vector <vpll> (n + 1, vpll(LG, mp(-1, -1)));
    depth = vi(n + 1);
    
    function <void(int,int)> dfs = [&] (int u, int p) -> void {
      depth[u] = (p == -1) ? 0 : depth[p] + 1;
      for (int bit = 1; bit < LG; bit++) {
        int v = up[u][bit - 1].first;
        if (v == -1) break;
        up[u][bit].first = up[v][bit - 1].first;
        up[u][bit].second = max(up[u][bit - 1].second, up[v][bit - 1].second);
      }
      for (auto [v, w]: g[u]) {
        if (v == p) continue;
        up[v][0] = mp(u, w);
        dfs(v, u);
      }
    };
    
    dfs(root, -1);
  }

  int walk (int u, int k) {
    for (int bit = 0; bit < LG and k; bit++) {
      if ((k >> bit) & 1) {
        u = up[u][bit].first;
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
      if (up[u][bit].first != up[v][bit].first) {
        u = up[u][bit].first;
        v = up[v][bit].first;
      }
    }
    return up[u][0].first;
  }
  
  int dis (int u, int v) {
    int p = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[p];
  }

  ll compute (int u, int k) {
    ll mx = 0;
    for (int bit = 0; bit < LG and k; bit++) {
      if ((k >> bit) & 1) {
        mx = max(mx, up[u][bit].second);
        u = up[u][bit].first;
        k -= (1 << bit);
      }
    }
    return mx;
  }

  ll query (int u, int v) {
    int p = lca(u, v);
    return max(compute(u, depth[u] - depth[p]),
               compute(v, depth[v] - depth[p]));
  }
};


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

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m, k, q;
  cin >> n >> m >> k >> q;
  vector <vpii> g(n + 1);
  vector <tuple <ll, int, int>> edge(m);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].eb(v, w);
    g[v].eb(u, w);
    edge[i] = mt(w, u, v);
  }
  set <pll> qq;
  const ll INF = 1e18;
  vll dis(n + 1, INF);
  for (int i = 1; i <= k; i++) {
    dis[i] = 0;
    qq.emplace(dis[i], i);
  }
  while (not empty(qq)) {
    auto [dis_u, u] = *begin(qq); qq.erase(begin(qq));
    for (auto [v, w]: g[u]) {
      if (dis[v] > dis_u + w) {
        qq.erase(mp(dis[v], v));
        dis[v] = dis_u + w;
        qq.emplace(mp(dis[v], v));
      }
    }
  }
  for (auto& [w, u, v]: edge) {
    w += dis[u] + dis[v];
  }
  sort(all(edge));
  DSU dsu(n + 1);
  vector <vpll> tree(n + 1);
  for (auto [w, u, v]: edge) {
    if (dsu.join(u, v)) {
      tree[u].eb(v, w);
      tree[v].eb(u, w);
    }
  }
  LCA lca(tree, n, 1);
  while (q--) {
    int u, v;
    cin >> u >> v;
    cout << lca.query(u, v) << '\n';
  }
  return (0);
}
