// Segment Tree, Lazy Propagation
// 4
// 21-09-2020

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
  vi a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  const ll INF = 1e18;
  vll st(4 * n);
  vll lazy1(4 * n, 0); // increase
  vll lazy2(4 * n, INF); // set
  function <void(int,int,int)> build = [&] (int u, int l, int r) -> void {
    if (l == r) {
      st[u] = a[l];
      return;
    }
    int m = (l + r) >> 1;
    build(2 * u, l, m);
    build(2 * u + 1, m + 1, r);
    st[u] = st[2 * u] + st[2 * u + 1];
  };
  auto push = [&] (int u, int l, int r) {
    if (lazy2[u] != INF) { // set
      st[u] = (r - l + 1) * lazy2[u];
      if (l != r) {
        lazy1[2 * u] = lazy1[2 * u + 1] = 0;
        lazy2[2 * u] = lazy2[2 * u + 1] = lazy2[u];
      }
      lazy2[u] = INF;
    }
    if (lazy1[u]) { // increase
      st[u] += (r - l + 1) * lazy1[u];
      if (l != r) {
        lazy1[2 * u] += lazy1[u];
        lazy1[2 * u + 1] += lazy1[u];
      }
      lazy1[u] = 0;
    }
  };
  function <void(int,int,int,int,int,int,int)> update = [&] (int u, int l, int r, int L, int R, int val, int t) -> void {
    push(u, l, r);
    if (r < L or R < l) return;
    if (L <= l and r <= R) {
      if (t == 1) lazy1[u] += val;
      if (t == 2) lazy2[u] = val;
      push(u, l, r);
      return;
    }
    int m = (l + r) >> 1;
    update(2 * u, l, m, L, R, val, t);
    update(2 * u + 1, m + 1, r, L, R, val, t);
    st[u] = st[2 * u] + st[2 * u + 1];
  };
  function <ll(int,int,int,int,int)> get = [&] (int u, int l, int r, int L, int R) -> ll {
    push(u, l, r);
    if (r < L or R < l) return 0;
    if (L <= l and r <= R) return st[u];
    int m = (l + r) >> 1;
    return get(2 * u, l, m, L, R) + get(2 * u + 1, m + 1, r, L, R);
  };
  build(1, 1, n);
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      update(1, 1, n, l, r, x, 1);
    }
    if (t == 2) {
      int l, r, x;
      cin >> l >> r >> x;
      update(1, 1, n, l, r, x, 2);
    }
    if (t == 3) {
      int l, r;
      cin >> l >> r;
      cout << get(1, 1, n, l, r) << '\n';
    }
  }
  return (0);
}
