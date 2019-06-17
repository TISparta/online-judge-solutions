/**
 * > Author : TISparta
 * > Date : 17-06-19
 * > Tags : Binary Lifting
 * > Difficulty : 6 / 10
 */

#include <bits/stdc++.h>

#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, q;
    cin >> n >> q;
    vector <vector <int>> G(n + 1);
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    const int LG = 19;
    vector <int> depth(n + 1);
    vector <vector <int>> up(LG, vector <int> (n + 1, 0));
    vector <vector <ll>> acc(LG, vector <ll> (n + 1, 0LL));
    vector <int> size(n + 1, 0);
    vector <int> sum(n + 1, 0);
    vector <ll> sum_sq(n + 1, 0LL);
    function <void(int,int)> dfs_pre = [&] (int u, int p) -> void {
      size[u] = 1;
      for (int v: G[u]) {
        if (v == p) continue;
        dfs_pre(v, u);
        size[u] += size[v];
        sum[u] += size[v];
        sum_sq[u] += 1LL * size[v] * size[v];
      }
    };
    auto f = [] (ll s, ll s2) { return 1 + (s * s - s2 + 2 * s) / 2; };
    function <void(int,int)> dfs_build = [&] (int u, int p) -> void {
      for (int bit = 1; bit < LG; bit++) {
        int v = up[bit - 1][u];
        if (v == 0) break;
        up[bit][u] = up[bit - 1][v];
        acc[bit][u] = acc[bit - 1][u] + acc[bit - 1][v];
      }
      for (int v: G[u]) {
        if (p == v) continue;
        depth[v] = depth[u] + 1;
        up[0][v] = u;
        acc[0][v] = f(sum[u] - size[v], sum_sq[u] - 1LL * size[v] * size[v]);
        dfs_build(v, u);
      }
    };
    auto walk = [&] (int u, int k) {
      for (int bit = LG - 1; bit >= 0; bit--)
        if ((k >> bit) bitand 1) u = up[bit][u];
      return u;
    };
    auto get = [&] (int u, int v) -> ll {
      if (u == v) {
        ll add = n - size[u];
        return f(sum[u] + add, sum_sq[u] + add * add);
      }
      if (depth[u] < depth[v]) swap(u, v);
      int U = u;
      ll ans = f(sum[u], sum_sq[u]);
      int k = depth[u] - depth[v];
      for (int bit = LG - 1; bit >= 0; bit--) {
        if ((k >> bit) & 1) {
          ans += acc[bit][u];
          u = up[bit][u];
        }
      }
      if (u == v) {
        int r = walk(U, k - 1);
        ll add = n - size[v];
        ll s1 = sum[v] - size[r] + add;
        ll s2 = sum_sq[v] - 1LL * size[r] * size[r] + add * add;
        return ans - acc[0][r] + f(s1, s2);
      }
      ans += f(sum[v], sum_sq[v]);
      for (int bit = LG - 1; bit >= 0; bit--) {
        if (up[bit][u] != up[bit][v]) {
          ans += acc[bit][u] + acc[bit][v];
          u = up[bit][u], v = up[bit][v];
        }
      }
      int p = up[0][u];
      ll add = n - size[p];
      ll s1 = sum[p] - size[u] - size[v] + add;
      ll s2 = sum_sq[p] - 1LL * size[u] * size[u] - 1LL * size[v] * size[v] + add * add;
      return ans + f(s1, s2);
    };
    dfs_pre(1, 0);
    dfs_build(1, 0);
    while (q--) {
      int u, v;
      cin >> u >> v;
      cout << get(u, v) << '\n';
    }
  }
  return (0);
}
