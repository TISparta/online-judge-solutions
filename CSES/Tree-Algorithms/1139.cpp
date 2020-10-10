// BIT, DFS
// 5
// 10-10-2020

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
  int n;
  cin >> n;
  vi a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector <vi> g(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  int t = 1;
  vi tin(n + 1);
  vi tout(n + 1);
  vi arr(n + 1);
  function <void(int,int)> dfs = [&] (int u, int p) -> void {
    arr[t] = u;
    tin[u] = t++;
    for (int v: g[u]) {
      if (v == p) continue;
      dfs(v, u);
    }
    tout[u] = t - 1;
  };
  dfs(1, -1);
  vi c = a;
  sort(all(c));
  c.erase(unique(all(c)), end(c));
  for (int i = 1; i <= n; i++) {
    a[i] = lower_bound(all(c), a[i]) - begin(c);
  }
  vector <vi> pos(n + 1);
  vi last(n + 1);
  vector <tuple <int, int, int>> query;
  for (int i = 1; i <= n; i++) {
    arr[i] = a[arr[i]];
    pos[arr[i]].pb(i);
    last[arr[i]] = -1;
    query.emplace_back(tin[i], tout[i], i);
  }
  BIT ft(n + 1);
  for (int i = 1; i <= n; i++) {
    if (pos[i].empty()) continue;
    ft.update(pos[i][0], 1);
    last[i] = 0;
  }
  sort(all(query));
  int cur = 1;
  vi ans(n + 1);
  for (auto [l, r, i]: query) {
    while (cur < l) {
      int j = last[arr[cur]];
      int p = pos[arr[cur]][j];
      ft.update(p, -1);
      last[arr[cur]] += 1;
      j += 1;
      if (j < sz(pos[arr[cur]])) {
        p = pos[arr[cur]][j];
        ft.update(p, 1);
      }
      cur += 1;
    }
    ans[i] = ft.sum(l, r);
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
  return (0);
}
