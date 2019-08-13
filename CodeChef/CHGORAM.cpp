/**
 * > Author : TISparta
 * > Date : 03-08-19
 * > Tags : Segment Tree, Fenwick Tree, DFS
 * > Difficulty : 6 / 10
 */

#include <bits/stdc++.h>

#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

class STree {
private:
  int l, r;
  vector <vector <int>> st;

  void build (const vector <int>& arr, int node, int l, int r) {
    if (l == r) {
      st[node] = {arr[l]};
      return;
    }
    int m = (l + r) >> 1;
    int left = node << 1;
    int right = left | 1;
    build(arr, left, l, m);
    build(arr, right, m + 1, r);
    std::merge(all(st[left]), all(st[right]), back_inserter(st[node]));
  }

  int lt (int node, int l, int r, const int L, const int R, const int VAL) {
    if (r < L or R < l) return 0;
    if (L <= l and r <= R) {
      if (st[node].back() < VAL) return sz(st[node]);
      return upper_bound(all(st[node]), VAL) - begin(st[node]);
    }
    int m = (l + r) >> 1;
    return lt(2 * node, l, m, L, R, VAL) + lt(2 * node + 1, m + 1, r, L, R, VAL);
  }

public:

  STree () {}

  STree (vector <int>& arr, int l, int r): l(l), r(r) {
    st.assign(4 * r, vector <int> ());
    build(arr, 1, l, r);
  }

  int lt (int L, int R, int VAL) {
    return lt(1, l, r, L, R, VAL);
  }

};

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector <int> perm(3);
    for (int i = 0; i < 3; i++) cin >> perm[i];
    vector <vector <int>> G(n + 1);
    bool is_line = true;
    int root = 1;
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
      is_line &= (sz(G[i]) <= 2);
      if (sz(G[i]) == 1) root = i;
    }
    vector <int> ft(n + 10, 0);
    auto get = [&] (int pos) {
      int ret = 0;
      while (pos) {
        ret += ft[pos];
        pos -= pos & -pos;
      }
      return ret;
    };
    auto update = [&] (int pos, int val) {
      while (pos < sz(ft)) {
        ft[pos] += val;
        pos += pos & -pos;
      }
    };
    ll ans = 0LL;
    vector <pii> tour(n + 1);
    struct Node {
      ll sum_a = 0, sum_b = 0;
      ll sum2_a = 0, sum2_b = 0;
      ll prod = 0;
    };
    vector <int> arr;
    function <void(int, int)> dfs_build = [&] (int u, int p) {
      tour[u].first = sz(arr);
      arr.push_back(u);
      for (int v: G[u]) {
        if (v == p) continue;
        dfs_build(v, u);
      }
      tour[u].second = sz(arr) - 1;
    };
    dfs_build(root, -1);
    STree tree;
    if (not is_line) tree = STree(arr, 0, sz(arr) - 1);
    function <void(int, int)> dfs = [&] (int u, int p) {
      Node have;
      if (is_line) {
        ll total = get(n);
        ll lt = get(u - 1);
        ll gt = total - lt;
        have.sum_a += lt;
        have.sum2_a += lt * lt;
        have.sum_b += gt;
        have.sum2_b += gt * gt;
        have.prod += lt * gt;
      }
      for (int v: G[u]) {
        if (v == p) continue;
        if (is_line) update(u, 1);
        dfs(v, u);
        if (is_line) continue;
        int from = tour[v].first;
        int to = tour[v].second;
        int total = to - from + 1;
        ll lt = tree.lt(from, to, u);
        ll gt = total - lt;
        have.sum_a += lt;
        have.sum2_a += lt * lt;
        have.sum_b += gt;
        have.sum2_b += gt * gt;
        have.prod += lt * gt;
      }
      ll lt = u - 1;
      ll gt = n - (u + 1) + 1;
      lt -= have.sum_a;
      gt -= have.sum_b;
      have.sum_a += lt;
      have.sum2_a += lt * lt;
      have.sum_b += gt;
      have.sum2_b += gt * gt;
      have.prod += lt * gt;
      if (perm[1] == 1) {
        ans += (have.sum_b * have.sum_b - have.sum2_b) / 2;
      } else if (perm[1] == 3) {
        ans += (have.sum_a * have.sum_a - have.sum2_a) / 2;
      } else {
        ans += have.sum_a * have.sum_b - have.prod;
      }
    };
    dfs(root, -1);
    cout << ans << '\n';
  }
  return (0);
}
