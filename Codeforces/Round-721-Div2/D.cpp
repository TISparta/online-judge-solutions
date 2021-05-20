// Topics: LCA, IEP
// Difficulty: 5.2
// Priority: 4
// Date: 20-05-2021

#include <bits/stdc++.h>
     
#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define mp make_pair
     
using namespace std;
     
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <pii> vpii;
typedef vector <pll> vpll;

struct LCA {
  vector <vi> up;
  vi depth;
  const int LG = 18;

  LCA (const vector <vi>& g, int n, int root) {
    up = vector <vi> (n + 1, vi(LG, -1));
    depth = vi(n + 1);
    
    function <void(int,int)> dfs = [&] (int u, int p) -> void {
      depth[u] = (p == -1) ? 0 : depth[p] + 1;
      for (int bit = 1; bit < LG; bit++) {
        int v = up[u][bit - 1];
        if (v == -1) break;
        up[u][bit] = up[v][bit - 1];
      }
      for (auto v: g[u]) {
        if (v == p) continue;
        up[v][0] = u;
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
};

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector <vi> g(n);
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
    }
    vi ss(n, 0);
    vi par(n);
    function <void(int,int)> dfs_sz = [&] (int u, int p) -> void {
      ss[u] = 1;
      for (int v: g[u]) if (v != p) dfs_sz(v, u), ss[u] += ss[v], par[v] = u;
    };
    dfs_sz(0, -1);
    int x = 0, y = 1;
    set <int> st;
    int cur = 1;
    while (cur != 0) {
      st.emplace(cur);
      cur = par[cur];
    }
    st.emplace(0);
    vll ans(n + 1, 0);
    LCA lca(g, n, 0);
    auto solve = [&] (int x, int y) {
      if (lca.depth[x] > lca.depth[y]) swap(x, y);
      int p = lca.lca(x, y);
      if (p == x) {
        int d = lca.dis(x, y);
        int z = lca.walk(y, d - 1);
        return 1LL * ss[y] * (n - ss[z]);
      }
      return 1LL * ss[x] * ss[y];
    };
    ans[2] = solve(x, y);
    for (int i = 2; i < n; i++) {
      if (st.count(i) == 0) {
        int cur = i;
        while (st.count(cur) == 0) {
          st.emplace(cur);
          cur = par[cur];
        }
        if (not (cur == x or cur == y)) break;
        if (cur == x) x = i;
        else if (cur == y) y = i;
      }
      ans[i + 1] = solve(x, y);
    }
    for (int i = 2; i + 1 <= n; i++) ans[i] -= ans[i + 1];
    for (int u: g[0]) ans[0] += 1LL * ss[u] * (ss[u] - 1) / 2;
    ll total = 1LL * n * (n - 1) / 2;
    ans[1] = total - accumulate(all(ans), 0LL);
    for (int i = 0; i <= n; i++) cout << ans[i] << " \n"[i == n];
  }
  return (0);
}
