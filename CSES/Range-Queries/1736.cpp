// Segment Tree, Lazy Propagation
// 5
// 19-10-2020

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

struct STree {
  int from, to;
  struct State {
    ll sum;
    int a;
    int r;
  };
  vector <State> st;
  State NIL{0, 0, 0};

  void build (int u, int l, int r, const vi& arr) {
    if (l == r) {
      st[u].sum = arr[l];
      st[u].a = 0;
      return;
    }
    int m = (l + r) >> 1;
    int lu = u << 1;
    int ru = lu | 1;
    build(lu, l, m, arr);
    build(ru, m + 1, r, arr);
    st[u] = merge(st[lu], st[ru]);
  }

  STree (int l, int r, const vi& arr): from(l), to(r) {
    st.resize(4 * r);
    build(1, l, r, arr);
  }

  State merge (State lu, State ru) {
    State ret{lu.sum + ru.sum, 0};
    return ret;
  }

  void push (int u, int l, int r) {
    if (st[u].a == 0) return;
    ll len = r - l + 1;
    st[u].sum += st[u].a * len + st[u].r * len * (len - 1) / 2;
    if (l != r) {
      int lu = u << 1;
      int ru = lu | 1;
      st[lu].a += st[u].a;
      st[lu].r += st[u].r;
      st[ru].a += st[u].a + st[u].r * ((l + r) / 2 + 1 - l);
      st[ru].r += st[u].r;
    }
    st[u].a = 0;
    st[u].r = 0;
  }

  void update (int L, int R, int u, int l, int r) {
    push(u, l, r);
    if (r < L or R < l) return;
    if (L <= l and r <= R) {
      st[u].a = l - L + 1;
      st[u].r = 1;
      push(u, l, r);
      return;
    }
    int m = (l + r) >> 1;
    int lu = u << 1;
    int ru = lu | 1;
    update(L, R, lu, l, m);
    update(L, R, ru, m + 1, r);
    st[u] = merge(st[lu], st[ru]);
  }

  void update (int L, int R) { update(L, R, 1, from, to); }

  State query (int L, int R, int u, int l, int r) {
    push(u, l, r);
    if (r < L or R < l) return NIL;
    if (L <= l and r <= R) return st[u];
    int m = (l + r) >> 1;
    return merge(query(L, R, (u << 1), l, m), query(L, R, (u << 1) | 1, m + 1, r));
  }

  State query (int L, int R) { return query(L, R, 1, from, to); }

};

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, q;
  cin >> n >> q;
  vi a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  STree st(1, n, a);
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int l, r;
      cin >> l >> r;
      st.update(l, r);
    } else {
      int l, r;
      cin >> l >> r;
      cout << st.query(l, r).sum << '\n';
    }
  }
  return (0);
}
