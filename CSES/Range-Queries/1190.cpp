// Segment Tree
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
  int n, m;
  cin >> n >> m;
  vi a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  struct node { ll best, bleft, bright, total; };
  vector <node> st(4 * n);
  auto merge = [&] (const node& x, const node& y) {
    node ret;
    ret.total = x.total + y.total;
    ret.bleft = max(x.bleft, x.total + y.bleft);
    ret.bright = max(y.bright, x.bright + y.total);
    ret.best = max({ret.total, ret.bleft, ret.bright, x.best, y.best, x.bright + y.bleft});
    return ret;
  };
  function <void(int,int,int)> build = [&] (int u, int l, int r) -> void {
    if (l == r) {
      st[u].total = a[l];
      st[u].bleft = st[u].bright = max(0, a[l]);
      st[u].best = max({st[u].bleft, st[u].bright, st[u].total});
      return;
    }
    int m = (l + r) >> 1;
    build(2 * u, l, m);
    build(2 * u + 1, m + 1, r);
    st[u] = merge(st[2 * u], st[2 * u + 1]);
  };
  build(1, 1, n);
  function <void(int,int,int,int,int)> update = [&] (int u, int l, int r, int pos, int val) {
    if (not (l <= pos and pos <= r)) return;
    if (l == pos and pos == r) {
      st[u].total = val;
      st[u].bleft = st[u].bright = max(0, val);
      st[u].best = max({st[u].bleft, st[u].bright, st[u].total});
      return;
    }
    int m = (l + r) >> 1;
    update(2 * u, l, m, pos, val);
    update(2 * u + 1, m + 1, r, pos, val);
    st[u] = merge(st[2 * u], st[2 * u + 1]);
  };
  while (m--) {
    int pos, val;
    cin >> pos >> val;
    update(1, 1, n, pos, val);
    cout << st[1].best << '\n';
  }
  return (0);
}
