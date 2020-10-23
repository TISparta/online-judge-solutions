// Segment Tree
// 2
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
  vi st(4 * n);
  function <void(int,int,int)> build = [&] (int u, int l, int r) -> void {
    if (l == r) {
      st[u] = a[l];
      return;
    }
    int m = (l + r) >> 1;
    build(2 * u, l, m);
    build(2 * u + 1, m + 1, r);
    st[u] = min(st[2 * u], st[2 * u + 1]);
  };
  function <void(int,int,int,int,int)> update = [&] (int u, int l, int r, int pos, int val) -> void {
    if (not (l <= pos and pos <= r)) return;
    if (l == pos and pos == r) {
      st[u] = val;
      return;
    }
    int m = (l + r) >> 1;
    update(2 * u, l, m, pos, val);
    update(2 * u + 1, m + 1, r, pos, val);
    st[u] = min(st[2 * u], st[2 * u + 1]);
  };
  function <int(int,int,int,int,int)> mn = [&] (int u, int l, int r, int L, int R) -> int {
    if (r < L or R < l) return INT_MAX;
    if (L <= l and r <= R) return st[u];
    int m = (l + r) >> 1;
    return min(mn(2 * u, l, m, L, R), mn(2 * u + 1, m + 1, r, L, R));
  };
  build(1, 1, n);
  while (q--) {
    int t, l, r;
    cin >> t >> l >> r;
    if (t == 1) {
      update(1, 1, n, l, r);
    } else {
      cout << mn(1, 1, n, l, r) << '\n';
    }
  }
  return (0);
}
