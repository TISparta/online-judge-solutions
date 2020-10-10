// Binary Lifting
// 5
// 09-10-2020

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

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector <vi> g(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  const int LG = 18;
  vector <vi> up(n + 1, vi(LG, -1));
  vi level(n + 1);
  vi leaf;
  function <void(int,int,int)> dfs = [&] (int u, int p, int h) -> void {
    level[u] = h;
    for (int bit = 1; bit < LG; bit++) {
      int v = up[u][bit - 1];
      // 2^bit = 2^(bit - 1) -> 2^(bit - 1)
      if (v == -1) break;
      up[u][bit] = up[v][bit - 1];
    }
    bool is_leaf = true;
    for (int v: g[u]) {
      if (v == p) continue;
      up[v][0] = u;
      dfs(v, u, h + 1);
      is_leaf = false;
    }
    if (is_leaf) leaf.pb(u);
  };
  dfs(1, -1, 0);
  auto walk = [&] (int u, int k) {
    for (int bit = 0; bit < LG and u != -1; bit++) {
      if ((k >> bit) & 1) {
        u = up[u][bit];
      }
    }
    return u;
  };
  auto lca = [&] (int u, int v) {
    if (level[u] > level[v]) swap(u, v);
    v = walk(v, level[v] - level[u]);
    if (u == v) return u;
    for (int bit = LG - 1; bit >= 0; bit--) {
      if (up[u][bit] != up[v][bit]) {
        u = up[u][bit];
        v = up[v][bit];
      }
    }
    return up[u][0];
  };
  vi acc(n + 1, 0);
  up[1][0] = 0;
  while (q--) {
    int u, v;
    cin >> u >> v;
    int p = lca(u, v);
    acc[u] += 1;
    acc[v] += 1;
    acc[p] -= 2;
    acc[p] += 1;
    acc[up[p][0]] -= 1;
  }
  function <void(int,int)> dfs2 = [&] (int u, int p) -> void {
    for (int v: g[u]) {
      if (v == p) continue;
      dfs2(v, u);
      acc[u] += acc[v];
    }
  };
  dfs2(1, -1);
  for (int i = 1; i <= n; i++) {
    cout << acc[i] << " \n"[i == n];
  }
  return (0);
}
