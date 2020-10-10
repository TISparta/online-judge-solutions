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
  int n, q;
  cin >> n >> q;
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
  function <void(int,int)> dfs = [&] (int u, int p) -> void {
    tin[u] = t++;
    for (int v: g[u]) {
      if (v == p) continue;
      dfs(v, u);
    }
    tout[u] = t++;
  };
  dfs(1, -1);
  BIT <ll> ft(t);
  for (int i = 1; i <= n; i++) {
    ft.update(tin[i], a[i]);
  }
  while (q--) {
    int tt;
    cin >> tt;
    if (tt == 1) {
      int u, x;
      cin >> u >> x;
      ft.update(tin[u], -a[u] + x);
      a[u] = x;
    } else {
      int u;
      cin >> u;
      cout << ft.sum(tin[u], tout[u]) << '\n';
    }
  }
  return (0);
}
